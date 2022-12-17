/*
 * LinkedList.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: Dominic London
 */

#include "LinkedList.hpp"

LinkedList::LinkedList()
{
	// TODO Auto-generated constructor stub
	headptr = nullptr;
}


LinkedList::~LinkedList()
{
	// TODO Auto-generated destructor stub
	delete_list();
}


void LinkedList::push_back(int theData)
{
	if (headptr == nullptr)
	{
		headptr = new ListNode;
		headptr->data = theData;
	}
	else
	{
		ListNode *tempNode = headptr;
		while(tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}

		ListNode *newNode = new ListNode;
		tempNode->next = newNode;
		newNode->data = theData;
	}
}


void LinkedList::push_front(int theData)
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
	while (tempHead != nullptr)
	{
		tempHead = tempHead->next;
		sizeCount++;
	}
	return sizeCount;
}

void LinkedList::print_list()
{
	ListNode *tempHead = headptr;
	while (tempHead != nullptr)
	{
		cout << tempHead->data << ", ";
		tempHead = tempHead->next;
	}
	cout << endl;
}


void LinkedList::delete_list()
{
	while (headptr != nullptr)
	{
		ListNode *tempHead = headptr->next;
		delete headptr;
		headptr = tempHead;
	}
	cout << "List deleted" << endl;
}


void LinkedList:: pop_front()
{
	if (headptr != nullptr)
	{
		ListNode *tempHead = headptr;
		headptr = tempHead->next;
		delete tempHead;
	}
}


void LinkedList::pop_back()
{
	if (headptr != nullptr)
	{
		ListNode *aNode = headptr;

		while(aNode->next->next != nullptr)
		{
			aNode = aNode->next;
		}

		delete aNode->next;
		aNode->next = nullptr;
	}
}

int LinkedList::first()
{
	if (headptr == nullptr)
	{
		char errMsg[] = "Error: Empty list.";
		throw errMsg;

	}
	else
	{
		return headptr->data;
	}
}


int LinkedList::last()
{
	if (headptr == nullptr)
	{
		char errMsg[] = "Error: Empty list.";
		throw errMsg;

	}
	else
	{
		ListNode *aNode = headptr;

		while(aNode->next->next != nullptr)
		{
			aNode = aNode->next;
		}
		return aNode->next->data;
	}
}
int LinkedList::getAt(int nodePlace)
{
	if (headptr == nullptr)
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
		while ((listCount < nodePlace) && (tempHead != nullptr))
		{

			tempHead = tempHead->next;
			listCount++;
		}
		return tempHead->data;
	}
}


int LinkedList::operator[](const int theIndex)
{
	int thePlace;
	return	thePlace = getAt(theIndex);
}


void LinkedList::insertAt(int theData, int nodePlace)
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
			ListNode *prev = nullptr;
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
	else if (headptr == nullptr)
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
			ListNode *prev = nullptr;
			int listCount = 0;
			while ((listCount < nodePlace) && (current != nullptr))
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


void LinkedList::insertSorted(int theData)
{
	ListNode* tempHead;
	ListNode* newNode = new ListNode;
	newNode->data = theData;
	ListNode *prev = nullptr;
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
			if (current == nullptr)
			{
				break;
			}
		}

		prev->next = newNode;
		newNode->next = current;
	}
}
