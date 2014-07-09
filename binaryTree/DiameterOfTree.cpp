//how to print the path of max diameter
//http://stackoverflow.com/questions/16379670/path-of-the-diameter-of-a-binary-tree

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

class  btnode
{
public:
	int data;
	btnode *right;
	btnode *left;
	 btnode(int data)
	 {
	 	this->data = data;
	 	this->right = NULL;
	 	this->left = NULL;
	 	this->next = NULL;
	 }
	~ btnode();
	
};

int height(btnode *root)
{
	if(!root)
		return 0;
	else
		return (1+max(height(root->left),height(root->right)));
}

int diameter(btnode *root)
{
	if(!root)
		return 0;
	int leftheight=height(root->right);
	int rightheight=height(root->left);
	int leftdia=diameter(root->right);
	int rightdia=diameter(root->left);
	return ( max(1+(leftheight+rightheight), (leftdia+rightdia)));
}
btnode* newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
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
 
  printf("Diameter of the given binary tree is %d\n", diameter(root));

 
  getchar();
  return 0;
}