/*
Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on 
Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and 
finally revert the changes to restore original tree.

1. Initialize current as root 
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as right child of the rightmost node in current's left subtree
      b) Go to this left child, i.e., current = current->left

*/


#include <iostream>
#include <cstdio>
using namespace std;

class btnode{
public:
	int data;
	btnode* left;
	btnode* right;
	btnode(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

btnode *newNode(int data)
{
	btnode *temp=new btnode(data);
	return temp;
}

void inorder_without_stack_or_recursion(btnode *root)
{
	if(!root)
		return;
  btnode *current = root;
  while(current)
  {
  	if(!current->left)
  	{
  		cout<<current->data<<" ";
  		current = current->right;
  	}
  	else
  	{
  		btnode *temp = current->left;
  		while(temp->right && temp->right != current)
  			temp= temp->right;
  		if(!temp->right)
  		{
  		temp->right = current;
  		current = current->left;
  		}
  		else
  		{
  			temp->right=NULL;
  			cout<<current->data<<" ";
  			current = current->right;
  		}
  	}
  }
}

int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 

  inorder_without_stack_or_recursion(root);

  getchar();
  return 0;
}
