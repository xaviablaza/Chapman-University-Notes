#include "InputHandler.h"
InputHandler::InputHandler() {
	qsa = new double[10];
	isa = new double[10];
	msa = new double[10];
}

InputHandler::~InputHandler() {
}

bool InputHandler::openFile(string iFilePath) {
	// See: http://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
	struct stat buffer;   
	if (!(stat (iFilePath.c_str(), &buffer) == 0)) {
		cout<<"IOError: File does not exist. Exiting..."<<endl;
		return false;
	}
	f.open(iFilePath.c_str());
	return true;
}

void InputHandler::parseFile() {
	// Declare string to analyze
	string line;

	// First line is the number of doubles in the list
	getline(f, line);
	if (isMalformedDouble(line)) {
		cout<<"Malformed double at line 1! Exiting..."<<endl;
		return;
	}
	
	// Array size
	numDoubles = atof(line.c_str());
	
	// Init arrays
	qsa = new double[numDoubles];
	isa = new double[numDoubles];
	msa = new double[numDoubles];

	// Arr pointer
	int ptr = 0;
	
	// Loop through file to get all doubles
	while (getline(f, line)) {
		// Check if line is malformed double
		if (isMalformedDouble(line)) {
			// Print error message and exit program
			int lineNum = ptr+2;
			cout<<"Malformed double at line "<<lineNum<<"! Exiting..."<<endl;
			return;
		// Convert string to double and put in all 3 arrays
		} else {
			qsa[ptr] = atof(line.c_str());
			isa[ptr] = atof(line.c_str());
			msa[ptr] = atof(line.c_str());
		}
		// Increment ptr
		++ptr;
	}
	if (ptr != numDoubles) cout<<"Expected "<<numDoubles<<" doubles. Exiting..."<<endl;
}

void InputHandler::calculateSortTime() {
	Sorter<double> s;
	time_t b1;
	s.quickSort(qsa, numDoubles);
	time_t a1;

	time_t b2;
	s.insertionSort(isa, numDoubles);
	time_t a2;

	time_t b3;
	s.oddEvenSort(msa, numDoubles);
	time_t a3;

	cout<<endl;
	cout<<"QuickSort"<<endl;
	cout<<"Time started: "<<b1<<endl;
	cout<<"Time ended: "<<a1<<endl;
	cout<<"Time difference: "<<-(double)difftime(a1, b1)<<endl;
	cout<<endl;

	cout<<"Insertion Sort"<<endl;
	cout<<"Time started: "<<b2<<endl;
	cout<<"Time ended: "<<a2<<endl;
	cout<<"Time difference: "<<-(double)difftime(a2, b2)<<endl;
	cout<<endl;

	cout<<"Odd Even Sort"<<endl;
	cout<<"Time started: "<<b3<<endl;
	cout<<"Time ended: "<<a3<<endl;
	cout<<"Time difference: "<<-(double)difftime(a3, b3)<<endl;
	cout<<endl;
}

void InputHandler::closeFile() {
	f.close();
}

// See: http://stackoverflow.com/questions/5932391/determining-if-a-string-is-a-double
bool InputHandler::isMalformedDouble(string input) {
	bool hasPoint = false;
	if (input.size() == 1 && !isdigit(input[0])) return true;
	if (input[input.size()-1] == '.') return true;
	for (int i=0; i<input.size()-1; ++i) {
		if (input[i] == '.') {
			if (hasPoint) return true;
			else hasPoint = true;
		} else if(!isdigit(input[i])) {
			return true;
		}
	}
	return false;
}