/*
 * Stack.hpp
 *
 *  Created on: Mar 13, 2018
 *      Author: Dominic
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "LinkedList.hpp"
using namespace std;


class Stack: public LinkedList {
public:
	void push(Bagel*);
	void pop();
	Bagel* top();

	Stack();
	virtual ~Stack();
};

#endif /* STACK_HPP_ */
