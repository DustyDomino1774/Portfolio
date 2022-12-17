//============================================================================
// Name        : CS20_BinaryTrees.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Not today big boi
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct TreeNode
{
	int Data;
	TreeNode* Left;
	TreeNode* Right;
};

bool InsertNode(TreeNode*&, TreeNode*);
void PrintTreePost(TreeNode*);
void PrintTreeIn(TreeNode*);
void PrintTreePre(TreeNode*);
void DeleteTree(TreeNode*&);
bool Search(TreeNode*, int);
void deleteNode(int , TreeNode*&);
void deleteLeaf (TreeNode*& );

int main() {
	TreeNode* TreePointer = nullptr;

	TreeNode* newNode = new TreeNode;
	newNode->Data = 31;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	InsertNode(TreePointer, newNode);

	newNode = new TreeNode;
	newNode->Data = 19;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	InsertNode(TreePointer, newNode);

	newNode = new TreeNode;
	newNode->Data = 59;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	InsertNode(TreePointer, newNode);

	newNode = new TreeNode;
	newNode->Data = 20;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	InsertNode(TreePointer, newNode);

	newNode = new TreeNode;
	newNode->Data = 7;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	InsertNode(TreePointer, newNode);

	newNode = new TreeNode;
	newNode->Data = 60;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	InsertNode(TreePointer, newNode);

	PrintTreePre(TreePointer);
	cout << endl;
	PrintTreePost(TreePointer);
	cout << endl;
	deleteNode(60 , TreePointer);
	PrintTreeIn(TreePointer);
	cout<< endl;

	if (Search(TreePointer, 7) == true)
	{
		cout << "Found: 7" << endl;
	}
	else
	{
		cout << "Number wasn't found" << endl;
	}

	DeleteTree(TreePointer);

	cout << "End of Program." << endl;
	return 0;
}

bool InsertNode(TreeNode*& treePtr, TreeNode* theNode)
{
	if(treePtr == nullptr)
	{
		treePtr = theNode;
		return true;
	}

	if(theNode->Data == treePtr->Data)
	{
		return false;
	}

	if(theNode->Data < treePtr->Data)
	{
		if (treePtr->Left == nullptr)
		{
			treePtr->Left = theNode;
			return true;
		}
		return InsertNode(treePtr->Left, theNode);
	}
	else
	{
		if (treePtr->Right == nullptr)
		{
			treePtr->Right = theNode;
			return true;
		}
		return InsertNode(treePtr->Right, theNode);
	}

}

void PrintTreePost(TreeNode* treePtr)
{
	if (treePtr == nullptr)
	{
		return;
	}
	PrintTreePost(treePtr->Left);
	PrintTreePost(treePtr->Right);
	cout << treePtr->Data << endl;
}

void PrintTreeIn(TreeNode* treePtr)
{
	if (treePtr == nullptr)
	{
		return;
	}
	PrintTreeIn(treePtr->Left);
	cout << treePtr->Data << endl;
	PrintTreeIn(treePtr->Right);
}

void PrintTreePre(TreeNode* treePtr)
{
	if (treePtr == nullptr)
	{
		return;
	}
	cout << treePtr->Data << endl;
	PrintTreePre(treePtr->Left);
	PrintTreePre(treePtr->Right);
}

void DeleteTree(TreeNode*& treePtr)
{
	if (treePtr == nullptr)
	{
		return;
	}
	DeleteTree(treePtr->Left);
	DeleteTree(treePtr->Right);
	delete treePtr;
}

bool Search(TreeNode* treePtr, int value)
{
	if (treePtr == nullptr)
	{
		return true;
	}

	if(treePtr->Data == value)
	{
		return true;
	}
	if(treePtr->Data < value)
	{
	return Search(treePtr->Left, value);
	}

	if(treePtr->Data > value)
	{
	return Search(treePtr->Right, value);
	}

	return false;
}

void deleteNode(int num, TreeNode *&treePtr)
 {
 if (num < treePtr->Data)
 deleteNode(num, treePtr->Left);
 else if (num > treePtr->Data)
 deleteNode(num, treePtr->Right);
 else
 deleteLeaf(treePtr);
 }

void deleteLeaf (TreeNode*& treePtr)
{

	       // Define a temporary pointer to use in reattaching
	       // the left subtree.
	       TreeNode *tempNodePtr = nullptr;

	       if (treePtr == nullptr)
	           cout << "Cannot delete empty node.\n";
	       else if (treePtr->Right == nullptr)
	       {
	           tempNodePtr = treePtr;
	           treePtr = treePtr->Left;  // Reattach the left child.
	           delete tempNodePtr;
	       }
	       else if (treePtr->Left == nullptr)
	       {
	           tempNodePtr = treePtr;
	           treePtr = treePtr->Right;  // Reattach the right child.
	           delete tempNodePtr;
	       }
	       // If the node has two children.
	       else
	       {
//	           // Move one node to the right.
//	           tempNodePtr = treePtr->Right;
//	           // Go to the end left node.
//	           while (tempNodePtr->Left)
//	               tempNodePtr = tempNodePtr->Left;
//	           // Reattach the left subtree.
//	           tempNodePtr->Left = treePtr->Left;
//	           tempNodePtr = treePtr;
//	           // Reattach the right subtree.
//	           treePtr = treePtr->Right;
//	           delete tempNodePtr;
	       }


}
