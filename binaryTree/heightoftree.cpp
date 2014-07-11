#include <iostream>
#include <cstdio>
using namespace std;

class btnode
{
public:
	int data;
	btnode* left;
	btnode* right;

	btnode(int data)
	{
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

int treesize(btnode* root)
{
	if(!root)
		return 0;
	int left = treesize(root->left);
	int right = treesize(root->right);
	if(left>right)
		return left+1;
	else
		return right+1;
}



int main()
{
    btnode *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
  
    printf("Hight of tree is %d", treesize(root));
  
    getchar();
    return 0;
}