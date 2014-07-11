/*
Algorithm:
Traverse given tree in post order to convert it, i.e., first change left and right children to hold the children sum property then change the parent node.

Let difference between node’s data and children sum be diff.

     diff = node’s children sum - node’s data  
If diff is 0 then nothing needs to be done.

If diff > 0 ( node’s data is smaller than node’s children sum) increment the node’s data by diff.

If diff < 0 (node’s data is greater than the node's children sum) then increment one child’s data. We can choose to increment either left or right child if 
they both are not NULL. Let us always first increment the left child. Incrementing a child changes the subtree’s children sum property so we need to change left subtree also. So we recursively increment the left child. If left child is empty then we recursively call increment() for right child.
*/
#include <iostream>
#include <cstdio>
using namespace std;


class btnode
{
public:
	int data;
	btnode *left;
	btnode *right;
	btnode(int data)
	{
		this->data= data;
		this->left = NULL;
		this->right = NULL;
	}
};

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;

}

void convert_tree_children_prop(btnode *root)
{
	if(root && !(root->right==NULL && root->left==NULL))
	{
		convert_tree_children_prop(root->left);
		convert_tree_children_prop(root->right);
		int diff,rightdata=0,leftdata=0;
		if(root->right)
			rightdata=root->right->data;
		if(root->left)
			leftdata=root->left->data;
		diff = (rightdata+leftdata)-root->data;
		if(diff==0)
			return;
		else if(diff>0)
			root->data +=diff;
		else
		{
			if(root->left)
			{
				root->left->data += diff;
				convert_tree_children_prop(root->left);
			}
			else
			{
				root->right->data += diff;
				convert_tree_children_prop(root->right);		
			}	
			
		}
	}
}

bool checkprop(btnode *root)
{
	if(!root || (root->left == NULL && root->right==NULL))
		return true;
	int leftdata=0,rightdata=0;
	if(root->left)
		leftdata=root->left->data;
	if(root->right)
		rightdata = root->right->data;

	if((root->data == (rightdata + leftdata)) && checkprop(root->right) && checkprop(root->left))
		return true;
	return false;
}


int main()
{
	btnode *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
if(!checkprop(root)){
    printf("The given tree doesnot satisfies the children sum property ");
  	convert_tree_children_prop(root);
  	if(checkprop(root))
    		printf("The given tree now satisfies the children sum property ");
 	 else
    		printf("The given tree does not satisfy the children sum property ");
  	}
else
    printf("The given tree does not satisfy the children sum property ");

getchar();
  return 0;
}
