/*
 * Employee.hpp
 *
 *  Created on: Mar 8, 2018
 *      Author: student
 */

#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <iostream>
using namespace std;

class Employee {
public:
	int ID;
	string name;
	Employee();
	virtual ~Employee();
};

#endif /* EMPLOYEE_HPP_ */
