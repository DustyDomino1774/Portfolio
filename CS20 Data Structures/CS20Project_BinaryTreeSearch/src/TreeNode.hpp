/*
 * TreeNode.hpp
 *
 *  Created on: Apr 19, 2018
 *      Author: Dominic
 */

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

class TreeNode {
public:
    TreeNode();
    virtual ~TreeNode();

    int Data;
    TreeNode* Left;
    TreeNode* Right;
    int BalanceFactor;

private:

};

#endif /* TreeNode_hpp */

