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
  btnode *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(2);
  
if(checkprop(root))
    printf("The given tree satisfies the children sum property ");
    
else
    printf("The given tree does not satisfy the children sum property ");

  getchar();
  return 0;
}
