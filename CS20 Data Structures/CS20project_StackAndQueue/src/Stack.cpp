/*
 * Stack.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: Dominic
 */

#include "Stack.hpp"

Stack::Stack() {
	// TODO Auto-generated constructor stub

}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

void Stack::push(Bagel* aBagel)
{
	push_back(aBagel);
}

void Stack::pop()
{
	pop_back();
}

Bagel* Stack::top()
{
	return last();
}


