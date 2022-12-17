//============================================================================
// Name        : CS20_Exceptions.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ErrorClass.hpp"
using namespace std;

int picANumber(int);

int main()
{
	// Not finished
	//===========================
	int aVar;
	while (true)
	{
	try
	{
		picANumber(aVar);
		break;
	}
	catch (const ErrorClass theError)
	{
		cout << "Error selecting a value" << endl;
		cout << theError.ErrorMsg << endl;
		continue;
	}
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

int picANumber(int theNumber)
{
	if (theNumber < 1 || theNumber > 5)
	{
		ErrorClass theError;
		theError.ErrorCode = 999;
		theError.ErrorMsg = "Error is not in the correct range.";
		theError.ErrorInFunction = "picANumber";
	}

	return theNumber;
}
