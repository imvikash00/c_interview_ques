// use geeks for geeks for algorithm


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

void morrisTraversalPreorder(btnode *root)
{
	if(!root)
		return;
	while(root)
	{	
		if(!root->left)
		{
			cout<<root->data<<" ";
			root=root->right;
		}
		else
		{
			btnode *current=root->left;
			while(current->right && current->right!=root)
				current=current->right;
			if(current->right==root)
			{
				current->right=NULL;
				root=root->right;
			}
			else
			{
				cout<<root->data<<" ";
				current->right=root;
				root=root->left;
			}
		}
	}	
}


void preorder(btnode* root)
{
    if (root)
    {
        printf( "%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Driver program to test above functions*/
int main()
{
    btnode* root = NULL;

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    morrisTraversalPreorder(root);

    printf("\n");
    preorder(root);

    return 0;
}