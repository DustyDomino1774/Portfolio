/*
 * Clown.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: Dominic
 */

#include "Clown.hpp"

Clown::Clown() {
	scarefactor = 0;
	noseColor = 'n';
	weight = 0;
	shoesize = 0;
	// TODO Auto-generated constructor stub

}

Clown::Clown(double aDouble)
{
	scarefactor =0;
	noseColor = 0;
	weight = 0;
	shoesize = aDouble;
}
Clown::~Clown() {
	// TODO Auto-generated destructor stub
}

bool Clown::operator<(const Clown &right) const {
	return shoesize < right.shoesize;
}//operator<

