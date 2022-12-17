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

#include "Bagel.hpp"
using namespace std;

struct ListNode {
	Bagel* data;
	ListNode *next = NULL;
};//ListNode

class LinkedList {
private:

	ListNode* headptr;

public:

	void push_back(Bagel*);
	void push_front(Bagel*);
	int size();
	void delete_list();
	void print_list();
	void pop_front();
	void pop_back();
	Bagel* first();
	Bagel* last();
	Bagel* getAt(int);
	Bagel* operator[](const int);
	void insertAt(Bagel*, int);
	void deleteAt(int);
	void insertSorted(Bagel*);
	ListNode* getHead();

	ListNode* FindLastNode(ListNode*);
	int CountInventory(ListNode*);
	void PrintListR(ListNode*);

	LinkedList();
	virtual ~LinkedList();

};

#endif /* LINKEDLIST_HPP_ */
