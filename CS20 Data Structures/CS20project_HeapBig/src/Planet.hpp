/*
 * Planet.hpp
 *
 *  Created on: May 1, 2018
 *      Author: Dominic
 */

#ifndef PLANET_HPP_
#define PLANET_HPP_

#include <iostream>
using namespace std;

class Planet {
public:
	int Key;
	string url;
	string Name;

	Planet();
	virtual ~Planet();
};

#endif /* PLANET_HPP_ */
