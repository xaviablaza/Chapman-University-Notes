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
		cout<<"Example: ./a.out sample.txt"<<endl;
		return 0;
	}

	InputHandler ih;
	ih.openFile(argv[1]);
	ih.parseFile();
	ih.calculateStatistics(ih.studAmt);
	ih.closeFile();
	return 0;
}
