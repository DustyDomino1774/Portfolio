//============================================================================
// Name        : CS20_STLLists.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include "MermaidZombie.hpp"
using namespace std;

bool autoCompareAscending (MermaidZombie* first, MermaidZombie* second)
{
	return (first->weight) < (second->weight);
}

int main() {

	list<MermaidZombie*> myZomList;
	list<MermaidZombie*>::iterator iter;

	MermaidZombie *zombie1 = new MermaidZombie;
	MermaidZombie *zombie2 = new MermaidZombie;
	MermaidZombie *zombie3 = new MermaidZombie;

	zombie1->flavor = "chocolate";
	zombie2->flavor = "vanilla";
	zombie3->flavor = "strawberry";

	zombie1->weight = 1060;
	zombie2->weight = 110;
	zombie3->weight = 580;

	myZomList.push_back(zombie1);
	myZomList.push_back(zombie2);
	myZomList.push_back(zombie3);


	for (iter = myZomList.begin(); iter != myZomList.end(); iter++)
	{
		cout << (*iter)->flavor << endl;
	}

	cout << endl;

	myZomList.sort(autoCompareAscending);

	for (iter = myZomList.begin(); iter != myZomList.end(); iter++)
	{
		cout << (*iter)->flavor << endl;
	}

	for (iter = myZomList.begin(); iter != myZomList.end(); iter++)
	{
		delete *iter;
	}


	myZomList.sort(autoCompareAscending);


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
