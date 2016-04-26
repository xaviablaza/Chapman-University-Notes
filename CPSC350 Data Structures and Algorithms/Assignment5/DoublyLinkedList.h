#include "ListNode.h"
#include <iostream>
using namespace std;

// Doubly linked list where a each node contains a reference
// to the next node & the previous node, but back->next != head and head->prev != back
// DoublyLinkedList of type T, ListNode holds T
template<class T>
class DoublyLinkedList {
	private:
		ListNode<T> *back;
		unsigned int size;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		ListNode<T> *head;

		// Inserts a T at the front of the list
		void insertFront(T d);
		
		// Removes and returns a T from the front of the list
		T removeFront();

		// Inserts a T at the back of the list
		void insertBack(T d);

		// Removes and returns a T from the back of the list
		T removeBack();

		// Returns, but does not remove a T from the front of the list
		T peekHead();

		// Returns, but does not remove a T from the back of the list
		T peekBack();

		bool contains(T data);

		// Gets the size of this list
		unsigned int getSize();

		// true if list is empty, false otherwise
		bool isEmpty();

		// Removes an element given its data
		bool remove(T d);
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	back = NULL;
	size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	ListNode<T> *temp = head;
	while (head->next != NULL) {
		temp = head->next;
		head->next = NULL;
		temp->prev = NULL;
		delete head;
		head = temp;
	}
}

template<class T>
void DoublyLinkedList<T>::insertFront(T d) {
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
T DoublyLinkedList<T>::removeFront() {
	ListNode<T> *temp = head;
	if (head->next == NULL) {
		back = NULL;
	} else {
		head->next->prev = NULL;
		head = head->next;
	}
	T val = temp->data;
	temp->next = NULL;
	delete temp;
	--size;
	return val;
}

template<class T>
void DoublyLinkedList<T>::insertBack(T d) {
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
T DoublyLinkedList<T>::removeBack() {
	ListNode<T> *temp = back;
	if (back->prev == NULL) {
		head = NULL;
	} else {
		back->prev->next = NULL;
		back = back->prev;
	}
	T val = temp->data;
	temp->prev = NULL;
	delete temp;
	--size;
	return val;
}

template<class T>
T DoublyLinkedList<T>::peekHead() {
	return head->data;
}

template<class T>
T DoublyLinkedList<T>::peekBack() {
	return back->data;

}

template<class T>
bool DoublyLinkedList<T>::contains(T data) {
	ListNode<T> *temp = head;
	while (temp != NULL) {
		if (temp->data == data) return true;
		else temp = temp->next;
	}
	return false;
}

template<class T>
unsigned int DoublyLinkedList<T>::getSize() {
	return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (size == 0);
}

template<class T>
bool DoublyLinkedList<T>::remove(T d) {
	ListNode<T> *node = head;
	while (node != NULL) {
		if (node->data == d) {
			// If node to remove is front node
			if (node == head) {
				removeFront();
				return true;

			// If node to remove is back node
			} else if (node == back) {
				removeBack();
				return true;

			// If node to remove has a next and prev node that are not NULL
			} else {
				node->prev->next = node->next;
				node->next->prev = node->prev;
				delete node;
				--size;
				return true;
			}
		}
		// Move onto the next node
		node = node->next;
	}
	// Didn't find node to delete
	return false;
}