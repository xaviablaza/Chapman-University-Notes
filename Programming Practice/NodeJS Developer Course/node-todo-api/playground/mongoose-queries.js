const {ObjectID}= require('mongodb');

const {mongoose} = require('./../server/db/mongoose');
const {Todo} = require('./../server/models/todo');
const {User} = require('./../server/models/user');

// var id = '58788e893348b209c47dabb711';

// if (!ObjectID.isValid(id)) {
// 	console.log('ID not valid');
// }

// Todo.find({
// 	_id: id
// }).then((todos) => {
// 	console.log('Todos', todos);
// });
// // [] if not found

// Todo.findOne({
// 	_id: id
// }).then((todos) => {
// 	console.log('Todos', todos);
// });
// // null if not found

// Todo.findById(id).then((todo) => {
// 	if (!todo) {
// 		return console.log('Id not found');
// 	}
// 	console.log('Todos by Id', todo);
// }).catch((e) => console.log(e))
// // null if not found

var userId = '587735105d376d0768266892'
User.findById(userId).then((user) => {
	if (!user) {
		return console.log('User not found');
	}
	console.log('User by Id');
	console.log(JSON.stringify(user, undefined, 2));
}).catch((e) => console.log(e));