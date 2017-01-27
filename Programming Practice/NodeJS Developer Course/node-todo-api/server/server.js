require('./config/config');

const _ = require('lodash');
const express = require('express');
const bodyParser = require('body-parser');
const {ObjectID} = require('mongodb');
const {bcrypt} = require('bcryptjs');

// ES6 restructuring
var {mongoose} = require('./db/mongoose');
var {Todo} = require('./models/todo');
var {User} = require('./models/user');
var {authenticate} = require('./middleware/authenticate');

var app = express();
const port = process.env.PORT;

// Middleware
app.use(bodyParser.json());

app.post('/todos', authenticate, (req, res) => {
	// Make new todo
	var todo = new Todo({
		text: req.body.text,
		_creator: req.user._id
	});

	todo.save().then((doc) => {
		res.send(doc);
	}, (e) => {
		res.status(400).send(e);
	});
});

app.get('/todos', authenticate, (req, res) => {
	Todo.find({
		// Return todos that were only created by the user
		_creator: req.user._id
	}).then((todos) => {
		res.send({todos})
	}, (e) => {
		res.status(400).send(e);
	});
});

// GET /todos/12341234
app.get('/todos/:id', (req, res) => {
	var id = req.params.id;
	// res.send(req.params);

	// Valid id using isValid
	  // 404 - send back empty send
	if (!ObjectID.isValid(id)) {
		res.status(404).send();
	}

  	// findById
  	Todo.findById(id).then((todo) => {
  		if (!todo) {
  			return res.status(404).send();
  		}
  		res.send({todo});
  	}).catch((e) => {
  		res.status(400).send();
  	});
});

app.delete('/todos/:id', (req, res) => {
	// get the id
	var id = req.params.id;

	// validate the id-> not valid? return 404
	if (!ObjectID.isValid(id)) {
		return res.status(404).send();
	}

	Todo.findByIdAndRemove(id).then((todo) => {
		if (!todo) {
			return res.status(404).send();
		}
		res.send({todo});
	}).catch((e) => {
		res.status(400).send();
	});
});

app.patch('/todos/:id', (req, res) => {
	var id = req.params.id;
	// Subset of things that the user sent to us (we don't want them to enter a completedAt field)
	var body = _.pick(req.body, ['text', 'completed']);

	if (!ObjectID.isValid(id)) {
		return res.status(404).send();
	}

	// Update the completedAt property
	if (_.isBoolean(body.completed) && body.completed) {
		body.completedAt = new Date().getTime();
	} else {
		body.completed = false;
		body.completedAt = null;
	}

	// Update the body to the database
	Todo.findByIdAndUpdate(id, {$set: body}, {new: true}).then((todo) => {
		if (!todo) {
			return res.status(404).send();
		}

		res.send({todo});
	}).catch((e) => {
		res.status(400).send();
	})
});

// POST /users
app.post('/users', (req, res) => {
	var body = _.pick(req.body, ['email', 'password']);
	var user = new User(body);

	// user.save() here is used to create the user
	user.save().then(() => {
		return user.generateAuthToken();
	}).then((token) => {
		// Custom header
		res.header('x-auth', token).send(user);
	}).catch((e) => {
		res.status(400).send(e);
	})
});

app.get('/users/me', authenticate, (req, res) => {
	res.send(req.user);
});

// POST /users/login {email, password}
app.post('/users/login', (req, res) => {
	var body = _.pick(req.body, ['email', 'password']);

	// Verify if user exists in the database
	User.findByCredentials(body.email, body.password).then((user) => {
		// Create a new auth token
		// return is used so that the catch block will be invoked
		return user.generateAuthToken().then((token) => {
			// Send the token through the header
			res.header('x-auth', token).send(user);
		});
	}).catch((e) => {
		res.status(400).send();
	});
});

app.delete('/users/me/token', authenticate, (req, res) => {
	req.user.removeToken(req.token).then(() => {
		res.status(200).send();
	}, () => {
		res.status(400).send();
	});
});

app.listen(3000, () => {
	console.log('Started on port 3000');
});

module.exports = {app};
