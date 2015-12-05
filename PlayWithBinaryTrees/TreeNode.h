/*
 * TreeNode.h
 *
 *  Created on: Nov 29, 2015
 *      Author: ioannis
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;


class TreeNode {
public:
	TreeNode(int number);
	~TreeNode();

	void treeInsert(TreeNode *&root, int newItem);
	int countNodes( TreeNode *root );
	void preorderPrint( TreeNode *root );
	bool treeContains( TreeNode *root, int item );


private:
	int item;         // The data in this node.
	TreeNode *left;   // Pointer to the left subtree.
	TreeNode *right;  // Pointer to the right subtree.

};


#endif /* TREENODE_H_ */
