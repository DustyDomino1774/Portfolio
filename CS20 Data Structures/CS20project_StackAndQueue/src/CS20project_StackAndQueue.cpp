//============================================================================
//============================================================================
//Project Name: CS20 Project Stack and Queue
//
//Project Description: Implementing stack and queue format of linked list
//
//Project Author: London, Dominic
//
//Is this an extra credit Project: No
//
//Date completed: 03/13/2018
//
//Operating system used: Windows
//
//IDE Used:  Eclipse
//============================================================================

#include <iostream>

#include "Bagel.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "LinkedList.hpp"
using namespace std;

int main()
{
	Bagel* aBagel1 = new Bagel();
	Bagel* aBagel2 = new Bagel();
	Bagel* aBagel3 = new Bagel();
	Bagel* aBagel4 = new Bagel();
	Bagel* aBagel5 = new Bagel();
	Bagel* aBagel6 = new Bagel();

	Stack* stackList = new Stack();
	Queue* queList = new Queue();

	aBagel1->setFlavor("Bagel1");
	aBagel1->setOnHand(3);
	aBagel1->setCost(12.35);
	aBagel1->setPrice(15.55);

	aBagel2->setFlavor("Bagel2");
	aBagel2->setOnHand(3);
	aBagel2->setCost(12.35);
	aBagel2->setPrice(15.55);

	aBagel3->setFlavor("Bagel3");
	aBagel3->setOnHand(3);
	aBagel3->setCost(12.35);
	aBagel3->setPrice(15.55);

	aBagel4->setFlavor("Fagel4");
	aBagel4->setOnHand(3);
	aBagel4->setCost(12.35);
	aBagel4->setPrice(15.55);

	aBagel5->setFlavor("Fagel5");
	aBagel5->setOnHand(3);
	aBagel5->setCost(12.35);
	aBagel5->setPrice(15.55);

	aBagel6->setFlavor("Fagel6");
	aBagel6->setOnHand(3);
	aBagel6->setCost(12.35);
	aBagel6->setPrice(15.55);

	cout << "stack push" << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	stackList->push(aBagel1);
	stackList->PrintListR(stackList->getHead());

	stackList->push(aBagel2);
	cout << "======================================================================================================" << endl;
	stackList->PrintListR(stackList->getHead());

	stackList->top();

	stackList->push(aBagel3);
	cout << "======================================================================================================" << endl;
	stackList->PrintListR(stackList->getHead());

	stackList->top();

	cout << "stack pop" << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;

		stackList->PrintListR(stackList->getHead());
		cout << "======================================================================================================" << endl;

		stackList->pop();
		cout << "======================================================================================================" << endl;
		stackList->PrintListR(stackList->getHead());

		stackList->pop();
		cout << "======================================================================================================" << endl;
		stackList->PrintListR(stackList->getHead());

		stackList->pop();
		cout << "======================================================================================================" << endl;
		stackList->PrintListR(stackList->getHead());
	// que
	//=================================================================================================================================

	cout << "queue enque" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

	queList->enqueue(aBagel4);
	cout << "======================================================================================================" << endl;
	queList->PrintListR(queList->getHead());

	queList->enqueue(aBagel5);
	cout << "======================================================================================================" << endl;
	queList->PrintListR(queList->getHead());

	queList->top();

	queList->enqueue(aBagel6);
	cout << "======================================================================================================" << endl;
	queList->PrintListR(queList->getHead());

	queList->top();

	cout << "queue deque" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

	queList->PrintListR(queList->getHead());
	cout << "======================================================================================================" << endl;

	queList->dequeue();
	cout << "======================================================================================================" << endl;
	queList->PrintListR(queList->getHead());

	queList->dequeue();
	cout << "======================================================================================================" << endl;
	queList->PrintListR(queList->getHead());

	queList->dequeue();
	cout << "======================================================================================================" << endl;
	queList->PrintListR(queList->getHead());




	cout << "End of Program." << endl; // prints !!!Hello World!!!
	return 0;
}
