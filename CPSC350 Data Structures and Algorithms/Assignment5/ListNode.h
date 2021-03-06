#include <iostream>
using namespace std;
template<class T>
class ListNode {
	public:
		ListNode();
		~ListNode();

		// Constructor to initialize ListNode with T data
		ListNode(T d);
		
		T data;
		ListNode *prev;
		ListNode *next;
};

template<class T>
ListNode<T>::ListNode() {
	prev = NULL;
	next = NULL;
}

template<class T>
ListNode<T>::~ListNode(){}

template<class T>
ListNode<T>::ListNode(T d) {
	data = d;
	prev = NULL;
	next = NULL;
}