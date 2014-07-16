#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class btnode
{
public:
	int data;
	btnode *left;
	btnode *right;
	btnode(int data)
	{
		this->data=data;
		this->right=NULL;
		this->left=NULL;
	}
	~btnode();
	
};

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

void printklevelnode(btnode *root, int k)
{
	if(!root)
		return;
	// if k greater than height then return..not implementing

	if(k==0)
		cout<<root->data<<endl;
	printklevelnode(root->left,k-1);
	printklevelnode(root->right,k-1);

}

int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8 
  */
btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  

  printklevelnode(root, 2);

  getchar();
  return 0;
}