#include "InputHandler.h"
using namespace std;
int main(int argc, char** argv) {
	// Checks if the correct amount of arguments are specified
	if (argc == 1) {
		cout<<"Syntax error: Specify a file name."<<endl;
		return 0;
	}
	if (argc >= 3) {
		cout<<"Syntax error: Too many arguments."<<endl;
		cout<<"Try: ./a.out <fileName>"<<endl;
		cout<<"Example: ./a.out main.cpp"<<endl;
		return 0;
	}

	InputHandler inputHandler;
	inputHandler.openFile(argv[1]);
	bool successful = inputHandler.parseFile();
	inputHandler.closeFile();
	if (successful) {
		cout<<"No mismatched delimiters found."<<endl;
		inputHandler.promptPath("Enter name of source file to analyze: ");
	}
	return 0;
}
