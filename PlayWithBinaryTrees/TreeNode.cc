/*
 * TreeNode.cc
 *
 *  Created on: Nov 29, 2015
 *      Author: ioannis
 */

#include "TreeNode.h"

TreeNode::TreeNode(int number){
	// Constructor.  Make a node containing str.
	item = number;
	left = NULL;
	right = NULL;
}

TreeNode::~TreeNode() {
	// TODO Auto-generated destructor stub
}

void TreeNode::treeInsert(TreeNode *&root, int newItem){
	// Add the item to the binary sort tree to which the parameter
	// "root" refers.  Note that root is passed by reference since
	// its value can change in the case where the tree is empty.
	if ( root == NULL ) {
		// The tree is empty.  Set root to point to a new node containing
		// the new item.  This becomes the only node in the tree.
		root = new TreeNode( newItem );
		// NOTE:  The left and right subtrees of root
		// are automatically set to NULL by the constructor.
		// This is important!
		return;
	}
	else if ( newItem < root->item ) {
		treeInsert( root->left, newItem );
	}
	else {
		treeInsert( root->right, newItem );
	}
}


int TreeNode::countNodes( TreeNode *root ) {
      // Count the nodes in the binary tree to which
      // root points, and return the answer.
   if ( root == NULL )
      return 0;  // The tree is empty.  It contains no nodes.
   else {
      int count = 1;   // Start by counting the root.
      count += countNodes(root->left);  // Add the number of nodes
                                       //     in the left subtree.
      count += countNodes(root->right); // Add the number of nodes
                                       //    in the right subtree.
      return count;  // Return the total.
   }
} // end countNodes()

void TreeNode::preorderPrint( TreeNode *root ) {
      // Print all the items in the tree to which root points.
      // The item in the root is printed first, followed by the
      // items in the left subtree and then the items in the
      // right subtree.
   if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
      cout << root->item << " ";      // Print the root item.
      preorderPrint( root->left );    // Print items in left subtree.
      preorderPrint( root->right );   // Print items in right subtree.
   }
} // end preorderPrint()


bool TreeNode::treeContains( TreeNode *root, int item ) {
       // Return true if item is one of the items in the binary
       // sort tree to which root points.   Return false if not.
   if ( root == NULL ) {
         // Tree is empty, so it certainly doesn't contain item.
      return false;
   }
   else if ( item == root->item ) {
         // Yes, the item has been found in the root node.
      return true;
   }
   else if ( item < root->item ) {
         // If the item occurs, it must be in the left subtree.
      return treeContains( root->left, item );
   }
   else {
         // If the item occurs, it must be in the right subtree.
      return treeContains( root->right, item );
   }
}  // end treeContains()
