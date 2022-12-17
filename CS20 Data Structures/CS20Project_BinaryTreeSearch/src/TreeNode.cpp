/*
 * TreeNode.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: Dominic
 */


#include "TreeNode.hpp"
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
    Data = 0;
    Left = nullptr;
    Right = nullptr;
    BalanceFactor = 0;
}//TreeNode()

TreeNode::~TreeNode() {
    cout << "Deleting node: " << Data << endl;
}//~TreeNode()
