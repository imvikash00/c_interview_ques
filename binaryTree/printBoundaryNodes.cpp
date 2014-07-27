/*
We break the problem in 3 parts:
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.

*/

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

void printleaf(btnode *root)
{
	if(!root)
		return;
	printleaf(root->left);
	if(!root->left && !root->right)
		cout<<root->data<<" ";
	printleaf(root->right);
}


void printleftboundary(btnode *root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	if(root->left!=NULL && root->left->left!=NULL)
		printleftboundary(root->left);
}


//need to pass root->right else root will be printed twice
void printrightboundary(btnode* root)
{
	if(!root)
		return;
	if(!(root->right!=NULL && root->right->right==NULL))
		printrightboundary(root->right);
	cout<<root->data<<" ";

}

void boundaryTraversal(btnode *root)
{
	if(!root)
		return;
	printleftboundary(root);
	printleaf(root);
	printrightboundary(root->right);
}


int main()
{
    // Let us construct the tree given in the above diagram
    btnode *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
     root->right->right->right        = newNode(26);
    boundaryTraversal( root );

    return 0;
}