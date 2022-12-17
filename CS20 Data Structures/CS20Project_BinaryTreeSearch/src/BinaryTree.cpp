/*
 * BinaryTree.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: Dominic
 */



#include <iostream>
#include <iomanip>
#include "BinaryTree.hpp"
using namespace std;

//
//Default constructor
BinaryTree::BinaryTree() {
	// TODO Auto-generated constructor stub
}//BinaryTree()

//
//Destructor
BinaryTree::~BinaryTree() {
	// TODO Auto-generated destructor stub
	this->destroyTree();
}//~BinaryTree()

//***********************************************************
//Public Functions
//***********************************************************

//
//Public function which inserts an integer into the tree
bool BinaryTree::insert(int anInt) {
	TreeNode* newNode = new TreeNode();
	newNode->Data = anInt;

	if (insertNode(rootNode, newNode)) {
		return true;
	}//if
	else {
		delete newNode;
		return false;
	}//else
}//insert

//
//Public function which will print the tree in forward order
bool BinaryTree::searchNode(int tofind) {
	return findNode(rootNode, tofind);
}//printTreeInOrder;

//
//Public function which will print the tree in forward order
void BinaryTree::displayInOrder(void) {
	if (this->size() > 0) {
		cout << right << setw(8) << "Data" << setw(16) << "Balance Factor" << endl;
		cout << right << setw(8) << "----" << setw(16) << "--------------" << endl;
		printNodesInOrder(rootNode);
	}//if
	else {
		cout << endl << "The tree is empty" << endl << endl;
	}
}//printTreeInOrder;

//
//Public function which will print the tree in reverse order
void BinaryTree::displayPostOrder(void) {
	if (this->size() > 0) {
		cout << right << setw(8) << "Data" << setw(16) << "Balance Factor" << endl;
		cout << right << setw(8) << "----" << setw(16) << "--------------" << endl;
		printNodesPostOrder(rootNode);
	}//if
	else {
		cout << endl << "The tree is empty" << endl << endl;
	}
}//printTreeInPostOrder;

//
//Public function which will print the tree in Pre order
void BinaryTree::displayPreOrder(void) {
	if (this->size() > 0) {
		cout << right << setw(8) << "Data" << setw(16) << "Balance Factor" << endl;
		cout << right << setw(8) << "----" << setw(16) << "--------------" << endl;
		printNodesPreOrder(rootNode);
	}//if
	else {
		cout << endl << "The tree is empty" << endl << endl;
	}
}//printTreeInPreOrder;

//
//Public function which will calculate the size of the tree (number of nodes)
int BinaryTree::size(void) {
	return treeSize(rootNode);
}//getTreeSize

//
//Public function which will delete/clear all nodes in the tree
void BinaryTree::destroyTree(void) {
	destroySubTree(rootNode);
}//clear

//
//Public function which will return whether or not a tree is in balance
//True if the tree is in balance, False if it is not
bool BinaryTree::isInBalance(void) {
	calculateBalance(rootNode);			//Calculate all Balance Factors in the tree
	int anInt = largestBF();			//Find the largest balanace factor
	if (abs(anInt) > 1) {				//If it is > 1 or < -1, the tree is out of balance
		return false;
	}//if
	else {
		return true;
	}//else
}//isInBalance

//
//Public function which will remove a node with a certain value
bool BinaryTree::remove(int valueToFind) {
	return deleteNode(rootNode, valueToFind);
}//remove

//
//Public function which calls the private function calculateHeight to get the height of the tree
int BinaryTree::height(void) {
	return calculateHeight(rootNode);
}//height

//
//Public function which calls findNode with an int value and then returns its balance factor
int BinaryTree::getBalanceFactor(int valueToFind) {
	TreeNode* aNode = findNode(rootNode, valueToFind);
	if (aNode == nullptr) {
		return -999;
	}//if
	else {
		return aNode->BalanceFactor;
	}//else
}//getBalanceFactor

//
//Public function which returns the largest balance factor in the tree.  Used by function isInBalance
int BinaryTree::largestBF(void) {
	return getLargestBF(rootNode);
}


//***********************************************************
//Private Functions
//***********************************************************

//
//Private function called by the public insert function to add a new node to the
//tree
bool BinaryTree::insertNode(TreeNode* &rootNode, TreeNode* newNode) {
	if (rootNode == nullptr) {
		rootNode = newNode;
		return true;
	}//if
	else if (newNode->Data < rootNode->Data) {
		return insertNode(rootNode->Left, newNode);
	}//else if
	else if (newNode->Data > rootNode->Data) {
		return insertNode(rootNode->Right, newNode);
	}//else if
	else {
		return false;
	}//else
}//isnertNode

//
//Private function called by printTreeInFwdOrder to print the tree in forward order
void BinaryTree::printNodesInOrder(TreeNode* rootNode) {
	if (rootNode != nullptr) {
		printNodesInOrder(rootNode->Left);
		cout << right << setw(8) << rootNode->Data << setw(16) << rootNode->BalanceFactor << endl;
		printNodesInOrder(rootNode->Right);
	}//if
}//printNodesInOrder;

//
//Private function called by printTreeInRevOrder to print the tree in reverse order
void BinaryTree::printNodesPostOrder(TreeNode* rootNode) {
	if (rootNode != nullptr) {
		printNodesPostOrder(rootNode->Left);
		printNodesPostOrder(rootNode->Right);
		cout << right << setw(8) << rootNode->Data << setw(16) << rootNode->BalanceFactor << endl;
	}//if
}//printNodesRev

//
//Private function called by printTreeInPreOrder to print the tree in reverse order
void BinaryTree::printNodesPreOrder(TreeNode* rootNode) {
	if (rootNode != nullptr) {
		cout << right << setw(8) << rootNode->Data << setw(16) << rootNode->BalanceFactor << endl;
		printNodesPreOrder(rootNode->Left);
		printNodesPreOrder(rootNode->Right);
	}//if
}//printNodesRev

//
//Private function called by the public function size to return the number of nodes in the tree
int BinaryTree::treeSize(TreeNode* rootNode) {
	if (rootNode != nullptr) {
		int aValue = treeSize(rootNode->Left);
		aValue += treeSize(rootNode->Right);
		return ++aValue;
	}//if
	else {}

	return 0;
}//treeSize;

//
//Private function called by the public function size and will clear all nodes in the tree
void BinaryTree::destroySubTree(TreeNode* &rootNode) {
	if (rootNode != nullptr) {
		destroySubTree(rootNode->Left);
		destroySubTree(rootNode->Right);
		delete rootNode;
	}//if
}//clearTree;

//
//Private function which calculates the balance factor of a node and its branches/leafs.
//Called by isInBalance
int BinaryTree::calculateBalance(TreeNode* rootNode) {

	if (rootNode == nullptr)
	{
		return 0;
	}

	else if ((rootNode->Left == nullptr) && (rootNode->Right == nullptr))
	{
		return 1;
	}

	else
	{
		int left = calculateBalance(rootNode->Left) +1;
		int right = calculateBalance(rootNode->Right) +1;
		rootNode->BalanceFactor = (left - right);
		return 1 + max(calculateBalance(rootNode->Left),calculateBalance(rootNode->Right));
	}

}//calculateBalance

//
//Private function returning the balance factor of a particular node.  Called by isInBalance
int BinaryTree::calculateHeight(TreeNode* rootNode) {

	if (rootNode == nullptr)
	{
		return 0;
	}

	else if ((rootNode->Left == nullptr) && (rootNode->Right == nullptr))
	{
		return 0;
	}

	else
	{
		return 1 + max(calculateHeight(rootNode->Left),calculateHeight(rootNode->Right));
	}

}//calculateHeight

//
//Private function which returns the largest balance factor in the entire tree.  Called by largestBF
int BinaryTree::getLargestBF(TreeNode* rootNode) {

	if (rootNode == nullptr)
	{
		return 0;
	}

	else if ((rootNode->Left == nullptr) && (rootNode->Right == nullptr))
	{
		return rootNode->BalanceFactor;
	}

	else
	{
		int leftBF = abs(getLargestBF(rootNode->Left));
		int rightBF = abs(getLargestBF(rootNode->Right));
		if (leftBF > rightBF)
		{
			return max(abs(rootNode->BalanceFactor),leftBF);
		}
		else if (rightBF > leftBF)
		{
			return max(abs(rootNode->BalanceFactor),rightBF);
		}
		else
		{
			return abs(rootNode->BalanceFactor);
		}
	}

	//	if (rootNode == nullptr)
	//		{
	//			return 0;
	//		}
	//
	//		else if ((rootNode->Left == nullptr) && (rootNode->Right == nullptr))
	//		{
	//			return 0;
	//		}
	//
	//		else
	//		{
	//			return 1 + max(calculateHeight(rootNode->Left),calculateHeight(rootNode->Right));
	//		}

	//	int LBF = rootNode->BalanceFactor;
	//
	//	if (rootNode == nullptr)
	//	{
	//		LBF = 0;
	//		return LBF;
	//	}
	//
	//	else if ((rootNode->Left == nullptr) && (rootNode->Right == nullptr))
	//	{
	//		LBF = rootNode->BalanceFactor;
	//		return LBF;
	//	}
	//
	//	else
	//	{
	//		int largestLeft = abs(getLargestBF(rootNode->Left));
	//		int largestRight = getLargestBF(rootNode->Right);
	//
	//		if(largestLeft > LBF)
	//		{
	//			if (largestRight > largestLeft)
	//			{
	//				return largestRight;
	//			}
	//
	//			else
	//			{
	//				return largestLeft;
	//			}
	//		}
	//
	//		if(largestRight > LBF)
	//		{
	//
	//			return largestRight;
	//		}
	//		else
	//		{
	//			return LBF;
	//		}
	//	}

	//You need to do this

}//getLargestBF

//
//Private function called by remove which will delete a node from the tree with a certain value
bool BinaryTree::deleteNode(TreeNode* &rootNode, int valueToFind) {
	if (rootNode == nullptr) {
		return false;
	}
	else if (rootNode->Data == valueToFind) {
		//delete the node here
		if (rootNode->Right == nullptr) {
			TreeNode* holdNode = rootNode;
			rootNode = rootNode->Left;
			delete holdNode;
		}
		else if (rootNode->Left == nullptr) {
			TreeNode* holdNode = rootNode;
			rootNode = rootNode->Right;
			delete holdNode;
		}
		else if (rootNode->Right->BalanceFactor > rootNode->Left->BalanceFactor) {
			TreeNode* rightNode = rootNode->Right;
			TreeNode* leftNode = rootNode->Left;
			delete rootNode;
			rootNode = rightNode;
			insertNode(rootNode, leftNode);
		}
		else {
			TreeNode* rightNode = rootNode->Right;
			TreeNode* leftNode = rootNode->Left;
			delete rootNode;
			rootNode = leftNode;
			insertNode(rootNode, rightNode);
		}
		return true;
	}//elseif
	else {
		if (valueToFind < rootNode->Data) {
			return deleteNode(rootNode->Left, valueToFind);
		}//if
		else {
			return deleteNode(rootNode->Right, valueToFind);
		}//else
	}
}//deleteNode

//
//Private function called by remove which will delete a node from the tree with a certain value
TreeNode* BinaryTree::findNode(TreeNode* rootNode, int valueToFind) {
	if (rootNode == nullptr) {
		return nullptr;
	}
	else if (rootNode->Data == valueToFind) {
		return rootNode;
	}//elseif
	else {
		if (valueToFind < rootNode->Data) {
			return findNode(rootNode->Left, valueToFind);
		}//if
		else {
			return findNode(rootNode->Right, valueToFind);
		}//else
	}
}//findNode

//
//Private function which will return true if a node is a leaf and false if it is a branch
bool BinaryTree::isLeaf(TreeNode* root) {
	if (root->Left == nullptr && root->Right == nullptr) {
		return true;
	}//if
	else {
		return false;
	}//else
}//isLeaf

//
//Private function which will return a true if the node has a left child, false if not
bool BinaryTree::hasLeftChild(TreeNode* root) {
	if (root->Left != nullptr) {
		return true;
	}//if
	else {
		return false;
	}//else
}//hasLeftChild

//
//Private function which will return a true if the node has a right child, false if not
bool BinaryTree::hasRightChild(TreeNode* root) {
	if (root->Right != nullptr) {
		return true;
	}//if
	else {
		return false;
	}//else
}//hasRightChild


