#include "ListNode.h"
#include <iostream>
using namespace std;

// Doubly linked list where a each node contains a reference
// to the next node & the previous node, but back->next != head and head->prev != back
// DoublyLinkedList of type T, ListNode holds T
template<class T>
class DoublyLinkedList {
	private:
		ListNode<T> *head;
		ListNode<T> *back;
		unsigned int size;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		// Inserts a T* at the front of the list
		void insertFront(T* d);
		
		// Removes and returns a T* from the front of the list
		T* removeFront();

		// Inserts a T* the back of the list
		void insertBack(T* d);

		// Removes and returns a T* from the back of the list
		T* removeBack();

		// Returns, but does not remove a T from the front of the list
		T* peekHead();

		// Returns, but does not remove a T from the back of the list
		T* peekBack();

		// Gets the size of this list
		unsigned int getSize();

		// true if list is empty, false otherwise
		bool isEmpty();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	back = NULL;
	size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	if (head->next == NULL) {
		delete head;
		delete back;
	} else {
		ListNode<T> *temp = head;
		while (head->next != NULL) {
			temp = head->next;
			head->next = NULL;
			temp->prev = NULL;
			delete head;
			head = temp;
		}
	}
}

template<class T>
void DoublyLinkedList<T>::insertFront(T* d) {
	ListNode<T> *node = new ListNode<T>(d);
	if (size == 0) {
		back = node;
	} else {
		head->prev = node;
		node->next = head;
	}
	head = node;
	++size;
}

template<class T>
T* DoublyLinkedList<T>::removeFront() {
	ListNode<T> *temp = head;
	if (head->next == NULL) {
		back = NULL;
	} else {
		head->next->prev = NULL;
		head = head->next;
	}
	T* val = temp->data;
	temp->next = NULL;
	delete temp;
	--size;
	return val;
}

template<class T>
void DoublyLinkedList<T>::insertBack(T* d) {
	ListNode<T> *node = new ListNode<T>(d);
	if (size == 0) {
		head = node;
	} else {
		back->next = node;
		node->prev = back;
	}
	back = node;
	++size;
}

template<class T>
T* DoublyLinkedList<T>::removeBack() {
	ListNode<T> *temp = back;
	if (back->prev == NULL) {
		head = NULL;
	} else {
		back->prev->next = NULL;
		back = back->prev;
	}
	T* val = temp->data;
	temp->prev = NULL;
	delete temp;
	--size;
	return val;
}

template<class T>
T* DoublyLinkedList<T>::peekHead() {
	return head->data;
}

template<class T>
T* DoublyLinkedList<T>::peekBack() {
	return back->data;

}

template<class T>
unsigned int DoublyLinkedList<T>::getSize() {
	return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (size == 0);
}