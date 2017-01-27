const fs = require('fs');

// Gets the notes array
var fetchNotes = () => {
	// Load in the file
	try {
		// Read data from file
		var notesString = fs.readFileSync('notes-data.json');
		// Convert data into array
		return JSON.parse(notesString);
	} catch (e) {
		return [];
	}
};

var saveNotes = (notes) => {
	// Turn array into json string and write to file
	fs.writeFileSync('notes-data.json', JSON.stringify(notes));
};

var addNote = (title, body) => {
	var notes = fetchNotes();
	var note = {
		title,
		body
	};

	// Keep each note in the array by returning true
	var duplicateNotes = notes.filter((note) => note.title === title);

	if (duplicateNotes.length === 0) {
		// Push note object to array
		notes.push(note);
		saveNotes(notes);
		return note;
	}
};

var getAll = () => {
	return fetchNotes();
};

var getNote = (title) => {
	var notes = fetchNotes();
	var filteredNotes = notes.filter((note) => note.title === title);
	return filteredNotes[0];
};

var removeNote = (title) => {
	// fetch notes
	var notes = fetchNotes();
	// filter notes, removing the one with title of argument
	var filteredNotes = notes.filter((note) => note.title !== title);
	// save new notes array
	saveNotes(filteredNotes);
	// returns true if note was removed
	return notes.length !== filteredNotes.length;
};

var logNote = (note) => {
	console.log('--');
	console.log(`Title: ${note.title}`);
	console.log(`Body: ${note.body}`);	
};

module.exports = {
	addNote,
	getAll,
	getNote,
	removeNote,
	logNote
};