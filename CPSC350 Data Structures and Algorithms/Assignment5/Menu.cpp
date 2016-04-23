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
	cout<<1<<". Print all student info (by ascending id)"<<endl;
	cout<<2<<". Print all faculty info (by ascending id)"<<endl;
	cout<<3<<". Print student info by student id"<<endl;
	cout<<4<<". Print faculty info by faculty id"<<endl;
	cout<<5<<". Print info of a student's faculty advisor"<<endl;
	cout<<6<<". Print all advisees of a faculty member"<<endl;
	cout<<7<<". Add a new student"<<endl;
	cout<<8<<". Delete a student"<<endl;
	cout<<9<<". Add a new faculty member"<<endl;
	cout<<10<<". Delete a faculty member"<<endl;
	cout<<11<<". Change a student's advisor"<<endl;
	cout<<12<<". Remove an advisee from a faculty member"<<endl;
	cout<<13<<". Rollback"<<endl;
	cout<<14<<". Exit"<<endl;
}

void Menu::promptOption() {
	string inputStr;
	int inputNum;
	while (true) {
		cin>>inputStr;
		if (isMalformedInt(inputStr)) {
			cout<<"Malformed int. Try again: ";
			continue;
		}
		inputNum = atoi(inputStr.c_str());
		switch (inputNum) {
			case 1:
				printAllStudents();
				continue;
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
				break;
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
	string inputStr;
	cout<<promptMsg;
	while (true) {
		cin>>inputStr;
		if (isMalformedInt(inputStr)) {
			cout<<"Malformed int. Try again: ";
			continue;
		} else break;
	}
	return atoi(inputStr.c_str());
}

void Menu::printStudent() {
	int inputNum = promptInt("Enter student ID: ");
	printStudentInfo(inputNum);
}

void Menu::printStudentInfo(int studentId) {
	StudentRecord sr;
	sr.id = studentId;
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
	FacultyRecord fr;
	fr.id = facultyId;
	if (bstFaculty.contains(fr)) {
		bstFaculty.printNode(fr);
	} else {
		cout<<"Faculty ID "<<facultyId<<" not found."<<endl;
		cout<<"Returning to menu..."<<endl;
	}
}

//TODO: need erroring for null advisor
void Menu::printAdvisor() {
	int inputNum = promptInt("Enter student ID: ");
	StudentRecord sr;
	sr.id = inputNum;
	StudentRecord val = bstStudent.find(sr);
	if (val.id >= 0) {
		printFacultyInfo(val.advisorId);
	} else {
		cout<<"Student ID "<<inputNum<<" not found."<<endl;
		cout<<"Returning to menu..."<<endl;
	}
}

void Menu::printAdvisees() {
	int inputNum = promptInt("Enter faculty ID: ");
	FacultyRecord fr;
	fr.id = inputNum;
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
			cout<<"Faculty member has no advisees.";
			cout<<"Returning to menu..."<<endl;
		}
	} else {
		cout<<"Faculty ID "<<inputNum<<" not found."<<endl;
		cout<<"Returning to menu..."<<endl;
	}
}

void Menu::addStudent() {

}

void Menu::deleteStudent() {

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

}