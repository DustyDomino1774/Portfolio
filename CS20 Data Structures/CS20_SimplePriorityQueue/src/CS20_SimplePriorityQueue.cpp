//============================================================================
// Name        : CS20_SimplePriorityQueue.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Not today big boi
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include "Clown.hpp"
//#include <>
using namespace std;

int main() {

	priority_queue<Clown> ClownCar;
	priority_queue<pair<double,Clown*>> clownSUV;

	priority_queue<pair<double, Clown*>,
	vector<pair<double, Clown*>>,
	greater<pair<double,Clown*>>> clownCarrier;

	double tempDouble = 0;
	double tempDouble2 = 0;

	cout << "Part 1" << endl;
	cout << endl;
	for (int count = 0; count < 5; count++)
	{
		cin >> tempDouble;
		ClownCar.emplace(tempDouble);

	}

	cout << "Part 2" << endl;
	cout << endl;
	while(tempDouble2 != -999)
	{
		cin >> tempDouble2;
		if (tempDouble2 != -999)
		{
			Clown* aClown = new Clown(tempDouble2);
			clownSUV.push(make_pair(aClown->shoesize, aClown));
		}
	}

	cout << "Part 3" << endl;
	cout << endl;
	while(tempDouble2 != -999)
	{
		cin >> tempDouble2;
		if (tempDouble2 != -999)
		{
			Clown* aClown = new Clown(tempDouble2);
			clownCarrier.push(make_pair(aClown->shoesize, aClown));
		}
	}

	cout << "Printing 1." << endl;
	while (!ClownCar.empty())
	{
		Clown aclown = ClownCar.top();
		aclown = ClownCar.top();
		cout << aclown.shoesize << endl;
		ClownCar.pop();
	}//while
	cout << endl;

	cout << "Printing 2." << endl;
	while(clownSUV.size() > 0)
	{
		cout << clownSUV.top().second->shoesize << endl;
		delete clownSUV.top().second;
		clownSUV.pop();
	}//while
	cout << endl;

	cout << "Printing 3." << endl;
	while(clownSUV.size() > 0)
	{
		cout << clownSUV.top().second->shoesize << endl;
		delete clownSUV.top().second;
		clownSUV.pop();
	}//while
	cout << endl;

	cout << "End of Program." << endl; // prints !!!Hello World!!!
	return 0;
}
