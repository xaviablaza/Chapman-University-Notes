#include "StudentRecord.h"
StudentRecord::StudentRecord() {
	id = -1;
	name = "";
	level = "";
	major = "";
	gpa = -1.0;
	advisorId  -1;
}

StudentRecord::~StudentRecord(){}

StudentRecord::StudentRecord(int id_, string name_, string level_, string major_, double gpa_, int advisorId_) {
	id = id_;
	name = name_;
	level = level_;
	major = major_;
	gpa = gpa_;
	advisorId = advisorId_;
}

string StudentRecord::serialize() {
	ostringstream oss;
	oss<<id<<','+name+','+level+','+major+','<<gpa<<','<<advisorId;
	return oss.str();
}