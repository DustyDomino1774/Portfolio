/*
 * Queue.hpp
 *
 *  Created on: Mar 13, 2018
 *      Author: Dominic
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "LinkedList.hpp"

class Queue: public LinkedList {
public:
	void enqueue(Bagel*);
	void dequeue();
	Bagel* top();
	Queue();
	virtual ~Queue();
};

#endif /* QUEUE_HPP_ */
