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

		ostream& operator<<(ostream& os, const FacultyRecord& f) {
			os<<"Faculty Member Name: "<<f.name<<endl;
			os<<"Faculty ID: "<<f.id<<endl;
			os<<"Level: "<<f.level<<endl;
			os<<"Department: "<<f.department<<endl;
			os<<"Advisee IDs: ";
			ListNode<int> *node = f.adviseeIds->head;
			if (node != NULL) {
				while (true) {
					os<<node->data;
					if (node->next == NULL) {
						break;
					} else {
						os<<", ";
						node = node->next;
					}
				}
			} else {
				os<<"None"<<endl;
			}
		}

		int id;
		string name;
		string level;
		string department;
		DoublyLinkedList<int> *adviseeIds;
	private:
		void deserialize(string serializedFr);
};