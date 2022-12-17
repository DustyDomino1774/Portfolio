//============================================================================
// Name        : CS20_Graphs.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Not today big boi
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

struct Vertex {
	string name;
	vector<Vertex*> destinations;
};

int totalVerticies (Vertex* theLinks) {
	int total = 0;
	for (int count  = 0; count < theLinks.size(); count++)
	{
		total++;
	}

	return total;
}

int main() {

	Vertex* sources[100];

	//Setup initial verticies
	Vertex *aVertex0 = new Vertex;
	aVertex0->name = "0";
	sources[0] = aVertex0;

	Vertex *aVertex1 = new Vertex;
	aVertex1->name = "1";
	sources[1] = aVertex1;

	Vertex *aVertex2 = new Vertex;
	aVertex2->name = "2";
	sources[2] = aVertex2;

	Vertex *aVertex3 = new Vertex;
	aVertex3->name = "3";
	sources[3] = aVertex3;

	Vertex *aVertex4 = new Vertex;
	aVertex4->name = "4";
	sources[4] = aVertex4;

	Vertex *aVertex5 = new Vertex;
	aVertex5->name = "5";
	sources[5] = aVertex5;

	//Setup initial edges
	sources[0]->destinations.push_back(sources[1]);
	sources[0]->destinations.push_back(sources[2]);


	sources[1]->destinations.push_back(sources[0]);
	sources[1]->destinations.push_back(sources[2]);
	sources[1]->destinations.push_back(sources[3]);

	sources[2]->destinations.push_back(sources[0]);
	sources[2]->destinations.push_back(sources[1]);
	sources[2]->destinations.push_back(sources[3]);
	sources[2]->destinations.push_back(sources[4]);

	sources[3]->destinations.push_back(sources[1]);
	sources[3]->destinations.push_back(sources[2]);
	sources[3]->destinations.push_back(sources[4]);
	sources[3]->destinations.push_back(sources[5]);

	sources[4]->destinations.push_back(sources[2]);
	sources[4]->destinations.push_back(sources[3]);
	sources[4]->destinations.push_back(sources[5]);

	sources[5]->destinations.push_back(sources[3]);
	sources[5]->destinations.push_back(sources[4]);

	// finish this print
	for (unsigned int count = 0; count < (totalVerticies); count++)
	{
		cout << "Vertex" << count << "degree is:" << sources[count]->destinations;
	}


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
