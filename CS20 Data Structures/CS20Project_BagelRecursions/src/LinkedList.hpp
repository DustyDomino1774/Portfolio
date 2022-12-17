/*
 * LinkedList.hpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Dominic
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>
#include <cstring>
#include "Bagels.hpp"
using namespace std;

struct ListNode {
	Bagels* data;
	ListNode *next = NULL;
};//ListNode

class LinkedList {
private:

	ListNode* headptr;

public:

	void push_back(Bagels*);
	void push_front(Bagels*);
	int size();
	void delete_list();
	void print_list();
	void pop_front();
	void pop_back();
	Bagels* first();
	Bagels* last();
	Bagels* getAt(int);
	Bagels* operator[](const int);
	void insertAt(Bagels*, int);
	void deleteAt(int);
	void insertSorted(Bagels*);
	ListNode* getHead();

	ListNode* FindLastNode(ListNode*);
	int CountInventory(ListNode*);
	void PrintListR(ListNode*);

	LinkedList();
	virtual ~LinkedList();

};

#endif /* LINKEDLIST_HPP_ */
