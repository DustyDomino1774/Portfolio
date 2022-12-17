//============================================================================
// Name        : CS20_LinkedList.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct listNode
{
	int Data;
	listNode *Next = nullptr;
	// listNode *head;
};

void Push_back(listNode* &, int);
void Push_front(listNode* &, int);
void Pop_front(listNode* &);
void Pop_back(listNode* &);
void Insert_at(listNode* &, int, int);
void Print_List(listNode*);
void Delete_at(listNode* &, int);
void Delete_List(listNode* &);
int Get_at(listNode*, int);

int main()
{
	listNode* head = nullptr;
	Print_List(head);

	Push_back(head, 15);
	Print_List(head);

	Push_back(head, 150);
	Print_List(head);

	Push_back(head, 1176);
	Print_List(head);

	Push_back(head, 1535);
	Print_List(head);

	Pop_front(head);
	Print_List(head);

	Pop_back(head);
	Print_List(head);

	Push_front(head, 16);
	Print_List(head);

	Insert_at(head, 17, 1);
	Print_List(head);

	Delete_at(head, 2);
	Print_List(head);

	Delete_List(head);
	Print_List(head);


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

void Push_back(listNode* &theHead, int theData)
{
	if (theHead == nullptr)
	{
		theHead = new listNode;
		theHead->Data = theData;
	}
	else
	{
		listNode *tempNode = theHead;
		while(tempNode->Next != nullptr)
		{
			tempNode = tempNode->Next;
		}

		listNode *newNode = new listNode;
		tempNode->Next = newNode;
		newNode->Data = theData;
	}
}

void Push_front(listNode* &theHead, int theData)
{
	listNode *tempNode = theHead;
	listNode *newHead = new listNode;
	newHead->Next = tempNode;
	theHead = newHead;
	newHead->Data = theData;

}

void Pop_front(listNode* &theHead)
{
	if (theHead != nullptr)
	{
		listNode *tempHead = theHead;
		theHead = tempHead->Next;
		delete tempHead;
	}
}

void Pop_back(listNode* &theHead)
{
	if (theHead != nullptr)
	{
		listNode *aNode = theHead;

		while(aNode->Next->Next != nullptr)
		{
			aNode = aNode->Next;
		}

		delete aNode->Next;
		aNode->Next = nullptr;
	}
}

void Insert_at(listNode* &theHead, int theData, int nodePlace)
{

	if(nodePlace >= 0)
	{
		listNode* newNode = new listNode;
		newNode->Data = theData;

		if (theHead == nullptr)
		{
			theHead = newNode;



		}// if
		else if(nodePlace == 1)
		{
			Push_front(theHead, theData);
		}// else if

		else
		{

			listNode *tempNode = theHead;
			int nodeCountMax = 1;

			while (tempNode != nullptr)
			{
				tempNode = tempNode->Next;
				nodeCountMax++;
			} // while

			if ((nodePlace + 1) >= nodeCountMax)
			{
				Push_back(theHead, theData);
			}// if
			else
			{
				int nodeCount = 0;
				listNode *prev = nullptr;
				listNode *current = theHead;

				while ((nodeCount < nodePlace ) && (current != nullptr))
				{
					prev = current;
					current = current->Next;
					nodeCount++;
				}//while

				prev->Next = newNode;
				newNode->Next = current;

			}// else
		}// else

	} //if
	else
	{
		cout << "You entered the wrong shit boi (or gurl don't make no difference)." << endl;
	} // else

}

void Print_List(listNode* theHead)
{
	listNode *tempHead = theHead;
	int size = 0;
	while (theHead != nullptr)
	{
		tempHead = theHead;
		cout << tempHead->Data << ", ";
		theHead = tempHead->Next;
		size++;
	}
	cout << endl;
	cout << size << endl;

}

void Delete_at(listNode* & theHead, int nodePlace)
{
	if (theHead == nullptr)
	{
		//throw "list empty";
		cout << "Empty list" << endl;
	}

	if((nodePlace-1) == 0)
	{
		Pop_front(theHead);
	}
	listNode *current = theHead;
	listNode *prev = nullptr;
	int listCount = 0;
	while ((listCount < nodePlace ) && (current != nullptr))
	{
		prev = current;
		current = current->Next;
		listCount++;
	}
	if (current != nullptr)
	{
		prev->Next = current->Next;
		delete current;
	}
	else
	{
		cout << "Node does not exist" << endl;
	}

}

void Delete_List(listNode* &theHead)
{
	listNode *tempHead;
	while (theHead != nullptr)
	{
		tempHead = theHead->Next;
		delete theHead;
		theHead = tempHead;
	}

	cout << "Linked list deleted" << endl;
}

int Get_at(listNode* theHead, int nodePlace)
{
	if (theHead == nullptr)
		{
			//throw "list empty";
			cout << "Empty list" << endl;
			return 0;
		}
	else
	{
		int listCount = 0;
			while ((listCount < nodePlace) && (theHead != nullptr))
			{

				theHead = theHead->Next;
				listCount++;
			}
			return theHead->Data;
	}
}
