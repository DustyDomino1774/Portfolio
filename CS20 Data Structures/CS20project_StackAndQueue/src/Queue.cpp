/*
 * Queue.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: Dominic
 */

#include "Queue.hpp"

Queue::Queue() {
	// TODO Auto-generated constructor stub

}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

void Queue::enqueue(Bagel* aBagel)
{
	push_back(aBagel);
}

void Queue::dequeue()
{
	pop_front();
}

Bagel* Queue::top()
{
	return first();
}

