#include "Arrival.h"
Arrival::Arrival(){}
Arrival::~Arrival() {
	delete [] students;
}
Arrival::Arrival(int clockTick_, int numStuds_, Student *firstStud) {
	clockTick = clockTick_;
	numStuds = numStuds_;
	students = new Student[numStuds];
	for (int i=0; i<numStuds; ++i) {
		students[i] = firstStud[i];
	}
}