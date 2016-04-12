#include "Student.h"
Student::Student(){}
Student::~Student(){}
Student::Student(int minsAtWindow){
	minsNeeded = minsAtWindow;
}

// Extension: Could include other fields like student name,
// ID number, college, major, etc.