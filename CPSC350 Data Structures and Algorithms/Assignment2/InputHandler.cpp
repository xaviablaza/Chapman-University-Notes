#include "InputHandler.h"
InputHandler::InputHandler(){}
InputHandler::~InputHandler() {}
int InputHandler::promptOptionInt(string promptMsg, string optionName, int numOptions) {
	cout<<promptMsg;
	string inputStr;
	int inputNum;
	while (true) {
		cin>>inputStr;
		if (isMalformedInt(inputStr)) {
			cout<<"Malformed int. Try again: ";
			continue;
		}
		inputNum = atoi(inputStr.c_str());
		if (!(inputNum>=0 && inputNum<numOptions)) {
			cout<<"Invalid "<<optionName<<". Try again: ";
			continue;
		}
		return inputNum;
	}
}
bool InputHandler::isMalformedInt(string input) {
	for (int i=0; i<input.size(); ++i) {
		if (!isdigit(input[i])) {
			return true;
		}
	}
	return false;
}
string InputHandler::promptPath(string promptMsg) {
	cout<<promptMsg;
	string iFilePath;
	while (true) {
		cin>>iFilePath;
		// See: http://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
		struct stat buffer;   
		if (!(stat (iFilePath.c_str(), &buffer) == 0)) {
			cout<<"IOError: File does not exist."<<endl;
			cout<<promptMsg;
			continue;
		}
		return iFilePath;
	}
}
int InputHandler::promptInt(string promptMsg) {
	cout<<promptMsg;
	string inputStr;
	int inputNum;
	while (true) {
		cin>>inputStr;
		if (isMalformedInt(inputStr)) {
			cout<<"Malformed int. Try again: ";
			continue;
		}
		inputNum = atoi(inputStr.c_str());
		return inputNum;
	}
}
double InputHandler::promptDouble(string promptMsg) {
	cout<<promptMsg;
	string inputStr;
	double inputNum;
	while (true) {
		cin>>inputStr;
		if (isMalformedFloat(inputStr)) {
			cout<<"Malformed float. Try again: ";
			continue;
		}
		inputNum = atof(inputStr.c_str());
		return inputNum;
	}
}
bool InputHandler::isMalformedFloat(string input) {
	bool hasPoint = false;
	for (int i=0; i<input.size(); ++i) {
		if (input[i] == '.') {
			hasPoint = true;
		} else if(!isdigit(input[i])) {
			return true;
		}
	}
	return false;
}
