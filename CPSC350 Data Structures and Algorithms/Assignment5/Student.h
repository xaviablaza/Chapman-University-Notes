#include <string>
using namespace std;
class Student {
	public:
		Student();
		~Student();
		Student(int id_, string name_, string level_, string major_, double gpa_, int advisorId_);
		
		bool operator==(const Student &s) {
			return (this->id == s.id);
		}

		bool operator<=(const Student &s) {
			return (this->id <= s.id);
		}

		bool operator<(const Student &s) {
			return (this->id < s.id);
		}

		bool operator>=(const Student &s){
			return (this->id >= s.id);
		}

		bool operator>(const Student &s){
			return (this->id > s.id);
		}

		int id;
		string name;
		string level;
		string major;
		double gpa;
		int advisorId;
};