/*
//Project Name: CS20 Project Big Heap
//
//Project Description: The Description says it all
//
//Project Author: London, Dominic
//
//Is this an extra credit Project: No
//
//Date completed: 05/3/2018
//
//Operating system used: Windows
//
//IDE Used:  Eclipse
 * P.S. this project nearly broke me.
 */


#include <iostream>
#include "utilities.hpp"
#include "Heap.hpp"
#include "Planet.hpp"
using namespace std;

int main() {

	Heap theHeap;

	Planet* Mercury =  new Planet();
	Planet* Venus =  new Planet();
	Planet* Earth =  new Planet();
	Planet* Mars =  new Planet();
	Planet* Jupiter =  new Planet();
	Planet* Saturn =  new Planet();
	Planet* Uranus =  new Planet();
	Planet* Neptune =  new Planet();
	Planet* Pluto =  new Planet();

//	theHeap.setType(0);            		//Min Heap
	theHeap.setType(1);                //Max Heap


	Mercury->Name = "Mercury";
	Mercury->Key = utilities::getRandomInt(1, 1000);
	Mercury->url = "https://upload.wikimedia.org/wikipedia/commons/d/d9/Mercury_in_color_-_Prockter07-edit1.jpg";
	theHeap.insertItem(Mercury->Key, Mercury);
	theHeap.printHeap();

	Venus->Name = "Venus";
	Venus->url = "https://images.interactives.dk/files/bonnier-ill/pictures/venus.png?auto=compress&ch=Width%2CDPR&ixjsv=2.2.4&rect=13%2C0%2C723%2C500&w=750";
	Venus->Key = utilities::getRandomInt(1, 1000);
	theHeap.insertItem(Venus->Key, Venus);
	theHeap.printHeap();

	Earth->Name = "Earth";
	Earth->url = "https://www.nasa.gov/centers/goddard/images/content/638831main_globe_east_2048.jpg";
	Earth->Key = utilities::getRandomInt(1, 1000);
	theHeap.insertItem(Earth->Key, Earth);
	theHeap.printHeap();

	Mars->Name = "Mars";
	Mars->Key = utilities::getRandomInt(1, 1000);
	Mars->url = "https://upload.wikimedia.org/wikipedia/commons/0/02/OSIRIS_Mars_true_color.jpg";
	theHeap.insertItem(Mars->Key, Mars);
	theHeap.printHeap();

	Jupiter->Name = "Jupiter";
	Jupiter->Key = utilities::getRandomInt(1, 1000);
	Jupiter->url = "http://planetary.s3.amazonaws.com/assets/images/5-jupiter/20130121_jupiter_vgr1_c1620_sat_transits.jpg";
	theHeap.insertItem(Jupiter->Key, Jupiter);
	theHeap.printHeap();

	Saturn->Name = "Saturn";
	Saturn->Key = utilities::getRandomInt(1, 1000);
	Saturn->url = "https://solarsystem.nasa.gov/system/stellar_items/image_files/38_saturn_1600x900.jpg";
	theHeap.insertItem(Saturn->Key, Saturn);
	theHeap.printHeap();

	Uranus->Name = "Uranus";
	Uranus->Key = utilities::getRandomInt(1, 1000);
	Uranus->url = "https://upload.wikimedia.org/wikipedia/commons/3/3d/Uranus2.jpg";
	theHeap.insertItem(Uranus->Key, Uranus);
	theHeap.printHeap();

	Neptune->Name = "Neptune";
	Neptune->Key = utilities::getRandomInt(1, 1000);
	Neptune->url = "http://www.osivanacankarja.si/files/2013/12/609px-Neptune.jpg";
	theHeap.insertItem(Neptune->Key, Neptune);
	theHeap.printHeap();

	Pluto->Name = "Pluto";
	Pluto->Key = utilities::getRandomInt(1, 1000);
	Pluto->url = "http://www.daninseries.it/wp-content/uploads/2018/02/mercurio.jpg";
	theHeap.insertItem(Pluto->Key, Pluto);
	theHeap.printHeap();



	theHeap.printHeap();

	Planet* aPlanet;
	unsigned int theSize = theHeap.size();
	for (unsigned int i=0; i<theSize; i++) {
		aPlanet = theHeap.top();
		cout << "Current iterator: " << i+1 << endl;
		cout << "Being removed" << endl;
		cout <<"===================================="<< endl;
		cout << aPlanet->Key << endl;
		cout << "Name: " << aPlanet->Name << " URL: " << aPlanet->url << endl;
		cout << endl;
		theHeap.printHeap();
		theHeap.pop();
	}//for

	cout << "Program ending, have a nice day" << endl;
	return 0;
}//main
