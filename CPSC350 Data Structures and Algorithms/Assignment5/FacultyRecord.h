#include "DoublyLinkedList.h"
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
class FacultyRecord {
	public:
		FacultyRecord();
		~FacultyRecord();
		FacultyRecord(int id_, string name_, string level_, string department_);
		FacultyRecord(string serializedFr);
		string serialize();
		void addAdviseeId(int);
		int removeAdviseeId(int);

		bool operator==(const FacultyRecord &f) {
			return (this->id == f.id);
		}

		bool operator<=(const FacultyRecord &f) {
			return (this->id <= f.id);
		}

		bool operator<(const FacultyRecord &f) {
			return (this->id < f.id);
		}

		bool operator>=(const FacultyRecord &f){
			return (this->id >= f.id);
		}

		bool operator>(const FacultyRecord &f){
			return (this->id > f.id);
		}

		int id;
		string name;
		string level;
		string department;
		DoublyLinkedList<int> *adviseeIds;
	private:
		void deserialize(string serializedFr);
};