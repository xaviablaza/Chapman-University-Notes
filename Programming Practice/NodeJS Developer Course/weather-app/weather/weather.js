const request = require('request');

var getWeather = (lat, lng, callback) => {
	request({
		url: `https://api.darksky.net/forecast/64a1fe369c6e330cd2e8444416873b7b/${lat},${lng}?units=si`,
		json: true
	}, (error, response, body) => {
		if (!error && response.statusCode === 200) {
			callback(undefined, {
				temperature: body.currently.temperature,
				apparentTemperature: body.currently.apparentTemperature
			});
		} else {
			callback('Unable to fetch weather.');
		}
	});
};

module.exports.getWeather = getWeather;