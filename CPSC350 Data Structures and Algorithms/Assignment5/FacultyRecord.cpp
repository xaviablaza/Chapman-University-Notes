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

FacultyRecord::FacultyRecord(int id_) {
	id = id_;
	name = "";
	level = "";
	department = "";
	adviseeIds = new DoublyLinkedList<int>();
}

FacultyRecord::FacultyRecord(int id_, string name_, string level_, string department_) {
	id = id_;
	name = name_;
	level = level_;
	department = department_;
	adviseeIds = new DoublyLinkedList<int>();
}

FacultyRecord::FacultyRecord(string serializedFr) {
	adviseeIds = new DoublyLinkedList<int>();
	deserialize(serializedFr);
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

void FacultyRecord::deserialize(string serializedFr) {
	stringstream ss(serializedFr);
	string item;
	int count = 0;
	while (getline(ss, item, ',')) {
		if (count == 0) id = atoi(item.c_str());
		else if (count == 1) name = item;
		else if (count == 2) level = item;
		else if (count == 3) department = item;
		else if (count >= 4) addAdviseeId(atoi(item.c_str()));
		count++;
	}
}

void FacultyRecord::addAdviseeId(int id) {
	adviseeIds->insertBack(id);
}

int FacultyRecord::removeAdviseeId(int id) {
	return adviseeIds->remove(id);
}

bool FacultyRecord::containsAdviseeId(int id) {
	return (adviseeIds->contains(id));
}