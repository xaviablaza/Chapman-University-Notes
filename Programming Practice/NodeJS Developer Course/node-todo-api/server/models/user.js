const mongoose = require('mongoose');
const validator = require('validator');
const jwt = require('jsonwebtoken');
const _ = require('lodash');
const bcrypt = require('bcryptjs');

var UserSchema = new mongoose.Schema({
	email: {
		type: String,
		required: true,
		trim: true,
		minlength: 1,
		unique: true,
		validate: {
			validator: validator.isEmail,
			message: '{VALUE} is not a valid email'
		},
		lowercase: true
	},
	password: {
		type: String,
		required: true,
		minlength: 6
	},
	tokens: [{
		access: {
			type: String,
			required: true
		},
		token: {
			type: String,
			required: true
		}
	}]
});

// Overridden method
UserSchema.methods.toJSON = function () {
	var user = this;
	var userObject = user.toObject();
	return _.pick(userObject, ['_id', 'email']);
};

UserSchema.methods.generateAuthToken = function () {
	var user = this;
	var access = 'auth';
	var token = jwt.sign({_id: user._id.toHexString(), access}, 'abc123');

	user.tokens.push({access, token});

	// user.save() here is used to save updates to the user
	return user.save().then(() => {
		return token;
	});
};

UserSchema.methods.removeToken = function (token) {
	var user = this;

	// Pull the token object from the arg
	return user.update({
		$pull: {
			tokens: {token}
		}
	});
};

UserSchema.statics.findByToken = function (token) {
	var User = this;
	var decoded;

	try {
		decoded = jwt.verify(token, 'abc123');
	} catch (e) {
		// return a promise that will always reject
		return Promise.reject();
	}

	return User.findOne({
		'_id': decoded._id,
		'tokens.token': token,
		'tokens.access': 'auth'
	});
};

// This was hard. Practice using Promises.
UserSchema.statics.findByCredentials = function (email, password) {
	var User = this;

	// Find a user within the database
	return User.findOne({email}).then((user) => {
		// If there is no user then reject
		if (!user) {
			return Promise.reject();
		}

		// Return a new Promise
		return new Promise((resolve, reject) => {
			// Use bcrypt.compare to compare password (plaintext) and user.password (hashed; from database)
			bcrypt.compare(password, user.password, (err, res) => {
				// If passwords don't match then reject
				if (!res) {
					reject();
				} else {
					// If passwords match then resolve with the user object
					resolve(user);
				}
			});
		});
	});
};

// Mongoose middleware
UserSchema.pre('save', function (next) {
	var user = this;

	if (user.isModified('password')) {
		bcrypt.genSalt(10, (err, salt) => {
			bcrypt.hash(user.password, salt, (err, hash) => {
				user.password = hash;
				next();
			});
		});
	} else {
		next();
	}
});

var User = mongoose.model('User', UserSchema);

module.exports = {User};