#include "InputHandler.h"
InputHandler::InputHandler() {
	studAmt = 0;
}
InputHandler::~InputHandler() {
	delete registrar;
}

void InputHandler::openFile(string iFilePath) {
	f.open(iFilePath.c_str());
}

void InputHandler::parseFile() {
	// Declare string to analyze
	string line;

	// First line is the number of windows open
	getline(f, line);
	int totWindows = atoi(line.c_str());
	GenQueue<Arrival> *genQueue = new GenQueue<Arrival>();

	while (getline(f, line)) {
		// Second line is a clock tick
		int clockTick = atoi(line.c_str());

		// Third line is how many students arrive
		getline(f, line);
		int numStuds = atoi(line.c_str());

		// Following lines are how many minutes a student needs at the window
		Student *studArray;
		studArray = new Student[numStuds];
		for (int i=0; i<numStuds; ++i) {
			getline(f, line);
			int minsNeeded = atoi(line.c_str());
			studArray[i] = Student(minsNeeded);
			studAmt++;
		}

		// Create Arrival object
		Arrival *arrival = new Arrival(clockTick, numStuds, studArray);

		// Put arrival into queue
		genQueue->enqueue(arrival);
	}
	// Create Registrar object for statistics calculations
	registrar = new Registrar(totWindows, genQueue);
}

void InputHandler::calculateStatistics(int studAmt) {
	registrar->calculateStats(studAmt);
}

void InputHandler::closeFile() {
	f.close();
}