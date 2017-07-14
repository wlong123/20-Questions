#include <iostream>
#include <string>
#include "binarytree.cpp"

using namespace std;

//main method. must return 0 at end. This is where I did all of my testing
int main(){
	binarytree<int>* t1 = new binarytree<int>(1);
	binarytree<int>* t2 = new binarytree<int>(2);
	binarytree<int>* t3 = new binarytree<int>(3);
	binarytree<int>* t4 = new binarytree<int>(3);
	binarytree<int>* t5 = new binarytree<int>(3);
	binarytree<int>* t6 = new binarytree<int>(3);
	binarytree<int>* t7 = new binarytree<int>(3);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2-> right = new binarytree<int>(3);
	t4-> left = t5;
	t4-> right = new binarytree<int>(3);
	t5-> right = t6;
	t6-> right = t7;

	cout << t1->size() << endl;
	cout << t5->height() << endl;
	cout << t1->height() << endl;
	
	binarytree<int>* t11 = new binarytree<int>(30);
	binarytree<int>* t12 = new binarytree<int>(3);
	binarytree<int>* t10 = new binarytree<int>(3, t11, t12);
	binarytree<int>* t13 = new binarytree<int>(30);
	binarytree<int>* t14 = new binarytree<int>(3);
	binarytree<int>* t15 = new binarytree<int>(30);
	binarytree<int>* t16 = new binarytree<int>(3);
	cout << t10->left->value << endl;
	t11-> right = t13;
	t13-> left = t14;
	t14-> right = t15;
	t12-> left = t16; 
	cout << t10-> height() << endl;
	
	t10-> printinorder();
	cout << endl;
	t1-> printinorder();
	cout << endl;
	cout << endl;
	t1-> printpreorder();
	cout << endl;
	t1-> printpostorder();
	cout << endl;
	
	cout << "\nISFULL" << endl;
	binarytree<int>* t21 = new binarytree<int>(30);
	binarytree<int>* t22 = new binarytree<int>(3);
	binarytree<int>* t20 = new binarytree<int>(3, t21, t22);
	
	cout << t20->isFull() << endl;
	cout << t1->isFull() << endl;
	cout << "\nISCOMPLETE" << endl;
	cout << t20->isComplete() << endl;
	cout << t1->isComplete() << endl;
	
	cout << "\nISBALANCED" << endl;
	cout << t20->isBalanced() << endl;
	cout << t1->isBalanced() << endl;
	
	cout << "\nSTRINGTREE" << endl;
	binarytree<string>* s1 = new binarytree<string>("left");
	binarytree<string>* s2 = new binarytree<string>("right");
	binarytree<string>* s3 = new binarytree<string>("middle",s1,s2);
	s3-> printinorder();
	cout << endl;
	s3-> printpreorder();
	cout << endl;
	s3-> printpostorder();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	binarytree<string>* test3 = new binarytree<string>("third");
	binarytree<string>* test2 = new binarytree<string>("second");
	binarytree<string>* test = new binarytree<string>("first",test2,test3);
	test2->left = new binarytree<string>("fourth");
	test2->right = new binarytree<string>("fifth");
	test3->left = new binarytree<string>("sixth");
	test3->right = new binarytree<string>("seventh");
	test-> printinorder();
	cout << endl;
	test-> printpreorder();
	cout << endl;
	test-> printpostorder();
	cout << endl;
	test-> print();
	cout << endl;
	
	binarytree<string>* tree2 = new binarytree<string>("It it in your home?");
	binarytree<string>* tree3 = new binarytree<string>("Is it a pet?");
	binarytree<string>* tree = new binarytree<string>("Is it alive?",tree2,tree3);
	binarytree<string>* tree4 = new binarytree<string>("Is it a school?");
	binarytree<string>* tree5 = new binarytree<string>("Is it a computer");
	binarytree<string>* tree6 = new binarytree<string>("It is a lion?");
	binarytree<string>* tree7 = new binarytree<string>("Is it a dog?");
	tree2-> left = tree4;
	tree2-> right = tree5;
	tree3-> left = tree6;
	tree3-> right = tree7;
	tree-> print();
	cout << endl;
	string y = tree-> convert();
	cout << y << endl;
	
	return 0;
}
