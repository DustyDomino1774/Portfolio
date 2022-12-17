//============================================================================
// Name        : CS20Project_BagelRecursions.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include "LinkedList.hpp"
#include "Bagels.hpp"
#include "utilities.hpp"
using namespace std;

void clearCIN ()
{
	cin.clear();
	cin.ignore(32768, '\n');
}


int main() {
	int menuWidth = 10;
	int menuChoice = 0;
	bool redo = true;
	int bagelCount;
	LinkedList* myBagelList = new LinkedList;
	do
	{
		cout << "Welcome to Bagel List program." << endl;
		cout << "===============================================" << endl;
		cout << "1." << setw(menuWidth) << "Enter Random Bagels" << endl;
		cout << "2." << setw(menuWidth) << "Print all Bagels" << endl;
		cout << "3." << setw(menuWidth) << "Delete all Bagels" << endl;
		cout << "4." << setw(menuWidth) << "Print Total Bagel Inventory" << endl;
		cout << "5." << setw(menuWidth) << "Find Last Node" << endl;
		cout << "6." << setw(menuWidth) << "Exit Program" << endl;
		cout << "Please enter a menu option: ";
		cin >> menuChoice;
		clearCIN();
		cout << endl;

		switch (menuChoice)
		{
		// enter random bagels
		case 1:
		{
			do
			{
				cout << "How many bagels do you want to make. (minimum 5):";
				cin >> bagelCount;
				clearCIN();
			}while(bagelCount < 5);

			for (int count = 0; count < bagelCount; count++)
			{
				Bagels* aBagel = new Bagels();
				aBagel->setFlavor(utilities::getRandomString(3,12));
				aBagel->setOnHand(utilities::getRandomInt(0, 25));
				aBagel->setCost(utilities::getRandomDouble(0, 15, 2));
				aBagel->setPrice(utilities::getRandomDouble(0, 20, 2));
				myBagelList->push_back(aBagel);
			}

			break;
		}
		// print all bagels
		case 2:
		{
			myBagelList->PrintListR(myBagelList->getHead());
			break;
		}
		// delete all bagels
		case 3:
		{
			myBagelList->delete_list();
			break;
		}
		// print total bagel inventory
		case 4:
		{
			cout << myBagelList->CountInventory(myBagelList->getHead()) << endl;
			cout << endl;
			break;
		}
		// find last node
		case 5:
		{
			ListNode* tempNode = myBagelList->FindLastNode(myBagelList->getHead());
			cout << setw(menuWidth) << "Bagel Flavor" << setw(menuWidth) << "Bagel Cost" << setw(menuWidth) << "Bagel Price" << setw(menuWidth) << "Bagels On Hand" << endl;
			cout << setw(menuWidth) << "------------" << setw(menuWidth) << "----------" << setw(menuWidth) << "-----------" << setw(menuWidth) << "--------------" << endl;
			cout << setw(menuWidth) << tempNode->data->getFlavor() << setw(menuWidth) << tempNode->data->getCost() << setw(menuWidth) << tempNode->data->getPrice() << setw(menuWidth) << tempNode->data->getOnHand() << endl;
			cout << endl;

			break;
		}
		// exit program
		case 6:
		{
			cout << "Exiting program" << endl;
			redo = false;
			break;
		}

		// default
		default :
		{
			cout << "Invalid input please enter a number 1-6 according to the menu." << endl;
			cout << endl;
		}
		}

	}while(redo == true);

	cout << "End of Program." << endl; // prints End of Program.
	return 0;
}
