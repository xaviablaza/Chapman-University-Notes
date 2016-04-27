#include <iostream>
using namespace std;

template <class T>
class GenStack {
	public:		
		GenStack();
		~GenStack();
		void push(T d);
		T pop();
		T peek();
		bool isEmpty();
	private:
		T *stack;
};

template <class T>
GenStack<T>::GenStack() {
	stack = new DoublyLinkedList<T>();
}
template <class T>
GenStack<T>::~GenStack() {
	delete stack;
}
template <class T>
void GenStack<T>::push(T d){
	stack->insertFront(d);
}
template <class T>
T GenStack<T>::pop() {
	return stack->removeFront();
}
template <class T>
T GenStack<T>::peek() {
	if (!isEmpty()) {
		return stack->peekHead();
	} else {
		cout<<"GenStack Exception: Stack is empty.";
	}
}
template <class T>
bool GenStack<T>::isEmpty(){
	return stack->isEmpty();
}