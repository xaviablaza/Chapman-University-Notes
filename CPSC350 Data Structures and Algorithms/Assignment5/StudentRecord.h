#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
class StudentRecord {
	public:
		StudentRecord();
		~StudentRecord();
		StudentRecord(int id_);
		StudentRecord(int id_, string name_, string level_, string major_, double gpa_, int advisorId_);
		StudentRecord(string serializedSr);
		string serialize();
		
		bool operator==(const StudentRecord &s) {
			return (this->id == s.id);
		}

		bool operator!=(const StudentRecord &s) {
			return (this->id != s.id);
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

		friend ostream& operator<<(ostream& os, const StudentRecord &s) {
			os<<"Student Name: "<<s.name<<endl;
			os<<"Student ID: "<<s.id<<endl;
			os<<"Level: "<<s.level<<endl;
			os<<"Major: "<<s.major<<endl;
			os<<"GPA: "<<s.gpa<<endl;
			if (s.advisorId >= 0) os<<"Advisor ID: "<<s.advisorId<<endl;
			else os<<"Advisor ID: None"<<endl;
			return os;
		}

		int id;
		string name;
		string level;
		string major;
		double gpa;
		int advisorId;
	private:
		void deserialize(string serializedSr);
};