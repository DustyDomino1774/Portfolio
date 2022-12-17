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
private:
	string flavor;
	int onHand;
	double cost;
	double price;

public:
	Bagels();
	virtual ~Bagels();

	void setFlavor(string);
	void setOnHand(int);
	void setCost(double);
	void setPrice(double);
	string getFlavor();
	int getOnHand();
	double getCost();
	double getPrice();

};

#endif /* BAGELS_HPP_ */
