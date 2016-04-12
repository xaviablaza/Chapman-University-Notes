#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Registrar.h"
using namespace std;
class InputHandler {
	private:
		ifstream f;
		Registrar *registrar;
	public:
		int studAmt;
		InputHandler();
		~InputHandler();

		// Opens a file specified by parameter using ifstream
		void openFile(string promptMsg);

		// Parses a file and creates a Registrar object for statistics calculations
		void parseFile();

		// Calculates mean student wait time (SWT), median SWT, longest SWT,
		// number of students waiting over 10 ticks, mean window idle time (WIT),
		// longest WID, and number of windows idle for over 5 ticks and prints
		// all statistics to standard output
		void calculateStatistics(int studAmt);

		// Closes the ifstream
		void closeFile();
};
