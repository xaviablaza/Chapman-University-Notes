const express = require('express');

var app = express();

app.get('/', (req, res) => {
	res.status(404).send({
		error: 'Page not found.',
		name: 'Todo App v1.0'
	});
});

// GET /users
app.get('/users', (req, res) => {
	res.status(200).send([
		{name: 'Xavi', age: 19},
		{name: 'Chris', age: 22},
		{name: 'Johnny', age: 14}
	]);
});
// Give users a name property and age property (2 or 3 users)

app.listen(3000);
module.exports.app = app;