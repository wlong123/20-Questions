#include <iostream>
#include <string>


using namespace std;


/*
	this is the .h file for binary tree. it is essentially an interface for binary tree 
	that will allow you to use your binary tree in other programs
	
	this is the structure with all of the methods for the binary tree class. The struct 
	is essentially an abstract class where you can declare methods and implement them if
	you want to. In this struct the constructors are implemented and all of the other
	methods are abstract. The rest of the methods are implemented in binarytree1.cpp
*/
template <class T>  //this must be put at the top of every method to use generics
struct binarytree{
		struct binarytree<T>* left; //the * makes this field a pointer
		struct binarytree<T>* right;
		T value;
	
	/* default constructor */	
	binarytree () {
		left = NULL;
		right = NULL;
	}
	
	/*
		constructor that only takes in a generice value
	*/
	binarytree (T v) {
		left = NULL;
		right = NULL;
		value = v;
	}
	
	/*
		constructor that takes in a generic value and a left and right branch
	*/
	binarytree (T v, binarytree<T>* l, binarytree<T>* r) {
		value = v;
		left = l;
		right = r;
	}
	
	//methods that are declared as abstract
	int size();
	int height();
	bool isLeaf();
	void printinorder();
	void printpreorder();
	void printpostorder();
	void print();
	bool isFull();
	bool isComplete();
	bool isBalanced();
	string convert();
};
