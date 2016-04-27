#include "TreeNode.h"
#include "FacultyRecord.h"
#include "StudentRecord.h"
#include <fstream>
template <class T>
class BST {
	public:
		BST();
		virtual ~BST(); // why virtual

		void insert(T val);
		bool contains(T val);
		void printNode(T val);
		T find(T val);
		bool isEmpty();

		T* getMax();
		T* getMin();
		TreeNode<T>* getSuccessor(TreeNode<T> *d); // used for deleting
		bool deleteNode(T k);
		void recursivePrint(TreeNode<T> *node);
		void printTree();
		void recursiveSerialize(ofstream &o, TreeNode<T> *node);
		void writeToFile(string fileName);
		void loadFromFile(string fileName);
	protected:
		TreeNode<T> *root;
};

class FacultyTable : public BST<FacultyRecord> {
	public:
		void recRemoveStudentId(TreeNode<FacultyRecord> *node, bool &abortCmd, int id) {
			if (!abortCmd) {
				if (node == NULL) return;
				recursivePrint(node->left);
				// If faculty tree contains id prompt the user and abort
				if (node->key.containsAdviseeId(id)) {
					abortCmd = true;
					cout<<"ERROR: Faculty member has advisee with ID "<<id<<endl;
					cout<<"Remove any conflicting advisee IDs before removing a student"<<endl;
				}
				recursivePrint(node->right);
			} else return;
		}
		// returns false if command was not aborted
		bool removeStudentId(int id) {
			bool abortCmd = false;
			recRemoveStudentId(root, abortCmd, id);
			return abortCmd;
		}
};

class StudentTable : public BST<StudentRecord> {
	public:
		// any FacultyRecord specific functions
};

template <class T>
BST<T>::BST() {
	root = NULL;
}

template <class T>
BST<T>::~BST() {
	delete root;
}

template <class T>
void BST<T>::insert(T val) {
	TreeNode<T>* node = new TreeNode<T>(val);
	if (root == NULL) root = node;
	else {
		TreeNode<T> *curr = root; // start at root
		TreeNode<T> * parent;
		while (true) {
			parent = curr;
			if (val < curr->key) { // go left
				curr = curr->left;
				if (curr == NULL) { // if it's null
					parent->left = node; // insert
					break;
				}
			} else {
				curr = curr->right;
				if (curr == NULL) {
					parent->right = node;
					break;
				}
			}
		}
	}
}

template <class T>
bool BST<T>::contains(T val) {
	if (root == NULL) return false;
	else {
		TreeNode<T> *curr = root; // start at root
		while (curr->key != val) {
			if (val < curr->key) curr = curr->left;
			else curr = curr->right;
			if (curr == NULL) return false; // we didn't find it
		}
		return true;
	}
}

template <class T>
void BST<T>::printNode(T val) {
	if (root == NULL) cout<<"Node not found."<<endl;
	else {
		TreeNode<T> *curr = root; // start at root
		while (curr->key != val) {
			if (val < curr->key) curr = curr->left;
			else curr = curr->right;
			if (curr == NULL) cout<<"Node not found."<<endl; // we didn't find it
		}
		cout<<curr->key;
	}
}

template <class T>
T BST<T>::find(T val) {
	if (root == NULL) return T();
	else {
		TreeNode<T> *curr = root; // start at root
		while (curr->key != val) {
			if (val < curr->key) curr = curr->left;
			else curr = curr->right;
			if (curr == NULL) return T(); // we didn't find it
		}
		return curr->key;
	}
}

template <class T>
bool BST<T>::isEmpty() {
	return (root == NULL);
}

template <class T>
T* BST<T>::getMax() {
	TreeNode<T> *curr = root;
	if (root == NULL) return NULL;
	while (curr->right != NULL) {
		curr = curr->right(); // Move along to the right most node
	}
	return &(curr->key);
}

template <class T>
T* BST<T>::getMin() {
	TreeNode<T> *curr = root;
	if (root == NULL) return NULL;
	while (curr->left != NULL) {
		curr = curr->left(); // Move along to the left most node
	}
	return &(curr->key);
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {// d is the node to be deleted
	TreeNode<T>* sp = d;
	TreeNode<T>* successor = d;
	TreeNode<T>* curr = d->right;
	while (curr != NULL) {
		sp = successor;
		successor = curr;
		curr = curr->left;
	}
	if (successor != d->right) {
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}

template <class T>
bool BST<T>::deleteNode(T k) {
	if (root == NULL) // empty tree
		return false;
	TreeNode<T> *curr = root;
	TreeNode<T> *parent = root;
	bool isLeft = true;
	while ((curr->key) != k) { // search for node to be removed
		parent = curr;
		if (k<curr->key) {
			isLeft = true;
			curr = curr->left;
		} else {
			isLeft = false;
			curr = curr->right;
		}
		if (curr == NULL) return false; // didn't find node
	}
	// TreeNode curr is now the node we want to delete after this line
	if (curr->left == NULL && curr->right == NULL) { //If leaf node; no children
		if (curr == root) root = NULL; // delete root
		else if (isLeft) parent->left = NULL;
		else parent->right = NULL;
	} else if (curr->right == NULL) { // If curr only has a left node
		if (curr == root) root = curr->left;
		else if (isLeft) parent->left = curr->left;
		else parent->right = curr->left;
	} else if (curr->left == NULL) { // If curr only has a right node
		if (curr == root) root = curr->right;
		else if (isLeft) parent->left = curr->right;
		else parent->right = curr->right;
	} else { // If curr has both a left and right node
		TreeNode<T> *succ = getSuccessor(curr);
		// Link parent of curr to successor
		if (curr == parent) {
			curr = parent->left;
			succ->left = curr;
			root = succ;
		} else {
			if (isLeft) parent->left = succ; // check if node to be deleted is left of parent
			else parent->right = succ; // check if node to be deleted is right of parent
			succ->left = curr->left; // link successor to curr's left child
		}
	}
}

template <class T>
void BST<T>::recursivePrint(TreeNode<T> *node) {
	if (node == NULL) return;
	recursivePrint(node->left);
	cout<<node->key<<endl;
	recursivePrint(node->right);
}

template <class T>
void BST<T>::printTree() {
	recursivePrint(root);
}

template <class T>
void BST<T>::recursiveSerialize(ofstream &o, TreeNode<T> *node) {
	if (node == NULL) return;
	o<<node->key.serialize()<<"\n";
	recursiveSerialize(o, node->left);
	recursiveSerialize(o, node->right);
}

template <class T>
void BST<T>::writeToFile(string fileName) {
	ofstream o;
	o.open(fileName.c_str(), ofstream::out | ofstream::trunc);
	recursiveSerialize(o, root);
	o.close();
}

template <class T>
void BST<T>::loadFromFile(string fileName) {
	ifstream f;
	f.open(fileName.c_str());
	string line;
	while (getline(f, line)) {
		T node = T(line);
		insert(node);
	}
	f.close();
}