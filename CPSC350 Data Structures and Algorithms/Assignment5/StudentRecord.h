#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;
class StudentRecord {
	public:
		StudentRecord();
		~StudentRecord();
		StudentRecord(int id_, string name_, string level_, string major_, double gpa_, int advisorId_);
		string serialize();
		
		bool operator==(const StudentRecord &s) {
			return (this->id == s.id);
		}

		bool operator<=(const StudentRecord &s) {
			return (this->id <= s.id);
		}

		bool operator<(const StudentRecord &s) {
			return (this->id < s.id);
		}

		bool operator>=(const StudentRecord &s){
			return (this->id >= s.id);
		}

		bool operator>(const StudentRecord &s){
			return (this->id > s.id);
		}

		int id;
		string name;
		string level;
		string major;
		double gpa;
		int advisorId;
};