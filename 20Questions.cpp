#include <iostream>
#include <string>
#include <fstream>
#include "binarytree.cpp"

using namespace std;

/**
	c++ user input/output: http://www.cplusplus.com/doc/tutorial/basic_io/
	c++ read text files: https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html
*/

//the tree and string copy of text file are global variables
binarytree<string>* mastertree = new binarytree<string>();
string s;

//read text from text file and returns it as a string
string readFile() {
	ifstream inFile;
	inFile.open("Saver.txt");
	if (!inFile) {
    	cerr << "Unable to open file\n";
    	exit(1);   // call system to stop
	}
	string x;
	string text;
	while (inFile >> x) {
 		text = text + x + " ";
 		//cout << x << endl;
	}
	inFile.close();
	
	return text;
}

//populates the tree with the string from the tet file
void populateTree(binarytree<string>* tree)
{
	string toAdd = "";
	if(s.length() == 0)
		return;
	if(int(s.at(0)) == 41) {
		s = s.substr(1);
		populateTree(tree);
	}
	if(int(s.at(0)) == 40) {
		s = s.substr(1);
		int i = 0;
		while((s.at(i) != '(') && (s.at(i) != ')') && (s.at(i) != ',')) {
			toAdd += s.at(i);
			i++;
		}
		tree-> left = new binarytree<string>(toAdd);
		s = s.substr(i);
		if(int(s.at(0)) == 40)
			populateTree(tree-> left);
		populateTree(tree);
	}
	
	toAdd = "";
	if(int(s.at(0)) == 44) {
		s = s.substr(1);
		int i = 0;
		while((s.at(i) != '(') && (s.at(i) != ')') && (s.at(i) != ',')) {
			toAdd += s.at(i);
			i++;
		}
		tree-> right = new binarytree<string>(toAdd);
		s = s.substr(i);
		if(int(s.at(0)) == 40)
			populateTree(tree-> right);
	}
}

//adds info to binary if it guesses incorrectly
void learn(binarytree<string>* tree) {
	string s; 
	getline (cin,s); 
	if(s == "yes")
		cout << "Thanks for playing" << endl;
	if(s == "no") {
		tree-> left = new binarytree<string>(tree-> value);
		cout << "What were you thinking of" << endl;
		getline (cin,s);
		tree-> right = new binarytree<string>(s);
		cout << "What is a question that could differentiate your answer from the one I gave?" << endl;
		getline (cin,s);
		tree-> value = s;
	}
}

//plays the games by asking questions and traversing through tree. 
bool run(binarytree<string>* tree) {
	if(tree-> isLeaf()) {
		cout << "Is it a " + tree-> value + "?" << endl;
		learn(tree);
		return true;
	}
	string s;
	cout << tree-> value << endl;
	getline (cin,s); 
	//s = tolower(s);
	if(s == "yes")
	{
		run(tree-> right);
	}
	if(s == "no")
	{
		run(tree-> left);
	}
	if((s != "yes") && (s != "no")) {
		cout << "Please enter yes or no" << endl;
		run(tree);
	}
	return true;
	
}

//When the user is done playing, the new tree is put into the text file
void save() {
	string data = mastertree-> convert();
	ofstream myfile;
	myfile.open ("Saver.txt");
  	myfile << data;
  	myfile.close();
}


int main(){
	//read the text file
	s = readFile();
	
	//adds initial value to the tree and then populates the rest of the tree
	if(s.length() > 0) {
		int i = 0;
		while(int(s.at(i)) != 40){
			i++;
		}
		string head = s.substr(0,i);
		s = s.substr(i);
		mastertree-> value = head;
	}
	populateTree(mastertree);

	//continues to play as long as the user wants to 
	bool playagain = true;
	while(playagain == true){
		cout << "Welcome to 20 Questions. Please think of an object." << endl;
		run(mastertree);
		string again;
		cout << "Would you like to play again" << endl;
		getline (cin,again);
		if(again == "no")
			playagain = false;
	}
	
	//once the user is done playing the new tree is updated into the text file
	save();
	
	return 0;
}


