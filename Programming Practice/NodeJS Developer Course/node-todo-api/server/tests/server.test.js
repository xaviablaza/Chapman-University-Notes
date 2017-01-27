const expect = require('expect');
const request = require('supertest');
const {ObjectID} = require('mongodb');

const {app} = require('./../server');
const {Todo} = require('./../models/todo');
const {User} = require('./../models/user');
const {todos, populateTodos, users, populateUsers} = require('./seed/seed');

// Seed the database
beforeEach(populateUsers);
beforeEach(populateTodos);

describe('POST /todos', () => {
	it('should create a new todo', (done) => {
		var text = 'Test todo text';

		// POST request to app
		request(app)
			.post('/todos')
			.set('x-auth', users[0].tokens[0].token)
			.send({text})
			.expect(200)
			.expect((res) => {
				expect(res.body.text).toBe(text);
			})
			.end((err, res) => {
				if (err) {
					return done(err);
				}

				// Check Todo collection (make assumption about the database)
				Todo.find({text}).then((todos) => {
					expect(todos.length).toBe(1);
					expect(todos[0].text).toBe(text);
					done();
				}).catch((e) => done(e));
			});
	});

	it('should not create todo with invalid body data', (done) => {
		request(app)
		  .post('/todos')
			.set('x-auth', users[0].tokens[0].token)
		  .send({})
		  .expect(400)
		  .end((err, res) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	Todo.find().then((todos) => {
		  		expect(todos.length).toBe(2);
		  		done();
		  	}).catch((e) => done(e));
		  });
	});

});

describe('GET /todos', () => {
	it('should get all todos', (done) => {
		// ### MAKE NEW HTTP REQUEST ###
		request(app)
		  .get('/todos')
			.set('x-auth', users[0].tokens[0].token)
		  .expect(200)
		  .expect((res) => {
		  	expect(res.body.todos.length).toBe(1);
		  })
		  .end(done);
	})
});

describe('GET /todos/:id', () => {
	it('should return todo doc', (done) => {
		request(app)
		  .get(`/todos/${todos[0]._id.toHexString()}`)
			.set('x-auth', users[0].tokens[0].token)
		  .expect(200)
		  .expect((res) => {
		  	expect(res.body.todo.text).toBe(todos[0].text);
		  })
		  .end(done);
	});

	it('should not return todo doc created by other user', (done) => {
		request(app)
		  .get(`/todos/${todos[1]._id.toHexString()}`)
			.set('x-auth', users[0].tokens[0].token)
		  .expect(404)
		  .end(done);
	});

	it('should return 404 if todo not found', (done) => {
		request(app)
		  .get(`/todos/${new ObjectID().toHexString()}`)
			.set('x-auth', users[0].tokens[0].token)
		  .expect(404)
		  .end(done);
	});

	it('should return 404 for non-object ids', (done) => {
		request(app)
		  .get('/todos/123')
			.set('x-auth', users[0].tokens[0].token)
		  .expect(404)
		  .end(done);
	});
});

describe('DELETE /todos/:id', () => {
	it('should remove a todo', (done) => {
		var hexId = todos[1]._id.toHexString();

		request(app)
		  .delete(`/todos/${hexId}`)
			.set('x-auth', users[1].tokens[0].token)
		  .expect(200)
		  .expect((res) => {
		  	expect(res.body.todo._id).toBe(hexId);
		  })
		  .end((err, res) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	// query database using findById using toNotExist
		  	Todo.findById(hexId).then((todo) => {
		  		expect(todo).toNotExist();
		  		done();
		  	}).catch((e) => done(e));
		  });
	});

	it('should not remove a todo created by another user', (done) => {
		var hexId = todos[0]._id.toHexString();

		request(app)
		  .delete(`/todos/${hexId}`)
			.set('x-auth', users[1].tokens[0].token)
		  .expect(404)
		  .end((err, res) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	// query database using findById using toNotExist
		  	Todo.findById(hexId).then((todo) => {
		  		expect(todo).toExist();
		  		done();
		  	}).catch((e) => done(e));
		  });
	});

	it('should return 404 if todo not found', (done) => {
		request(app)
		  .delete(`/todos/${new ObjectID().toHexString()}`)
			.set('x-auth', users[1].tokens[0].token)
		  .expect(404)
		  .end(done);
	});

	it('should return 404 if object id is invalid', (done) => {
		request(app)
		  .delete('/todos/123')
			.set('x-auth', users[1].tokens[0].token)
		  .expect(404)
		  .end(done);
	});
});

describe('PATCH /todos/:id', () => {
	it('should update the todo', (done) => {
		var hexId = todos[0]._id.toHexString();

		var text = 'something updated';

		request(app)
			.patch(`/todos/${hexId}`)
			.set('x-auth', users[0].tokens[0].token)
			.send({
				completed: true,
				text
			})
			.expect(200)
			.expect((res) => {
				expect(res.body.todo.text).toBe(text);
				expect(res.body.todo.completed).toBe(true);
				expect(res.body.todo.completedAt).toBeA('number');
			})
			.end(done);
	});

	it('should not update the todo created by another user', (done) => {
		var hexId = todos[0]._id.toHexString();

		var text = 'something updated';

		request(app)
			.patch(`/todos/${hexId}`)
			.set('x-auth', users[1].tokens[0].token)
			.send({
				completed: true,
				text
			})
			.expect(404)
			.end(done);
	});

	it('should clear completedAt when todo is not completed', (done) => {
		var hexId = todos[1]._id.toHexString();

		var text = 'something updated';

		request(app)
			.patch(`/todos/${hexId}`)
			.set('x-auth', users[1].tokens[0].token)
			.send({
				completed: false,
				text
			})
			.expect(200)
			.expect((res) => {
				expect(res.body.todo.text).toBe(text);
				expect(res.body.todo.completed).toBe(false);
				expect(res.body.todo.completedAt).toNotExist();
			})
			.end(done);
	});
});

describe('GET /users/me', () => {
	it('should return user if authenticated', (done) => {
		request(app)
		  .get('/users/me')
		  .set('x-auth', users[0].tokens[0].token)
		  .expect(200)
		  .expect((res) => {
		  	expect(res.body._id).toBe(users[0]._id.toHexString());
		  	expect(res.body.email).toBe(users[0].email);
		  })
		  .end(done);
	});

	it('should return 401 if not authenticated', (done) => {
		request(app)
		  .get('/users/me')
		  .expect(401)
		  .expect((res) => {
		  	expect(res.body).toEqual({});
		  })
		  .end(done);
	});
});

describe('POST /users', () => {
	it('should create a user', (done) => {
		var email = 'example@example.com';
		var password = '123amdn!';

		request(app)
		  .post('/users')
		  .send({email, password})
		  .expect(200)
		  .expect((res) => {
		  	expect(res.headers['x-auth']).toExist();
		  	expect(res.body._id).toExist();
		  	expect(res.body.email).toBe(email);
		  })
		  .end((err) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	User.findOne({email}).then((user) => {
		  		expect(user).toExist();
		  		expect(user.password).toNotBe(password);
		  		done();
		  	}).catch((e) => done(e));
		  });
	});

	it('should return validation errors if request invalid', (done) => {
		//send across invalid email and invalid password
		var email = 'example@';
		var password = '3';

		request(app)
		  .post('/users')
		  .send({email, password})
		  .expect(400)
		  .expect((res) => {
		  	expect(res.body.errors).toExist();
		  })
		  .end((err) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	User.findOne({email}).then((user) => {
		  		expect(user).toNotExist();
		  		done();
		  	});
		  });
	});

	it('should not create user if email in use', (done) => {
		// send across an email that is already in the database
		var email = users[0].email;
		var password = users[0].password;

		request(app)
		  .post('/users')
		  .send({email, password})
		  .expect(400)
		  .expect((res) => {
		  	expect(res.body.code).toBe(11000);
		  })
		  .end(done);
	});
});

describe('POST /users/login', () => {
	it('should login user and return auth token', (done) => {
		request(app)
		  .post('/users/login')
		  .send({
		  	email: users[1].email,
		  	password: users[1].password
		  })
		  .expect(200)
		  .expect((res) => {
		  	expect(res.headers['x-auth']).toExist();
		  }).end((err, res) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	User.findById(users[1]._id).then((user) => {
		  		expect(user.tokens[1]).toInclude({
		  			access: 'auth',
		  			token: res.headers['x-auth']
		  		});
		  		done();
		  	}).catch((e) => done(e));
		});
	});

	it('should reject invalid login', (done) => {
		request(app)
		  .post('/users/login')
		  .send({
		  	email: users[1].email,
		  	password: 'some_invalid_password'
		  })
		  .expect(400)
		  .expect((res) => {
		  	expect(res.headers['x-auth']).toNotExist();
		  }).end((err, res) => {
		  	if (err) {
		  		return done(err);
		  	}

		  	User.findById(users[1]._id).then((user) => {
		  		expect(user.tokens.length).toBe(1);
		  		done();
		  	}).catch((e) => done(e));
		});
	});
});

describe('DELETE /users/me/token', () => {
	it('should remove auth token on logout', (done) => {
		// DELETE request to /users/me/token
		request(app)
		  .delete('/users/me/token')
		  // Set x-auth equal to token
		  .set('x-auth', users[0].tokens[0].token)
		  // Expect status 200
		  .expect(200)
		  // Async end call
		  .end((err, res) => {
		  		// If there's an error then print it
		  		if (err) {
		  			return done(err);
		  		}

		  		// Find the user, verify that tokens array has length of zero
		  		User.findById(users[0]._id).then((user) => {
		  			expect(user.tokens.length).toBe(0);
		  			done();
		  		}).catch((e) => done(e));
		  });
	});
})
