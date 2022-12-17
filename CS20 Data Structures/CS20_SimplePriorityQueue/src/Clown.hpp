/*
 * Clown.hpp
 *
 *  Created on: Apr 24, 2018
 *      Author: Dominic
 */

#ifndef CLOWN_HPP_
#define CLOWN_HPP_

class Clown {
public:
	Clown();
	Clown(double);
	virtual ~Clown();
	bool operator<(const Clown &right) const;

	int scarefactor;
	char noseColor;
	double weight;
	double shoesize;
};

#endif /* CLOWN_HPP_ */
