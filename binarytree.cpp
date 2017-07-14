#include <iostream>
#include <string>
#include <sstream>
#include "binarytree.h"
using namespace std;


/*
	This is the binary tree class where the methods are implemented
	
	Resources:
	https://www.tutorialspoint.com/cplusplus/
	-look through all the pages on this site to get an overview of C++ syntax
*/

/*
	size method for binary tree
*/
template <class T>
int binarytree<T>::size(){
	int count = 1;
	if (left != NULL)
		count += left->size();
	if (right != NULL)
		count += right->size();
	return count;
}

/*
	is Leaf method for binary tree. Returns 0 for false and 1 for true
*/
template <class T>
bool binarytree<T>::isLeaf(){
	return (left == NULL) && (right == NULL);
}

/*
	returns the height of the tree
*/
template <class T>
int binarytree<T>::height(){
	int l = 0;
	int r = 0;
	if(isLeaf()) {
		if(l > r)
			return l + 1;
		return r + 1;	
	}
	if((left != NULL) && (right != NULL)) {
		l += 1 + left->height();
		r += 1 + right->height();
	}
	else if(right != NULL) {
		return 1 + r + right->height();
	}
	else if(left != NULL) {
		return 1 + l + left->height();
	}
	if(l > r)
		return l;
	return r;	
}

/*
	prints out an in order representation of the tree
*/
template <class T>
void binarytree<T>::printinorder(){
	if(isLeaf())
		cout << value;
	else if((left != NULL) && (right == NULL)) {
		left->printinorder(); 
		cout << ",";
		cout << value;
	}
	else if((right != NULL) && (left == NULL)) {
		cout << value;
		cout << ","; 
		right->printinorder();
	}
	else {
		left->printinorder();
		cout << ",";
		cout << value;
		cout << ","; 
		right->printinorder();
	}
}

/*
	prints out a pre order representation of the tree
*/
template <class T>
void binarytree<T>::printpreorder(){
	if(isLeaf())
		cout << value;
	else if((left != NULL) && (right == NULL)) {
		cout << value;
		cout << "("; 
		left->printpreorder();
		cout << ", )";
	}
	else if((right != NULL) && (left == NULL)) {
		cout << value;
		cout << "("; 
		right-> printpreorder();
		cout << ", )";
	}
	else {
		cout << value; 
		cout << "(";
		left->printpreorder(); 
		cout << ","; 
		right->printpreorder();
		cout << ")";
	}
}

//print method for tree. Calls printpreorder
template <class T>
void binarytree<T>::print(){
	printpreorder();
}

/*
	returns a string representation of the tree
*/
template <class T>
string binarytree<T>::convert(){
	string s = "";
	if(isLeaf())
		s += value;
	else if((left != NULL) && (right == NULL)) {
		s += value + "("; 
		s += left->convert();
		s += ", )";
	}
	else if((right != NULL) && (left == NULL)) {
		s += value + "("; 
		s += right-> convert();
		s += ", )";
	}
	else {
		s += value + "("; 
		s += left->convert(); 
		s += ","; 
		s += right->convert();
		s += ")";
	}
	return s;
}


/*
	prints out a post order representation of the tree
*/
template <class T>
void binarytree<T>::printpostorder(){
	if(isLeaf())
		cout << value;
	else if((left != NULL) && (right == NULL)) {
		left->printpostorder();
		cout << ",";
		cout << value;
	}
	else if((right != NULL) && (left == NULL)) {
		right-> printpostorder();
		cout << ",";
		cout << value;
	}
	else {
		left->printpostorder(); 
		cout << ","; 
		right->printpostorder();
		cout << ",";
		cout << value;
	}
}

/*
	returns whether the tree is full or not. returns 0 for false and 1 for true
*/
template <class T>
bool binarytree<T>::isFull(){
	if(isLeaf())
		return true;
	if((left == NULL) || (right == NULL))
		return false;
	return (left->isFull()) && (right->isFull()) && (right->height() == left->height());
}

/*
	returns whether the tree is complete or not. returns 0 for false and 1 for true
*/
template <class T>
bool binarytree<T>::isComplete(){
	if(isLeaf())
		return true;
	if(left == NULL)
		return false;
	if((right == NULL) && (left->isLeaf()))
		return true;
	if((left != NULL) && (right != NULL) && (left->height() - right->height() == 1))
		return (left->isComplete()) && (right->isFull());
	if((left != NULL) && (right != NULL) && (left->height() == right->height()))
		return (left->isFull()) && (right->isComplete());
	return false;
}

/*
	returns whether the tree is balanced or not. returns 0 for false and 1 for true
*/
template <class T>
bool binarytree<T>::isBalanced(){
	if(isLeaf()) 
		return true;
	if((left != NULL) && (right == NULL) && (height() <= 1))
		return true;
	if((right != NULL) && (left == NULL) && (height() <= 1))
		return true;
	if((left != NULL) && (right != NULL) && (abs(right->height() - left->height()) <= 1)) //difference between heights is less than 2
		return (left->isBalanced()) && (right->isBalanced());
	return false;
}

