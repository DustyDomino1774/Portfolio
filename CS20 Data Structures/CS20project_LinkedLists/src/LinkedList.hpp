/*
 * LinkedList.hpp
 *
 *  Created on: Feb 11, 2018
 *      Author: Dominic London
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>
#include <cstring>
using namespace std;

class LinkedList {
private:

	struct ListNode {
		int data;
		ListNode *next = nullptr;
	};//ListNode

	ListNode* headptr;

public:

	void push_back(int);
	void push_front(int);
	int size();
	void delete_list();
	void print_list();
	void pop_front();
	void pop_back();
	int first();
	int last();
	int getAt(int);
	int operator[](const int);
	void insertAt(int, int);
	void deleteAt(int);
	void insertSorted(int);

	LinkedList();
	virtual ~LinkedList();
	//	void Push_back(listNode* &, int);
	//	void Push_front(listNode* &, int);
	//	void Pop_front(listNode* &);
	//	void Pop_back(listNode* &);
	//	void Insert_at(listNode* &, int, int);
	//	void Print_List(listNode*);
	//	void Delete_at(listNode* &, int);
	//	void Delete_List(listNode* &);
	//	int Get_at(listNode*, int);

};

#endif /* LINKEDLIST_HPP_ */
