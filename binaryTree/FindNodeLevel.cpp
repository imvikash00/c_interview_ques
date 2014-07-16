//given a key find its level in binary tree

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

int getLevel(btnode* root, int key,int level)
{
	
	if(!root)
		return 0;
	
	if(root->data==key)
		return level;
	int res = getLevel(root->left,key,level+1);
	if(res!=0)
		return res;
	res = getLevel(root->right,key,level+1);
	if(res!=0)
		return res;


} 


int main()
{
    
    int x;

    /* Constructing tree given in the above figure */
    btnode *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    for (x = 1; x <=5; x++)
        printf(" Level of %d is %d\n", x, getLevel(root, x,1));

    getchar();
    return 0;
}