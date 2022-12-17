/*
 * Heap.hpp
 *
 *  Created on: May 1, 2018
 *      Author: Dominic
 */

#ifndef HEAP_HPP_
#define HEAP_HPP_

#include "Planet.hpp"
#include <vector>
using namespace std;

struct HeapNode
{
	int first;
	Planet* second;
};

class Heap {
private:
	void upHeap();
	void downHeap();
	string type;
	vector <HeapNode> theHeap;

public:
	void insertItem(int, Planet*);
	Planet* top();
	void pop();

	int size();
	void printHeap();//delete this too

	void setType(int); //0 = minHeap, 1 = maxHeap

	Heap();
	virtual ~Heap();
};

#endif /* HEAP_HPP_ */
