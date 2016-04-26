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
