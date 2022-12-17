/*
 * Bagels.hpp
 *
 *  Created on: Mar 1, 2018
 *      Author: student
 */

#ifndef BAGELS_HPP_
#define BAGELS_HPP_

#include <iostream>
using namespace std;

class Bagels {
public:
	Bagels();
	virtual ~Bagels();

	string flavor;
	int onHand;
	double cost;
	double price;

};

#endif /* BAGELS_HPP_ */
