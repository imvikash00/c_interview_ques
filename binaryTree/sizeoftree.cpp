#include <iostream>
#include <cstdio>
using namespace std;

class btnode{
public:
	int data;
	btnode *left;
	btnode *right;

};

btnode *newNode(int data)
{
	btnode *temp = new btnode;
	temp->data = data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int sizeoftree(btnode *root)
{
	if(!root)
		return 0;
	else
		return sizeoftree(root->left)+1+sizeoftree(root->right);
}

int main()
{
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);   

  printf("Size of the tree is %d", sizeoftree(root));  
  getchar();
  return 0;
}

