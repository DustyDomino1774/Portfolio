/*
 * LinkedList.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Dominic
 */

#include <iomanip>
#include <iostream>
#include "LinkedList.hpp"

#include "Bagel.hpp"

LinkedList::LinkedList()
{
	// TODO Auto-generated constructor stub

	headptr = NULL;
}


LinkedList::~LinkedList()
{
	// TODO Auto-generated destructor stub

	delete_list();
}


void LinkedList::push_back(Bagel* theData)
{
	if (headptr == NULL)
	{
		headptr = new ListNode;
		headptr->data = theData;
	}
	else
	{
		ListNode *tempNode = headptr;
		while(tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}

		ListNode *newNode = new ListNode;
		tempNode->next = newNode;
		newNode->data = theData;
	}
}


void LinkedList::push_front(Bagel* theData)
{
	ListNode *tempNode = headptr;
	ListNode *newHead = new ListNode;
	newHead->data = theData;
	newHead->next = tempNode;
	headptr = newHead;
}

int LinkedList::size()
{
	ListNode *tempHead = headptr;
	int sizeCount = 0;
	while (tempHead != NULL)
	{
		tempHead = tempHead->next;
		sizeCount++;
	}
	return sizeCount;
}

void LinkedList::print_list()
{
	ListNode *tempHead = headptr;
	while (tempHead != NULL)
	{
		cout << tempHead->data << ", ";
		tempHead = tempHead->next;
	}
	cout << endl;
}


void LinkedList::delete_list()
{
	while (headptr != NULL)
	{
		ListNode *tempHead = headptr;
		headptr = headptr->next;
		delete tempHead;
	}
	cout << "List deleted" << endl;
	cout << endl;
}


void LinkedList:: pop_front()
{
	if (headptr != NULL)
	{
		ListNode *tempHead = headptr;
		headptr = tempHead->next;
		delete tempHead;
	}
}


void LinkedList::pop_back()
{
//	if (headptr != NULL)
//	{
//		if (headptr->next != NULL)
//		{
//		ListNode *aNode = headptr;
//
//		aNode = FindLastNode(aNode);
//
//		delete aNode;
//		}
//		else
//		{
//			delete headptr;
//			headptr = NULL;
//		}
//	}

	if (headptr != NULL)
		{
		if (headptr->next != NULL)
		{

			ListNode *aNode = headptr->next;
			ListNode *prev = headptr;

			while(aNode->next != NULL)
			{
				prev = aNode;
				aNode = aNode->next;
			}

			prev->next = NULL;

			delete aNode;
			}
		else
		{
			delete headptr;
			headptr = NULL;
		}
		}

}

Bagel* LinkedList::first()
{
	if (headptr == NULL)
	{
		char errMsg[] = "Error: Empty list.";
		throw errMsg;

	}
	else
	{
		return headptr->data;
	}
}


Bagel* LinkedList::last()
{
	if (headptr == NULL)
	{
		char errMsg[] = "Error: Empty list.";
		throw errMsg;

	}
	else
	{
		ListNode *aNode = headptr;

		aNode = FindLastNode(aNode);
		return aNode->data;
	}
}
Bagel* LinkedList::getAt(int nodePlace)
{
	if (headptr == NULL)
	{
		//throw "list empty";
		cout << "Empty list" << endl;
		return 0;
	}
	else if((nodePlace + 1) > size())
	{
		char errMsg[] = "Error: Node does not exist.";
		throw errMsg;
	}
	else
	{
		ListNode* tempHead = headptr;
		int listCount = 0;
		while ((listCount < nodePlace) && (tempHead != NULL))
		{

			tempHead = tempHead->next;
			listCount++;
		}
		return tempHead->data;
	}
}


Bagel* LinkedList::operator[](const int theIndex)
{
	Bagel* theData;
	return	theData = getAt(theIndex);
}


void LinkedList::insertAt(Bagel* theData, int nodePlace)
{

	if((nodePlace + 1) > size())
	{
		char errMsg[] = "Error: Node does not exist.";
		throw errMsg;
	}// if
	else
	{
		if ((nodePlace + 1) == size())
		{
			push_back(theData);
		}// if
		else if (nodePlace == 0)
		{
			push_front(theData);
		}
		else
		{
			ListNode* newNode = new ListNode;
			newNode->data = theData;
			int nodeCount = 0;
			ListNode *prev = NULL;
			ListNode *current = headptr;

			while ((nodeCount < nodePlace ))
			{
				prev = current;
				current = current->next;
				nodeCount++;
			}//while

			prev->next = newNode;
			newNode->next = current;
		}
	}// else
}


void LinkedList::deleteAt(int nodePlace)
{
	if((nodePlace + 1) > size())
	{
		char errMsg[] = "Error: Node does not exist.";
		throw errMsg;
	}// if
	else if (headptr == NULL)
	{
		char errMsg[] = "Error: Empty list.";
		throw errMsg;
	}// else if
	else
	{
		if(nodePlace == 0)
		{
			pop_front();
		}
		else
		{
			ListNode *current = headptr;
			ListNode *prev = NULL;
			int listCount = 0;
			while ((listCount < nodePlace) && (current != NULL))
			{
				prev = current;
				current = current->next;
				listCount++;
			}
			prev->next = current->next;
			delete current;
		}
	}// else
}


void LinkedList::insertSorted(Bagel* theData)
{
	ListNode* tempHead;
	ListNode* newNode = new ListNode;
	newNode->data = theData;
	ListNode *prev = NULL;
	ListNode *current = headptr;

	if (headptr->data > newNode->data)
	{
		tempHead = headptr;
		headptr = newNode;
		newNode->next = tempHead;

	}
	else
	{

		while (current->data < newNode->data)
		{
			prev = current;
			current = current->next;
			if (current == NULL)
			{
				break;
			}
		}

		prev->next = newNode;
		newNode->next = current;
	}
}

ListNode* LinkedList::getHead()
{
	return headptr;
}


ListNode* LinkedList::FindLastNode(ListNode* current)
{
	if (current->next == NULL)
	{

		return current;
	}
	else
	{
		return FindLastNode(current->next);
	}
}

int LinkedList::CountInventory(ListNode* current)
{

	if (current == NULL)
	{
		return 0;
	}
	else
	{
		return current->data->getOnHand() + CountInventory(current->next);
	}
}

void LinkedList::PrintListR(ListNode* current)
{
	int menuWidth = 20;
	if (current == NULL)
	{
		cout << endl;
		return;
	}
	else
	{
		cout << setw(menuWidth) << "Bagel Flavor" << setw(menuWidth) << "Bagel Cost" << setw(menuWidth) << "Bagel Price" << setw(menuWidth) << "Bagel On Hand" << endl;
		cout << setw(menuWidth) << "------------" << setw(menuWidth) << "----------" << setw(menuWidth) << "-----------" << setw(menuWidth) << "--------------" << endl;
		cout << setw(menuWidth) << current->data->getFlavor() << setw(menuWidth) << current->data->getCost() << setw(menuWidth) << current->data->getPrice() << setw(menuWidth) << current->data->getOnHand() << endl;
		cout << endl;
		PrintListR(current->next);
	}
}
