/*Convert a given tree to its Sum Tree
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each
node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes 
are changed to 0.

For example, the following tree

           10
        /      \
	     -2        6
    /   \      /  \ 
	 8     -4    7    5
should be changed to

          20(4-2+12+6)
        /      \
	   4(8-4)      12(7+5)
     /   \      /  \ 
	 0      0    0    0*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class btnode{
public:
  int data;
  btnode *left;
  btnode *right;
  btnode(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
};

btnode *newNode(int data)
{
  btnode *temp = new btnode(data);
  return temp;
}

int toSumTree(btnode *node)
{
    // Base case
    if(node == NULL)
      return 0;
 
    // Store the old value
    int old_val = node->data;
 
    // Recursively call for left and right subtrees and store the sum as
    // new value of this node
    node->data = toSumTree(node->left) + toSumTree(node->right);
 
    // Return the sum of values of nodes in left and right subtrees and
    // old_value of this node
    return node->data + old_val;
}

void printInorder(btnode *root)
{
  if(root)
  {
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
  }
}

/* Driver function to test above functions */
int main()
{
  btnode *root = NULL;
  int x;
 
  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
 
  toSumTree(root);
 
  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
 
  getchar();
  return 0;
}





