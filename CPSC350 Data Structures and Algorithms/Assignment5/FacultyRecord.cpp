#include "FacultyRecord.h"
FacultyRecord::FacultyRecord() {
	id = -1;
	name = "";
	level = "";
	department = "";
	adviseeIds = new DoublyLinkedList<int>();
}

FacultyRecord::~FacultyRecord() {
	delete adviseeIds;
}

FacultyRecord::FacultyRecord(int id_, string name_, string level_, string department_) {
	id = id_;
	name = name_;
	level = level_;
	department = department_;
	adviseeIds = new DoublyLinkedList<int>();
}

string FacultyRecord::serialize() {
	ostringstream oss;
	oss<<id<<','+name+','+level+','+department+',';
	ListNode<int> *node = adviseeIds->head;
	if (node != NULL) {
		while (true) {
			oss<<node->data;
			if (node->next == NULL) {
				break;
			} else {
				oss<<',';
				node = node->next;
			}
		}
	} else {
		oss<<'-';
	}
	return oss.str();
}

void FacultyRecord::addAdviseeId(int id) {
	adviseeIds->insertBack(id);
}

int FacultyRecord::removeAdviseeId(int id) {
	return adviseeIds->remove(id);
}