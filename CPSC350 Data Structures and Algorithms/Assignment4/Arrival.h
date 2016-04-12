#include "Student.h"
class Arrival {
	public:
		Arrival();
		~Arrival();

		// clockTick_ tick all students arrive
		// numStuds_ number of students
		// *firstStud pointer to Student[] that decays to the first object of the array
		Arrival(int clockTick_, int numStuds_, Student *firstStud);
		int clockTick;
		int numStuds;
		Student *students;
};