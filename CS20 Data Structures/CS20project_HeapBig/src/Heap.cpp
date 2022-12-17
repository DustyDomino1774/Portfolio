/*
 * Heap.cpp
 *
 *  Created on: May 1, 2018
 *      Author: Dominic
 */

#include "Heap.hpp"
#include <vector>

Heap::Heap() {
	// TODO Auto-generated constructor stub

}

Heap::~Heap() {
	// TODO Auto-generated destructor stub
}

void Heap::insertItem(int Key, Planet* thePlanet)
{
	HeapNode aHeap;
	aHeap.first = Key;
	aHeap.second = thePlanet;
	theHeap.push_back(aHeap);
	upHeap();
}// Insert

Planet* Heap::top()
{
	return theHeap[0].second;
}// top

void Heap::pop()
{
	delete theHeap[0].second;
	downHeap();
}// pop

void Heap::setType(int anInt)
{
	if (anInt == 0)
	{
		type = "minHeap";
	}
	else if (anInt == 1)
	{
		type = "maxHeap";
	}
}// set type

void Heap::upHeap()
{
	//	int n = theHeap.size() - 1;
	//	int child = n - 1;
	//	int parent = child/2;
	if(type == "maxHeap")
	{
		int child = theHeap.size() - 1;
		int parent = child/2;

		while (theHeap[child].first > theHeap[parent].first && child >=0 && parent >= 0)
		{
			//swaping
			HeapNode temp = theHeap[parent];
			theHeap[parent] = theHeap[child];
			theHeap[child] = temp;
			// new positions
			child = parent;
			parent = child/2;

		}
		//				while (child != 0)
		//				{
		//					child = parent;
		//					parent = child /2;
		//
		//					if (theHeap[parent].first > theHeap[child].first)
		//					{
		//						HeapNode temp = theHeap[parent];
		//						theHeap[parent] = theHeap[child];
		//						theHeap[child] = temp;
		//
		//					}
		//
		//				}
//		printHeap();
	}

	else if (type == "minHeap")
	{
		int child = theHeap.size() - 1;
		int parent = child/2;
		while (theHeap[child].first < theHeap[parent].first && child >=0 && parent >= 0)
		{
			// swaping
			HeapNode temp = theHeap[parent];
			theHeap[parent] = theHeap[child];
			theHeap[child] = temp;
			// new positions
			child = parent;
			parent = child/2;

		}
		//				while (theHeap[parent].first < theHeap[child].first && parent > 0)
		//				{
		//					HeapNode temp = theHeap[parent];
		//					theHeap[parent] = theHeap[child];
		//					theHeap[child] = temp;
		//
		//					child = parent;
		//					parent = child /2;
		//				}
//		printHeap();
	}
	else
	{
		cout << "No action taken because no heap type specified." << endl;
	}
}// up heap


void Heap::downHeap()
{

	HeapNode temp = theHeap.front();
	theHeap.front() = theHeap.back();
	theHeap.back() = temp;
	theHeap.pop_back();


	//	unsigned int n = 0;
	//	unsigned int parent = n;
	//	unsigned int left = 2*n + 1;
	//	unsigned int right = 2*n+ 2;
	if (type == "maxHeap")
	{

		int parent = 0;

		while (true)
		{
			int left = 2*parent + 1;
			int right = 2*parent + 2;
			int length = theHeap.size();
			int largest = parent;

			if (left < length && theHeap[left].first > theHeap[largest].first)
			{
				largest = left;
			}

			if (right < length && theHeap[right].first > theHeap[largest].first)
			{
				largest = right;
			}

			if (largest != parent)
			{
				// swaping
				HeapNode temp = theHeap[parent];
				theHeap[parent] = theHeap[largest];
				theHeap[largest] = temp;
				//new position
				parent = largest;
			}
			else
			{
				break;
			}
			//		while (theHeap[left].first > theHeap[parent].first || theHeap[right].first >theHeap[parent].first )
			//		{
			//
			//			if ((theHeap[left].first < theHeap[right].first) || right > theHeap.size())
			//			{
			//				temp = theHeap[parent];
			//				theHeap[parent] = theHeap[left];
			//				theHeap[left] = temp;
			//				parent = left;
			//			}
			//			else
			//			{
			//
			//				temp = theHeap[parent];
			//				theHeap[parent] = theHeap[right];
			//				theHeap[right] = temp;
			//				parent = right;
			//			}
			//			left = 2*parent + 1;
			//			right = 2*parent+ 2;
			//			if (left > theHeap.size()-1 && theHeap.size()-1 )
			//			{
			//				break;
			//			}
			//		}
		}
	}
	else if (type == "minHeap")
	{
		int parent = 0;

		while (true)
		{
			int left = 2*parent + 1;
			int right = 2*parent + 2;
			int length = theHeap.size();
			int largest = parent;

			if (left < length && theHeap[left].first < theHeap[largest].first)
			{
				largest = left;
			}

			if (right < length && theHeap[right].first < theHeap[largest].first)
			{
				largest = right;
			}

			if (largest != parent)
			{
				// swaping
				HeapNode temp = theHeap[parent];
				theHeap[parent] = theHeap[largest];
				theHeap[largest] = temp;
				//new position
				parent = largest;
			}
			else
			{
				break;
			}

			//		while (theHeap[left].first > theHeap[parent].first || theHeap[right].first >theHeap[parent].first )
			//		{
			//
			//			if ((theHeap[left].first < theHeap[right].first) || right > theHeap.size())
			//			{
			//				temp = theHeap[parent];
			//				theHeap[parent] = theHeap[left];
			//				theHeap[left] = temp;
			//				parent = left;
			//			}
			//			else
			//			{
			//
			//				temp = theHeap[parent];
			//				theHeap[parent] = theHeap[right];
			//				theHeap[right] = temp;
			//				parent = right;
			//			}
			//			left = 2*parent + 1;
			//			right = 2*parent+ 2;
			//			if (left > theHeap.size()-1 && theHeap.size()-1 )
			//			{
			//				break;
			//			}
			//		}
		}
	}
	else
	{
		cout << "Action not done because no specificed heap type." << endl;
	}

}// down heap

int Heap::size()
{
	int theSize = 0;

	for(unsigned int count = 0; count < theHeap.size(); count++)
	{
		theSize++;
	}
	return theSize;
}

void Heap::printHeap()
{
	cout << "Current Heap." << endl;
	for (unsigned int count = 0; count < theHeap.size(); count++)
	{
		cout << theHeap[count].first << " "<< theHeap[count].second->Name <<  endl;
	}
	cout << "========================================================================================" << endl;
	cout << endl;
}
