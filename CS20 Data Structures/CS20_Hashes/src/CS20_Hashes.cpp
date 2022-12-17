//============================================================================
// Name        : CS20_Hashes.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Not today big boi
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <cmath>
#include "utilities.hpp"

using namespace std;

struct keyPair{
	int key;
	string data;
};

int hashTableSize = 1000000;
int hashSample = 1000;

int hashSum(string);

int main()
{
	vector<keyPair> hashTable[hashTableSize];


	for ( int count = 0; count < hashSample; count++)
	{
		keyPair aKeyPair;
		aKeyPair.data = utilities::getRandomString(5, 20);
		aKeyPair.key = hashSum(aKeyPair.data);
		hashTable [aKeyPair.key].push_back(aKeyPair);
	}

	for ( int count = 0; count < hashTableSize; count++)
		{
			if (hashTable[count].size() > 0)
			{
				cout << endl << "At position " << count << " the following keys are stored: " << endl;
				for (unsigned int count1 = 0; count1 < hashTable[count].size(); count1++)
				{
					cout << "\t " << hashTable[count].at(count1).data << ", ";
				}
			}
		}
	cout << endl;

	int crashCount = 0;

	for ( int count = 0; count < hashTableSize; count++)
		{
			if (hashTable[count].size() > 0)
			{
				crashCount++;
			}
			else
			{}
		}
	cout << "You have " << crashCount << " crashes" << endl;




	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

int hashSum(string theString)
{
	int sum = 0;

	for (unsigned int count = 0; count < theString.length(); count++)
	{

		sum += theString[count];
	}

	return sum  % hashTableSize * 31;
}
