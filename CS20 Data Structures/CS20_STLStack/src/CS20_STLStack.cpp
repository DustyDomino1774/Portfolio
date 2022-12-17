//============================================================================
// Name        : CS20_STLStack.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include "Bagels.hpp"
using namespace std;

int main()
{

	stack<Bagels*> bagelStack;
	queue<Bagels*> bagelQue;
	//	stack<char, vector<char> > charVStack;
	//	stack<char, list<char> > charLStack;

	Bagels* aBagel = new Bagels;
	Bagels* aBagel2 = new Bagels;
	Bagels* aBagel3 = new Bagels;

	Bagels* aBagel4 = new Bagels;
	Bagels* aBagel5 = new Bagels;
	Bagels* aBagel6 = new Bagels;

	aBagel->flavor = "vanilla";
	aBagel->onHand = 0;
	aBagel->price = 0;
	aBagel->cost = 0;

	aBagel2->flavor = "strawberry";
	aBagel2->onHand = 1;
	aBagel2->price = 1;
	aBagel2->cost = 1;

	aBagel3->flavor = "chocolate";
	aBagel3->onHand = 2;
	aBagel3->price = 2;
	aBagel3->cost = 2;

	aBagel4->flavor = "mango";
	aBagel4->onHand = 0;
	aBagel4->price = 0;
	aBagel4->cost = 0;

	aBagel5->flavor = "berry";
	aBagel5->onHand = 1;
	aBagel5->price = 1;
	aBagel5->cost = 1;

	aBagel6->flavor = "cherry";
	aBagel6->onHand = 2;
	aBagel6->price = 2;
	aBagel6->cost = 2;

	bagelStack.push(aBagel);
	bagelStack.push(aBagel2);
	bagelStack.push(aBagel3);

	bagelQue.push(aBagel4);
	bagelQue.push(aBagel5);
	bagelQue.push(aBagel6);

	Bagels* temp;

	while (!bagelStack.empty())
	{
		temp = bagelStack.top();
		cout <<  temp->flavor << endl;
		bagelStack.pop();
		delete temp;
	}//while

	cout << endl;

	while (!bagelQue.empty())
	{
		temp = bagelQue.front();
		cout <<  temp->flavor << endl;
		bagelQue.pop();
		delete temp;
	}//while


	cout << "Program ending, have a nice day." << endl; // prints !!!Hello World!!!
	return 0;
}
