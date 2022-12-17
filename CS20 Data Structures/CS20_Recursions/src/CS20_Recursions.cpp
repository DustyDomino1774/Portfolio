//============================================================================
// Name        : CS20_Recursions.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void countup10(int ctr) {
	if (ctr >= 64000) {
		return;
	} //if
	else {
		countup10(ctr++);
	} //else
} //countup10

int factorial(int num) {
	if (num > 0) {

		return num * factorial(num - 1);

	} else {
		return 1;
	}
}

int gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	} else {
		return gcd(y, x % y);
	}
}

int fib(int n) {
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}

int getRandomInt(int Min, int Max) {
	int tempInt = 0;

	while (true) {
		tempInt = rand() % Max;
		if (tempInt >= Min)
			break;
		else {
		}
	} //while

	return tempInt;
} //getRandomInt

int numFind(vector<int>& theVector, int n, int placement) {
	if (placement < theVector.size()) {
		placement++;
		if (theVector[placement] == n) {

			return numFind(theVector, n, placement) + 1;

		} else {
			return numFind(theVector, n, placement) + 1;
		}
	}
	return 0;
}

int findLargest() {

}

int main() {
	vector<int> myInts;
	//int aNum;
	for (int count = 0; count < 10000; count++) {
		myInts.push_back(getRandomInt(0, 100));
	}

	//cout << numFind(myInts, 100, 0) << endl;

//	cout << countup10(5) << endl;
//	cout << factorial(6) << endl;
//	cout << gcd(24, 36) << endl;
//	cout << fib(3) << endl;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
