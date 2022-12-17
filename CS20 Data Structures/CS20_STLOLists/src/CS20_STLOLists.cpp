//============================================================================
// Name        : CS20_STLOLists.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <map>
#include "SpaceBoats.hpp"
using namespace std;


int main()
{
	list<SpaceBoats*> myStringList;
	list<SpaceBoats*> ::iterator myStringIterator;

	SpaceBoats* aboat1 = new SpaceBoats;
	SpaceBoats* aboat2 = new SpaceBoats;
	SpaceBoats* aboat3 = new SpaceBoats;
	SpaceBoats* aboat4 = new SpaceBoats;
	SpaceBoats* aboat5 = new SpaceBoats;

	aboat1->name = "abe";
	aboat2->name = "dabe";
	aboat3->name = "gabe";
	aboat4->name = "cabe";
	aboat5->name = "labe";

	myStringList.push_back(aboat1);
	myStringList.push_back(aboat2);
	myStringList.push_back(aboat3);
	myStringList.push_back(aboat4);
	myStringList.push_back(aboat5);

	//myStringIterator = myStringList.begin();
	for (myStringIterator = myStringList.begin();
			myStringIterator != myStringList.end();
			myStringIterator++)
	{
		cout << (*myStringIterator)->name << endl;
		//	myStringIterator++;
	}
//	while (!myStringList.empty())
//	{
//		delete myStringList.front();
//		myStringList.pop_front();
//	}

	map<string, SpaceBoats*> myMap;
	pair<map<string, SpaceBoats*>::iterator, bool>ret;

	ret = myMap.insert(pair<string, SpaceBoats*>
	("a", aboat1->name));
	ret = myMap.insert(pair<string, SpaceBoats*>
		("b", aboat2->name));
	ret = myMap.insert(pair<string, SpaceBoats*>
		("c", aboat3->name));
	ret = myMap.insert(pair<string, SpaceBoats*>
		("d", aboat4->name));
	ret = myMap.insert(pair<string, SpaceBoats*>
		("e", aboat5->name));
	map<string, Spaceboats*>::iterator iter;
	for (iter = myMap.begin();
			iter != myMap.end();
				iter++)
	{
		iter = myMap.find("a");
		if (iter != myMap.end())
		{
			cout << "Boat: " << myMap["a"]->name << "exists" << endl;
		}
		else
		{
			cout << "Employee with key: " << "a" << "does not exist" << endl;
		}
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
