// See: http://www.programcreek.com/2014/04/leetcode-binary-search-tree-iterator-java/
#include "GenStack.h"
template <class T>
class BSTIterator {
	public:
		BSTIterator():
		BSTIterator(TreeNode<T> *root);
		~BSTIterator();
		bool hasNext();
		T next();
	private:
		GenStack<T> *stack;
		void recursivePush(TreeNode<T> *node);
};

template <class T>
BSTIterator<T>::BSTIterator(){}

template <class T>
BSTIterator<T>::BSTIterator(TreeNode<T> *root) {
	stack = new GenStack<T>();
	recursivePush(root);
}

template <class T>
void BSTIterator<T>::recursivePush(TreeNode<T> *node) {
	if (node == NULL) return;
	recursivePush(node->left);
	stack->push(node->key);
	recursivePush(node->right);
}

template <class T>
BSTIterator<T>::~BSTIterator() {
	delete stack;
}

template <class T>
bool BSTIterator<T>::hasNext() {
	return (!stack.isEmpty());
}

template <class T>
T BSTIterator<T>::next() {
	return stack.pop();
}