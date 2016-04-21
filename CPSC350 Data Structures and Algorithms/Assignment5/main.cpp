// #include "InputHandler.h"
#include "BST.h"
#include "StudentRecord.h"
#include "FacultyRecord.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv) {

	// Uncomment to test binary search tree
	/*BST<int> bst = BST<int>();
	bst.insert(7);
	bst.insert(4);
	bst.insert(9);
	bst.insert(5);
	bst.insert(6);
	bst.insert(2);
	bst.insert(8);
	bst.insert(3);
	bst.insert(1);
	bst.printTree();
	cout<<"---END---"<<endl;
	bst.deleteNode(7);
	bst.printTree();
	cout<<"---END---"<<endl;
	bst.deleteNode(4);
	bst.printTree();
	cout<<"---END---"<<endl;
	bst.deleteNode(2);
	bst.printTree();
	cout<<"---END---"<<endl;
	bst.deleteNode(8);
	bst.printTree();*/

	// Uncomment to test overloaded operators
	/*Student s1 = Student();
	s1.id = 500;
	Student s2 = Student();
	s2.id = 100;
	bool result = s1>s2;
	cout<<result<<endl;*/

	// Uncomment to test removing a node based on its data
	/*DoublyLinkedList<int> *dl = new DoublyLinkedList<int>();
	dl->insertBack(1);
	dl->insertBack(2);
	dl->insertBack(3);
	dl->remove(2);
	cout<<dl->removeFront()<<endl;
	cout<<dl->removeFront()<<endl;
	delete dl;*/

	// Uncomment to test serialization/deserialization
	/*StudentRecord sr = StudentRecord(1252, "Chris Shiherlis", "Freshman", "Software Engineering", 4.0, 4598);
	string serializedSr = sr.serialize();
	cout<<serializedSr<<endl;
	FacultyRecord fr = FacultyRecord(12053, "Sierra Montalcini", "Doctor", "Schmid");
	fr.addAdviseeId(1252);
	fr.addAdviseeId(1253);
	string serializedFr = fr.serialize();
	cout<<serializedFr<<endl;
	StudentRecord sr2 = StudentRecord(serializedSr);
	cout<<sr2.serialize()<<endl;
	FacultyRecord fr2 = FacultyRecord(serializedFr);
	cout<<fr2.serialize()<<endl;*/

	BST<StudentRecord> bst = BST<StudentRecord>();
	//TODO: Handling NULL advisorId
	bst.insert(StudentRecord(1252, "Chris Shiherlis", "Freshman", "Software Engineering", 4.0, 4598));
	bst.insert(StudentRecord(1253, "Frankie Minko", "Sophomore", "Biology", 3.5, 4599));
	bst.insert(StudentRecord(1251, "Johnny Carmichael", "Senior", "Business", 3.0, 4600));
	bst.writeToFile("studentTable");
	
	return 0;
}
