#include "GenStack.cpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
class InputHandler {
	public:
		InputHandler();
		~InputHandler();
		void openFile(string promptMsg);
		bool parseFile();
		void promptPath(string promptMsg);
		void closeFile();
	private:
		GenStack<char> *genStack;
		ifstream f;
};
