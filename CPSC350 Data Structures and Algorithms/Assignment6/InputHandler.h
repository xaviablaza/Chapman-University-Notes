#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Sorter.h"
using namespace std;
class InputHandler {
	private:
		ifstream f;

		// Array size
		int numDoubles;

		// Quicksort array
		double *qsa;
		// Insertion sort array
		double *isa;
		// Merge sort array
		double *msa;
		
		// Checks if string is malformed double
		bool isMalformedDouble(string input);

	public:
		InputHandler();
		~InputHandler();

		// Opens a file specified by parameter using ifstream
		bool openFile(string iFilePath);

		// Parses a file and creates a Registrar object for statistics calculations
		void parseFile();
		
		// Closes the ifstream
		void closeFile();
		
		// Sorts arrays using quicksort, insertion sort, and merge sort
		void calculateSortTime();
};