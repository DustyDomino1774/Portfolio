/*
 * Bagel.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Dominic
 */

#include "Bagel.hpp"

Bagel::Bagel() {
	// TODO Auto-generated constructor stub

	flavor = "None";
	cost = 0.00;
	price = 0.00;
	onHand = 0;
}

Bagel::~Bagel() {
	cout << "dead bagel" << endl;
	// TODO Auto-generated destructor stub
}

void Bagel::setFlavor(string aString)
{
	flavor = aString;
}
void Bagel::setOnHand(int anInt)
{
	onHand = anInt;
}
void Bagel::setCost(double aDouble)
{
	cost = aDouble;
}
void Bagel::setPrice(double aDouble)
{
	price = aDouble;
}
string Bagel::getFlavor()
{
	return flavor;
}
int Bagel::getOnHand()
{
	return onHand;
}
double Bagel::getCost()
{
	return cost;
}
double Bagel::getPrice()
{
	return price;
}
