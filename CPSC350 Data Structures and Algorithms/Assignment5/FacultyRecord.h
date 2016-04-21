#include "DoublyLinkedList.h"
#include <string>
#include <sstream>
using namespace std;
class FacultyRecord {
	public:
		FacultyRecord();
		~FacultyRecord();
		FacultyRecord(int id_, string name_, string level_, string department_);
		string serialize();
		void addAdviseeId(int);
		int removeAdviseeId(int);

		int id;
		string name;
		string level;
		string department;
		DoublyLinkedList<int> *adviseeIds;
};