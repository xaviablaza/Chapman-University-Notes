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
	if (!bstStudent.isEmpty()) {
	bstStudent.printTree();
	} else {
		cout<<"Student table is empty."<<endl;
	}
}

void Menu::printAllFaculty() {
	if (!bstFaculty.isEmpty()) {
	bstFaculty.printTree();
	} else {
		cout<<"Faculty table is empty."<<endl;
	}
}

int Menu::promptInt(string promptMsg) {
	string input;
	cout<<promptMsg;
	while (true) {
		getline(cin, input); // gets number input + \n
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
	if (!bstStudent.isEmpty()) {
		int inputNum = promptInt("Enter student ID: ");
		printStudentInfo(inputNum);
	} else {
		cout<<"Student table is empty. Add a student first before printing its info."<<endl;
	}
}

void Menu::printStudentInfo(int studentId) {
	StudentRecord sr(studentId);
	if (bstStudent.contains(sr)) {
		bstStudent.printNode(sr);
	} else {
		cout<<"Student ID "<<studentId<<" not found."<<endl;
	}
}

void Menu::printFacultyMember() {
	if (!bstFaculty.isEmpty()) {
		int inputNum = promptInt("Enter faculty ID: ");
		printFacultyInfo(inputNum);
	} else {
		cout<<"Faculty table is empty. Add a faculty member first before printing its info."<<endl;
	}
}

void Menu::printFacultyInfo(int facultyId) {
	FacultyRecord fr(facultyId);
	if (bstFaculty.contains(fr)) {
		bstFaculty.printNode(fr);
	} else {
		cout<<"Faculty ID "<<facultyId<<" not found."<<endl;
	}
}

void Menu::printAdvisor() {
	if (!bstStudent.isEmpty()) {
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
	} else {
		cout<<"Student table is empty. Add a student first before printing its info."<<endl;
	}
}

void Menu::printAdvisees() {
	if (!bstFaculty.isEmpty()) {
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
	} else {
		cout<<"Faculty table is empty. Add a faculty member first before printing its info."<<endl;
	}
}

void Menu::promptString(string promptMsg, string &input, bool nonEmpty) {
	cout<<promptMsg;
	while (true) {
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
bool Menu::isMalformedDouble(string input) {
	bool hasPoint = false;
	if (input.size() == 1 && !isdigit(input[0])) return true;
	if (input[input.size()-1] == '.') return true;
	for (int i=0; i<input.size()-1; ++i) {
		if (input[i] == '.') {
			if (hasPoint) return true;
			else hasPoint = true;
		} else if(!isdigit(input[i])) {
			return true;
		}
	}
	return false;
}

void Menu::addStudent() {
	string hack;
	getline(cin, hack);
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
	cout<<promptMsg;
	while (true) {
		string sgpa;
		getline(cin, sgpa);
		if (sgpa.empty()) {
			cout<<"Input must not be empty. Try again: ";
			continue;
		}
		if (isMalformedDouble(sgpa)) {
			cout<<"Malformed double. Try again: ";
			continue;
		} else {
			gpa = atof(sgpa.c_str());
			break;
		}
	}
	// Enter advisorId
	cout<<"Press [Enter] to skip adding an advisor ID."<<endl;
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
		return;
	}
	// Check if advisorId exists. If exists allgood
	FacultyRecord fr(advisorIdNum);
	if (advisorIdNum == -1 || bstFaculty.contains(fr)) {
		bstStudent.insert(sr);
	} else {
		cout<<"Advisor ID "<<advisorId<<" does not exist."<<endl;
	}
	// If nonempty advisorId does not exist, then warn user of breaking referential integrity
	// If proceed, then add stud. If not, abort
}

void Menu::deleteStudent() {
	if (bstStudent.isEmpty()) {
		cout<<"Student table is empty. Add a student first before printing its info."<<endl;
		return;
	}
	// Prompt for student id
	int id = promptInt("Enter student id: ");
	// Check if student tree contains id
	StudentRecord sr(id);
	if (bstStudent.contains(sr)) {
		FacultyRecord fr;
		fr.addAdviseeId(id);
		bool successful = bstFaculty.removeStudentId(id);
		// successful = false if the student is not an advisee of any advisor
		// could possibly just look at the advisor id and check if -1 then delete it
		if (!successful) {
			bstStudent.deleteNode(sr);
		} else {
			cout<<"Student has an advisor. Please change or remove student's advisor before deleting student."<<endl;
		}
	} else {
		cout<<"Student ID "<<id<<" does not exist."<<endl;
	}
}

void Menu::addFacultyMember() {
	// Enter faculty id
	int id = promptInt("Enter faculty id: ");
	// Enter faculty name
	string promptMsg = "Enter faculty name: ";
	string name;
	promptString(promptMsg, name, true);
	// Enter faculty level
	promptMsg = "Enter faculty level: ";
	string level;
	promptString(promptMsg, level, true);
	// Enter faculty department
	promptMsg = "Enter faculty department: ";
	string department;
	promptString(promptMsg, department, true);
	
	FacultyRecord fr(id, name, level, department);
	
	// Enter advisee IDs
	cout<<"Enter a single advisee ID and press [Enter] to add it."<<endl;
	cout<<"When you are finished adding IDs, type /done and press [Enter]"<<endl;
	promptMsg = "Enter advisee ID: ";
	string input;
	cout<<promptMsg;
	while (true) {
		getline(cin, input);
		getline(cin, input);

		for (int i=0; i<input.size(); ++i){
			cout<<input[i];
		}
		cout<<input<<endl;
		if (input.empty()) { // nonEmpty = true if input must be nonEmpty
			cout<<"Input must not be empty. Try again: ";
		} else if (input == "/done") {
			break;
		} else if (!isMalformedInt(input)) {
			int idNum = atoi(input.c_str());
			fr.addAdviseeId(idNum);
			cout<<promptMsg;
		} else {
			cout<<"Malformed int. Try again: ";
		}
	}
	bstFaculty.insert(fr);
}

void Menu::deleteFacultyMember() {
	if (bstFaculty.isEmpty()) {
		cout<<"Faculty table is empty. Add a faculty member first before printing its info."<<endl;
		return;
	}

	// Prompt for faculty id
	int id = promptInt("Enter faculty id: ");
	// Check if faculty tree contains id
	FacultyRecord fr(id);
	FacultyRecord found = bstFaculty.find(fr);
	if (found.id != -1) {
		// Check if the advisee list is empty
		if (found.hasNoAdvisees()) {
			bstFaculty.deleteNode(found);
		} else {
			cout<<"Faculty ID "<<id<<" has advisees. Please remove advisees before deleting faculty member."<<endl;
		}
	} else {
		cout<<"Faculty ID "<<id<<" does not exist."<<endl;
	}
}

void Menu::changeAdvisor() {
	if (bstStudent.isEmpty()) {
		cout<<"Student table is empty. Add a student first before printing its info."<<endl;
		return;
	}

	// Enter student id
	int studId = promptInt("Enter student id: ");
	StudentRecord sr(studId);
	StudentRecord found = bstStudent.find(sr);
	FacultyRecord old(found.advisorId);
	if (found.id != -1) {
		int facultyId = promptInt("Enter new advisor id: ");
		FacultyRecord newr(facultyId);
		if (bstFaculty.contains(newr)) {
			sr.advisorId = facultyId;
			// replace advisor id in the student tree
			bstStudent.replaceAdvisorId(sr);

			// replace student id in the faculty tree
			bstFaculty.replaceStudentId(old, newr, studId);

		} else {
			cout<<"Faculty ID "<<facultyId<<" does not exist."<<endl;
		}
	} else {
		cout<<"Student ID "<<studId<<" does not exist"<<endl;
	}
}

void Menu::removeAdvisee() {
	if (bstFaculty.isEmpty()) {
		cout<<"Faculty table is empty. Add a faculty member first before printing its info."<<endl;
		return;
	}

	// Enter faculty id
	int facultyId = promptInt("Enter faculty id: ");
	FacultyRecord fr(facultyId);
	FacultyRecord found = bstFaculty.find(fr);
	if (found != -1) {
		// Enter student id
		int studId = promptInt("Enter student id: ");
		if (found.containsAdviseeId(studId)) {
			bstFaculty.removeAdviseeId(found, studId);
		}
	} else {
		cout<<"Faculty ID "<<facultyId<<" does not exist."<<endl;
	}
}

void Menu::rollback() {

}

void Menu::exit() {
	cout<<"Exiting..."<<endl;
}