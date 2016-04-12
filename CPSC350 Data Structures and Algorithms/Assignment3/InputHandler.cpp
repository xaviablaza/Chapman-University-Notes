#include "InputHandler.h"

// Default constructor to create GenStack of size 10
InputHandler::InputHandler(){
	genStack = new GenStack<char>(10);
}

// Destructor that deletes genStack
InputHandler::~InputHandler() {
	delete genStack;
}

// Opens a file specified by parameter using ifstream
void InputHandler::openFile(string iFilePath) {
	f.open(iFilePath.c_str());
}

// Parses the file for any mismatched delimiters including: (, ), {, }, [, ]
bool InputHandler::parseFile() {
	// Declare delimiters
	const char openingDelimiters[] = {'(', '{', '['};
	const char closingDelimiters[] = {')', '}', ']'};
	const int delimiterSize = 3;

	// Declare string to analyze
	string line;

	// bool to ignore if delimiter is enclosed as a comment or within single or double quotes
	bool ignore = false;

	// int to count rows checked
	int row = 1;

	while (getline(f, line)) {
		for (int i=0; i<line.size(); ++i) {

			// char must be unsigned to check its hex value
			unsigned char curr = line[i];

			// Loop through delimiter array to see if current char is a delimiter
			for (int j=0; j<3; ++j) {
				if (!ignore) {
					if (curr == openingDelimiters[j]) {
						// If full, extend the genStack to be twice as large
						if (genStack->isFull()) {
							genStack->extend(genStack->size*2);
						} else {
							genStack->push(curr);
						}
					} else if (curr == closingDelimiters[j]) {

						// If the peeked element is not the correct opening delimiter
						if (genStack->peek() != openingDelimiters[j]) {

							// We may encounter a case where there is a mismatched delimiter inside matching outer delimiters
							// An instance would look like this: {)} or {(} or {((}
							// The following check fixes this
							if (!genStack->isEmpty()) {
								char expectedDelimiter;
								char popped = genStack->pop();
								if (genStack->isEmpty()) {
									if (curr == ')') {
										expectedDelimiter = '(';
									} else if (curr == ']') {
										expectedDelimiter = '[';
									} else if (curr == '}') {
										expectedDelimiter = '{';
									}
								} else /*if (genStack->peek() == openingDelimiters[j])*/ {
									if (popped == '(') {
										expectedDelimiter = ')';
									} else if (popped == '[') {
										expectedDelimiter = ']';
									} else if (popped == '{') {
										expectedDelimiter = '}';
									}
								}
								cout<<"Line "<<row<<": expected "<<expectedDelimiter<<" and found "<<curr<<endl;
							}
							return false;

						}
						// The recently pushed element in the genStack is correct, so pop it
						genStack->pop();
					}
				}
			}
			// If double quote or single quote switch ignore to true/false
			if (curr == 0x27 || curr == 0x22) {
				if (ignore) ignore = false;
				else ignore = true;
			// If multi-line comment symbol /* is encountered then ignore
			} else if (curr == 0x2F && line[i+1] == 0x2A) {
				ignore = true;
			// If multi-line comment symbol */ is encountered then do not ignore
			} else if (curr == 0x2A && line[i+1] == 0x2F) {
				ignore = false;
			// If line has single comment symbol // then skip the line
			} else if (curr == 0x2F && line[i+1] == 0x2F) {
				break;
			}
		}
		row++;
	}
	// Handling delimiters found at the end of the file
	if (!genStack->isEmpty()) {
		if (genStack->pop() == '{') {
			cout<<"Reached end of file: missing }"<<endl;
		} else if (genStack->pop() == '(') {
			cout<<"Reached end of file: mismatched ("<<endl;
		} else if (genStack->pop() == ')') {
			cout<<"Reached end of file: mismatched )"<<endl;
		} else if (genStack->pop() == '[') {
			cout<<"Reached end of file: mismatched ]"<<endl;
		} else if (genStack->pop() == ']') {
			cout<<"Reached end of file: mismatched ["<<endl;
		}
		return false;
	}
	return true;
}
void InputHandler::promptPath(string promptMsg) {
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

		// Recursive prompt for file if analyzation is successful
		openFile(iFilePath);
		bool successful = parseFile();
		closeFile();
		if (successful) promptPath("Enter name of source file to analyze: ");
	}
}
// Closes the ifstream
void InputHandler::closeFile() {
	f.close();
}