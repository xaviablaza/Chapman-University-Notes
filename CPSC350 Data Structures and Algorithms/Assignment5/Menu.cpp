#include "Menu.h"
Menu::Menu() {
	// Load the BSTs
	// See: http://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
	struct stat buffer;   
	if (stat (STUDENT_TABLE.c_str(), &buffer) == 0) {
		bstStudent.loadFromFile(STUDENT_TABLE);
	}
	if (stat (FACULTY_TABLE.c_str(), &buffer) == 0) {
		bstFaculty.loadFromFile(FACULTY_TABLE);
	}
}

Menu::~Menu(){}

bool Menu::isMalformedInt(string input) {
	for (int i=0; i<input.size(); ++i) {
		if (!isdigit(input[i])) {
			return true;
		}
	}
	return false;
}

void Menu::printMenu() {
	cout<<"--------------------MENU-------------------"<<endl;
	cout<<1<<".  Print all student info (by ascending id)"<<endl;
	cout<<2<<".  Print all faculty info (by ascending id)"<<endl;
	cout<<3<<".  Print student info by student id"<<endl;
	cout<<4<<".  Print faculty info by faculty id"<<endl;
	cout<<5<<".  Print info of a student's faculty advisor"<<endl;
	cout<<6<<".  Print all advisees of a faculty member"<<endl;
	cout<<7<<".  Add a new student"<<endl;
	cout<<8<<".  Delete a student"<<endl;
	cout<<9<<".  Add a new faculty member"<<endl;
	cout<<10<<". Delete a faculty member"<<endl;
	cout<<11<<". Change a student's advisor"<<endl;
	cout<<12<<". Remove an advisee from a faculty member"<<endl;
	cout<<13<<". Rollback"<<endl;
	cout<<14<<". Exit"<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"Enter an option: ";
}

void Menu::promptOption() {
	string inputStr;
	int inputNum;
	printMenu();
	while (true) {
		cin>>inputStr;
		if (isMalformedInt(inputStr)) {
			cout<<"Malformed int. Try again: ";
			continue;
		}
		inputNum = atoi(inputStr.c_str());
		cout<<"-----------------OPTION "<<inputNum<<"-----------------"<<endl;
		switch (inputNum) {
			case 1:
				printAllStudents();
				break;
			case 2:
				printAllFaculty();
				break;
			case 3:
				printStudent();
				break;
			case 4:
				printFacultyMember();
				break;
			case 5:
				printAdvisor();
				break;
			case 6:
				printAdvisees();
				break;
			case 7:
				addStudent();
				break;
			case 8:
				deleteStudent();
				break;
			case 9:
				addFacultyMember();
				break;
			case 10:
				deleteFacultyMember();
				break;
			case 11:
				changeAdvisor();
				break;
			case 12:
				removeAdvisee();
				break;
			case 13:
				rollback();
				break;
			case 14:
				exit();
				return;
			default:
				cout<<"Invalid option. Try again: ";
				continue;
		}
		printMenu();
	}
}

void Menu::printAllStudents() {
	bstStudent.printTree();
}

void Menu::printAllFaculty() {
	bstFaculty.printTree();
}

int Menu::promptInt(string promptMsg) {
	string input;
	cout<<promptMsg;
	while (true) {
		getline(cin, input);
		getline(cin, input);
		if (!input.empty()) {
			if (isMalformedInt(input)) {
				cout<<"Malformed int. Try again: ";
			} else break;
		} else {
			cout<<"Input must not be empty. Try again: ";
		}
	}
	return atoi(input.c_str());
}

void Menu::printStudent() {
	int inputNum = promptInt("Enter student ID: ");
	printStudentInfo(inputNum);
}

void Menu::printStudentInfo(int studentId) {
	StudentRecord sr(studentId);
	if (bstStudent.contains(sr)) {
		bstStudent.printNode(sr);
	} else {
		cout<<"Student ID "<<studentId<<" not found."<<endl;
		cout<<"Returning to menu..."<<endl;
	}
}

void Menu::printFacultyMember() {
	int inputNum = promptInt("Enter faculty ID: ");
	printFacultyInfo(inputNum);
}

void Menu::printFacultyInfo(int facultyId) {
	FacultyRecord fr(facultyId);
	if (bstFaculty.contains(fr)) {
		bstFaculty.printNode(fr);
	} else {
		cout<<"Faculty ID "<<facultyId<<" not found."<<endl;
		cout<<"Returning to menu..."<<endl;
	}
}

void Menu::printAdvisor() {
	int studentId = promptInt("Enter student ID: ");
	StudentRecord sr(studentId);
	StudentRecord val = bstStudent.find(sr);
	if (val.id >= 0) {
		if (val.advisorId < 0) {
			cout<<val.name<<" has no faculty advisor."<<endl;
		} else printFacultyInfo(val.advisorId);
	} else {
		cout<<"Student ID "<<studentId<<" not found."<<endl;
	}
	cout<<"Returning to menu..."<<endl;
}

void Menu::printAdvisees() {
	int facultyId = promptInt("Enter faculty ID: ");
	FacultyRecord fr(facultyId);
	FacultyRecord val = bstFaculty.find(fr);
	if (val.id >= 0) {
		ListNode<int> *node = val.adviseeIds->head;
		if (node != NULL) {
			while (true) {
				StudentRecord sr;
				sr.id = node->data;
				StudentRecord stud = bstStudent.find(sr);
				cout<<stud.name<<endl;
				if (node->next == NULL) {
					break;
				} else {
					node = node->next;
				}
			}
		} else {
			cout<<val.name<<" has no advisees.";
		}
	} else {
		cout<<"Faculty ID "<<facultyId<<" not found."<<endl;
	}
	cout<<"Returning to menu..."<<endl;
}

void Menu::promptString(string promptMsg, string &input, bool nonEmpty) {
	cout<<promptMsg;
	while (true) {
		getline(cin, input);
		getline(cin, input);

		for (int i=0; i<input.size(); ++i){
			cout<<input[i];
		}
		cout<<input<<endl;
		if (nonEmpty && input.empty()) { // nonEmpty = true if input must be nonEmpty
			cout<<"Input must not be empty. Try again: ";
		} else break;
	}
}

// See: http://stackoverflow.com/questions/5932391/determining-if-a-string-is-a-double
bool Menu::isOnlyDouble(const char* str) {
	char* endptr = 0;
	strtod(str, &endptr);
	if (*endptr != '\0' || endptr == str)
		return false;
	return true;
}

void Menu::addStudent() {
	// Enter student id
	int id = promptInt("Enter student id: ");
	// Enter student name
	string promptMsg = "Enter student name: ";
	string name;
	promptString(promptMsg, name, true);
	// Enter student level
	promptMsg = "Enter student level: ";
	string level;
	promptString(promptMsg, level, true);
	// Enter major
	promptMsg = "Enter student major: ";
	string major;
	promptString(promptMsg, major, true);
	// Enter gpa
	promptMsg = "Enter student GPA: ";
	double gpa;	
	while (true) {
		string sgpa;
		promptString(promptMsg, sgpa, true);
		if (isOnlyDouble(sgpa.c_str())) {
			cout<<"Malformed double. Try again: ";
		} else {
			gpa = atof(sgpa.c_str());
			break;
		}
	}
	// Enter advisorId
	promptMsg = "Enter advisor ID: ";
	string advisorId;
	int advisorIdNum;
	promptString(promptMsg, advisorId, false);
	if (advisorId.empty()) {
		advisorIdNum = -1;
	} else {
		advisorIdNum = atoi(advisorId.c_str());
	}
	// Check if there's the same stud id and abort
	StudentRecord sr(id, name, level, major, gpa, advisorIdNum);
	if (bstStudent.contains(sr)) {
		cout<<"Student ID "<<id<<" already exists."<<endl;
		cout<<"Returning to menu..."<<endl;
		return;
	}
	// Check if advisorId exists. If exists allgood
	FacultyRecord fr(advisorIdNum);
	if (advisorIdNum == -1 || bstFaculty.contains(fr)) {
		bstStudent.insert(sr);
	} else {
		promptMsg = "Advisor ID  " + advisorId + " does not exist. Continue? (y/n): ";
		string answer;
		bool continue_ = promptWarning(promptMsg, answer);
		if (continue_) {
			bstStudent.insert(sr);
		}
	}
	// If nonempty advisorId does not exist, then warn user of breaking referential integrity
	// If proceed, then add stud. If not, abort
}

bool Menu::promptWarning(string promptMsg, string &input) {
	cout<<promptMsg<<endl;
	while (true) {
		getline(cin, input);
		getline(cin, input);
		if (input == "y") {
			return true;
		} else if (input == "n") {
			return false;
		} else {
			cout<<"Invalid input. Try again: ";
		}
	}
}

void Menu::deleteStudent() {
	// Prompt for student id
	int id = promptInt("Enter student id: ");
	// Check if student tree contains id
	StudentRecord sr(id);
	if (bstStudent.contains(sr)) {
		FacultyRecord fr;
		fr.addAdviseeId(id);

		// TODO: need to work on iterator
		// check if faculty tree contains id
		BSTIterator<FacultyRecord> it(bstFaculty.getRoot());
		while (it.hasNext()) {
			FacultyRecord frt = it.next();
			if (frt.containsAdviseeId(id)) {
				string answer;
				// If faculty tree contains id, promptWarning
				string promptMsg;
				bool continue_= promptWarning(promptMsg, answer);

				if (continue_) {

				}
				if (continue_) {	
					//bstStudent.remove
				}
				// if yes remove student and display message to user
				// else abort
			}
		}




	} else {
		cout<<"Student ID "<<id<<" does not exist."<<endl;
		cout<<"Returning to menu..."<<endl;
	}
}

void Menu::addFacultyMember() {
	
}

void Menu::deleteFacultyMember() {

}

void Menu::changeAdvisor() {

}

void Menu::removeAdvisee() {

}

void Menu::rollback() {

}

void Menu::exit() {
	cout<<"Exiting..."<<endl;
}