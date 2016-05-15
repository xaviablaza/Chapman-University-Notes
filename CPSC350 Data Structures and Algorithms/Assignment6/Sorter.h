#include "DoublyLinkedList.h"
template <class T>
class Sorter {
	public:
		Sorter();
		~Sorter();

		// Performs quicksort on an array of type T and of length len
		void quickSort(T* S, int len);

		// Performs insertion sort on an array of type T and of length len
		void insertionSort(T* S, int len);

		// Performs odd even sort on an array of type T and of length len
		void oddEvenSort(T* S, int len);
	private:
		// Performs quicksort on a doubly linked S of type T
		void quickSort(DoublyLinkedList<T>* S);
};

template <class T>
Sorter<T>::Sorter(){}

template <class T>
Sorter<T>::~Sorter(){}

template <class T>
// See p. 519 of Data Structures and Algorithms in C++ 2nd Ed. by Goodrich, Tamassia, and Mount
void Sorter<T>::quickSort(T* S, int len) {
	// Check if the array is already sorted
	if (len <= 1) return;

	// The pivot
	T pivot = S[len-1];

	// Empty S-based sequences
	DoublyLinkedList<T> *L = new DoublyLinkedList<T>();
	DoublyLinkedList<T> *E = new DoublyLinkedList<T>();
	DoublyLinkedList<T> *G = new DoublyLinkedList<T>();

	// Loops through S backwards, dividing it into L, E, and G
	for (int i=len-1; i>=0; --i) {
		if (S[i] < pivot) {
			L->insertBack(S[i]);
		} else if (S[i] == pivot) {
			E->insertBack(S[i]);
		} else { // the last element in S is greater than pivot
			G->insertBack(S[i]);
		}
	}
	quickSort(L); // recur on the elements less than pivot
	quickSort(G); // recur on the elements greater than p
	int ptr = 0;
	while (!L->isEmpty()) {
		S[ptr] = L->removeFront();
		++ptr;
	}
	while (!E->isEmpty()) {
		S[ptr] = E->removeFront();
		++ptr;
	}
	while (!G->isEmpty()) {
		S[ptr] = G->removeFront();
		++ptr;
	}
	delete L;
	delete E;
	delete G;
	// S is now in sorted order
}

template <class T>
void Sorter<T>::quickSort(DoublyLinkedList<T>* S) {
	// Check if S is already sorted
	if (S->getSize() <= 1) return;

	// The pivot
	T pivot = S->peekBack();

	// Empty S-based sequences
	DoublyLinkedList<T> *L = new DoublyLinkedList<T>();
	DoublyLinkedList<T> *E = new DoublyLinkedList<T>();
	DoublyLinkedList<T> *G = new DoublyLinkedList<T>();

	// Loops through S backwards, dividing it into L, E, and G
	while (!S->isEmpty()) {
		if (S->peekBack() < pivot) {
			L->insertBack(S->removeBack());
		} else if (S->peekBack() == pivot) {
			E->insertBack(S->removeBack());
		} else { // the last element in S is greater than pivot
			G->insertBack(S->removeBack());
		}
	}
	quickSort(L); // recur on the elements less than pivot
	quickSort(G); // recur on the elements greater than pivot
	while (!L->isEmpty()) { // copy back to S the sorted elements less than pivot
		S->insertBack(L->removeFront());
	}
	while (!E->isEmpty()) {
		S->insertBack(E->removeFront());
	}
	while (!G->isEmpty()) { // copy back to S the sorted elements greater than p
		S->insertBack(G->removeFront());
	}
	// S is now in sorted order
}

template <class T>
void Sorter<T>::insertionSort(T* S, int len) {
	// since [0] is considered sorted, check from [1]
	for (int j=1; j<len; ++j) {
		int tmp = S[j];
		int k = j;
		while (k>0 && S[k-1]>=tmp) {
			S[k] = S[k-1];
			--k;
		}
		S[k] = tmp;
	}
}

template <class T>
// See: https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort
void Sorter<T>::oddEvenSort(T* S, int len) {
	for (int i=0; i<len; ++i) {
		if (i&1) {
			for (int j=2; j<len; j+=2) {
				if (S[j] < S[j-1]) {
					T temp = S[j-1];
					S[j-1] = S[j];
					S[j] = temp;
				}
			}
		} else {
			for (int j=1; j<len; j+=2) {
				if (S[j] < S[j-1]) {
					T temp = S[j-1];
					S[j-1] = S[j];
					S[j] = temp;
				}
			}
		}
	}
}