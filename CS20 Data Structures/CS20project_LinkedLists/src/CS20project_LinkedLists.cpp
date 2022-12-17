//============================================================================
// Name        : CS20project_LinkedLists.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
	LinkedList myList;
	try {
		cout << "First value is: " << myList.first() << endl;
	}//try
	catch (const char* e) {
		cout << e << endl;
	}//catch
	cout << "Inserting five values at the back of the list" << endl;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);
	myList.print_list();
	cout << endl << "Inserting five values at the front of the list" << endl;
	myList.push_front(5);
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
	myList.print_list();

	cout << endl << "Getting the first value in the list" << endl;
	try {
		cout << "First value is: " << myList.first() << endl;
	}//try
	catch (const char* e) {
		cout << e << endl;
	}//catch
	cout << endl << "Getting the last value in the list" << endl;
	try {
		cout << "Last value is: " << myList.last() << endl;
	}//try
	catch (const char* e) {
		cout << e << endl;
	}//catch

	cout << endl << "Testing the getAt function" << endl;
	cout << "Item at position 0 is: " << myList.getAt(0) << endl;
	cout << "Item at position 5 is: " << myList.getAt(5) << endl;
	cout << "Item at position 9 is: " << myList.getAt(9) << endl;
	try {
		cout << "Item at position 22 is: " << myList.getAt(22); }//try
	catch (const char* e) {
		cout << e << endl;
	}//catch

	cout << endl << "Inserting, sorted, six values" << endl;
	myList.insertSorted(120);
	myList.insertSorted(43);
	myList.insertSorted(-10);
	myList.insertSorted(-30);
	myList.insertSorted(120);
	myList.insertSorted(130);
	myList.print_list();

	cout << endl << "Deleting the node at position 0" << endl;
	myList.deleteAt(0);
	myList.print_list();

	cout << endl << "Trying to deleteAt a node past the end of the list" << endl;
	try {
		myList.deleteAt(myList.size());
	}//tru
	catch (const char* e) {
		cout << e << endl;
	}//catch

	cout << endl << "Trying to deleteAt the node at end of the list" << endl;
	myList.deleteAt(myList.size()-1);
	myList.print_list();

	cout << endl << "Trying to deleteAt a node in the middle of the list" << endl;
	myList.deleteAt((myList.size()-1)/2);
	myList.print_list();

	cout << endl << "Testing insertAt function before position 0 with value of 5000" << endl;
	myList.insertAt(5000, 0);
	myList.print_list();
	cout << endl << "Testing insertAt funciton before the last position with value of 5000" << endl;
	myList.insertAt(5000, myList.size()-1);
	myList.print_list();
	cout << endl << "Testing a for loop with overided [] operator" << endl;
	for (int i=0; i<myList.size(); i++) {
		cout << myList[i] << endl;
	}//for

	cout << endl << "Testing pop_front in a for loop to clear out the list" << endl;
	int theSize = myList.size();
	for (int i=0; i<theSize; i++) {
		cout << "Deleting: " << myList.first() << endl;
		myList.pop_front();
		myList.print_list();
	}//for

	cout << endl << "Program ending, have a nice day" << endl;
	return 0;
}//main
