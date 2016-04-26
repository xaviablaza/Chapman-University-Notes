#include <iostream>
using namespace std;
template <class ElementType>
class GenStack {
	public:
		int ptr;
		ElementType *stack;
		int size;

		GenStack();
		~GenStack();
		GenStack(int _size);
		void extend(int newSize);
		bool push(ElementType elementType);
		ElementType pop();
		ElementType peek();
		bool isEmpty();
		bool isFull();
};

template <class ElementType>
GenStack<ElementType>::GenStack() {
	ptr = -1;
	size = 10;
	stack = new ElementType[10];
}
template <class ElementType>
GenStack<ElementType>::~GenStack() {
	delete [] stack;
}
template <class ElementType>
GenStack<ElementType>::GenStack(int _size) {
	ptr = -1;
	size = _size;
	stack = new ElementType[size];
}
template <class ElementType>
void GenStack<ElementType>::extend(int newSize) {
	ElementType *_stack;
	_stack = new ElementType[newSize];
	for (int i=0; i<size; ++i) {
		_stack[i] = stack[i];
	}
	size = newSize;
	delete stack;
	stack = _stack;
}
template <class ElementType>
bool GenStack<ElementType>::push(ElementType elementType){
	if (!isFull()) {
		stack[++ptr] = elementType;
		return true;
	}
	return false;
}
template <class ElementType>
ElementType GenStack<ElementType>::pop() {
	if (!isEmpty()) {
		return stack[ptr--];
	} else {
		cout<<"GenStack Exception: Stack is empty.";
	}
}
template <class ElementType>
ElementType GenStack<ElementType>::peek() {
	if (!isEmpty()) {
		return stack[ptr];
	} else {
		cout<<"GenStack Exception: Stack is empty.";
	}
}
template <class ElementType>
bool GenStack<ElementType>::isEmpty(){
	return ptr == -1;
}
template <class ElementType>
bool GenStack<ElementType>::isFull(){
	return ptr+1 == size;
}
