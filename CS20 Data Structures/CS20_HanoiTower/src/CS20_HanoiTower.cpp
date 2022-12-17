//============================================================================
// Name        : CS20_HanoiTower.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void moveDisc(int, int[], int[], int[]);
void printTowers();

int fromPeg[3] = {3,2,1};
int toPeg[3] = {0};
int tempPeg[3] = {0};
const int arraySize = 3;
// Fix the print function

int main()
{

	moveDisc(arraySize, fromPeg, toPeg, tempPeg);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;


}

void moveDisc(int num, int  fromPeg[], int toPeg[3], int tempPeg[3])
{
	printTowers();
	if (num > 0)
	{
		moveDisc(num-1, fromPeg, toPeg, tempPeg);
		int count = 2;
		while(true)
		{
			if (fromPeg[count] == 0)
			{
				count--;
				continue;
			}//if
			else
			{
				break;
			}//else
		}//while

		int ctr = 0;
		while(true)
		{
			if (toPeg[ctr] == 0)
			{
				break;
			}//if
			else
			{
				ctr++;
				continue;
			}//else
		}//while
		toPeg[ctr] = fromPeg[count];
		moveDisc(num-1,tempPeg, toPeg, fromPeg);
	}//if
	else
	{
		return;
	}//else
}

void printTowers()
{
	cout << setw(8) << "From" << setw(8) << "To" << setw(8) <<"Temp" << endl;
			for (int ctr = 0; ctr < arraySize; ctr++)
			{
				fromPeg[ctr] << setw(8) << toPeg[ctr] << setw(8) << tempPeg[ctr];
			}
}
