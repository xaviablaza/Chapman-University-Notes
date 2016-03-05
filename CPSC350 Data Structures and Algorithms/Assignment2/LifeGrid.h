#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
class LifeGrid {
	private:
		int genNum;
		int mode;
		int height;
		int width;
		int numElements;
		bool stabilized;
		// This is a pointer to a pointer to a char,
		// set to point to an array of pointers to char
		char **arena;
		char **nextArena;
	public:
		LifeGrid(int mode_, int height, int width);
		LifeGrid();
		~LifeGrid();
		bool makeInitialMap(ifstream &f);
		void makeInitialMap(double density);
		bool isEmpty();
		bool isStabilized();
		void printGenerationNumber();
		void printCurrentGeneration();
		void makeNextGeneration();
		void printGenerationsToFile(string oFilePath);
};
