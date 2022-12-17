/*
 * Bagels.hpp
 *
 *  Created on: Mar 1, 2018
 *      Author: student
 */

#ifndef BAGEL_HPP_
#define BAGEL_HPP_

#include <iostream>
using namespace std;

class Bagel {
private:
	string flavor;
	int onHand;
	double cost;
	double price;

public:
	Bagel();
	virtual ~Bagel();

	void setFlavor(string);
	void setOnHand(int);
	void setCost(double);
	void setPrice(double);
	string getFlavor();
	int getOnHand();
	double getCost();
	double getPrice();

};

#endif /* BAGEL_HPP_ */
