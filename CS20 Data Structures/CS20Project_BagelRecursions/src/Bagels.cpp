/*
 * Bagels.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Dominic
 */

#include "Bagels.hpp"

Bagels::Bagels() {
	// TODO Auto-generated constructor stub

	flavor = "None";
	cost = 0.00;
	price = 0.00;
	onHand = 0;
}

Bagels::~Bagels() {
	// TODO Auto-generated destructor stub
}

void Bagels::setFlavor(string aString)
{
	flavor = aString;
}
void Bagels::setOnHand(int anInt)
{
	onHand = anInt;
}
void Bagels::setCost(double aDouble)
{
	cost = aDouble;
}
void Bagels::setPrice(double aDouble)
{
	price = aDouble;
}
string Bagels::getFlavor()
{
	return flavor;
}
int Bagels::getOnHand()
{
	return onHand;
}
double Bagels::getCost()
{
	return cost;
}
double Bagels::getPrice()
{
	return price;
}
