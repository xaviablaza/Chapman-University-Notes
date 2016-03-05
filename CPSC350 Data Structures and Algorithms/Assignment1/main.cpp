#include "DnaStringFile.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc == 1) {
		cout<<"Syntax error: Specify a file name."<<endl;
		return -1;
	}
	if (argc >= 3) {
		cout<<"Syntax error: Too many arguments."<<endl;
		cout<<"Try: ./dnaanalysis.out <fileName>"<<endl;
		cout<<"Example: ./dnaanalysis.out dnafile.txt"<<endl;
		return -1;
	}
	string filePath = argv[1];
	while (true) {
		DnaStringFile dsf;
		if (!dsf.open(filePath)) {
			return -1;
		}
		dsf.computeStatistics();
		dsf.close();
		dsf.printStatisticsToFile();
		dsf.printGaussianDnaString(1000);
		
		cout<<"Would you like to process another list? (y/n): ";
		string response;
		cin>>response;
		if (response.compare("y") == 0 || response.compare("Y") == 0) {
			cout<<"Enter file name: ";
			string fileName;
			cin>>fileName;
			filePath = fileName;
			continue;
		} else break;
	}	
	return 0;
}
