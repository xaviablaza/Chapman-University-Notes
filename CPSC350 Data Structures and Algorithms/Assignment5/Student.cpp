#include "Student.h"
Student::Student() {
	id = -1;
	name = "";
	level = "";
	major = "";
	gpa = -1.0;
	advisorId  -1;
}

Student::~Student(){}

Student::Student(int id_, string name_, string level_, string major_, double gpa_, int advisorId_) {
	id = id_;
	name = name_;
	level = level_;
	major = major_;
	gpa = gpa_;
	advisorId = advisorId_;
}