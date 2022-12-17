/*
 * ErrorClass.hpp
 *
 *  Created on: Feb 1, 2018
 *      Author: student
 */

#ifndef ERRORCLASS_HPP_
#define ERRORCLASS_HPP_

#include <string>
using namespace std;

class ErrorClass {
public:
	ErrorClass();
	virtual ~ErrorClass();

	int ErrorCode;
	string ErrorInFunction;
	string ErrorMsg = "Error is not in the correct range";
};

#endif /* ERRORCLASS_HPP_ */
