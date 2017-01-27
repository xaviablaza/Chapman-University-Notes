var square = x => x * x;
console.log(square(9));

var user = {
	name: 'Xavi',
	// Use arrow functions when you don't need access to arguments or this
	sayHi: () => {
		console.log(arguments);
		console.log(`Hi. I'm ${this.name}`);
	},
	// Use regular functions when you need access to arguments or this keyword
	sayHiAlt () {
		console.log(arguments);
		console.log(`Hi. I'm ${this.name}`);
	}
};

user.sayHi(1, 2, 3);