const expect = require('expect');

const utils = require('./utils');

describe('Utils', () => {

	describe('#add', () => {
		it('should add two numbers', () => {
			var res = utils.add(33, 11);
			expect(res).toBe(44).toBeA('number');
		});
	});

	// asynchronous test
	it('should async add two numbers', (done) => {
		utils.asyncAdd(4, 3, (sum) => {
			expect(sum).toBe(7).toBeA('number');
			done();
		});
	});

	it('should async square a number', (done) => {
		utils.asyncSquare(5, (res) => {
			expect(res).toBe(25).toBeA('number');
			done();
		});
	});

	it('should square a number', () => {
		var res = utils.square(11);
		expect(res).toBe(121).toBeA('number');
	});
});

it('should set firstName and lastName', () => {
	var user = {
		age: 19,
		location: 'Manila'
	};
	var res = utils.setName(user, 'Xavi Ablaza');
	expect(res.firstName).toBeA('string').toBe('Xavi');
	expect(res.lastName).toBeA('string').toBe('Ablaza');
	expect(res).toInclude({
		firstName: 'Xavi',
		lastName: 'Ablaza'
	})

	// // expect(12).toNotBe(11);
	// // expect({name: 'Xavi'}).toEqual({name: 'Xavi'});
	// // expect([2, 3, 4]).toExclude(1);
	// expect({
	// 	name: 'Xavi',
	// 	age: 19,
	// 	location: 'Manila'
	// }).toExclude({
	// 	age: 120
	// })
});