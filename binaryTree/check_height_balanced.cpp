/* Height balanced Tree
	Non-empty is height balanced
	if
		Left tree is height balanced
		Right tree is height balanced
		diff btw. height of right and left is not more than 1

*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class btnode{
public:
	int data;
	btnode* left;
	btnode *right;
	btnode(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

int height(btnode *root)
{
	if(!root)
		return 0;
	else
		return(max(height(root->left),height(root->right))+1);
}

//O(n^2)
bool isbalanced(btnode* root)
{
	if(!root)
		return true;
	return (isbalanced(root->left) && isbalanced(root->right) && (height(root->left)-height(root->right))<2);
}

//we could reduce complexity to O(n) by calculating height in the same recursion instead of calling a differenct function

bool isbalancedv2(btnode *root, int *height)
{
	int lh=0,rh=0; //height of left and right
	if(!root)
	{
		*height = 0;
		return true;
	}
	bool l = isbalancedv2(root->left,&lh);
	bool r = isbalancedv2(root->right,&rh); // pay close attention we need to pass rightheight variable
	*height = max(lh,rh)+1;
	return (l&&r&&(lh-rh)<2);
}


int main()
{
    btnode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    int height;
    if(isbalancedv2(root,&height))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    

    getchar();
    return 0;
}