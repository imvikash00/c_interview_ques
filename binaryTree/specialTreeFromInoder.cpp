/*
Given Inorder Traversal of a Special Binary Tree in 
which key of every node is greater than keys in left and right children, construct the Binary Tree and return root
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

btnode *newnode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

int findmaxindex(int inorder[], int sindex, int eindex)
{
	int max=0;
	for(int i=sindex;i<=eindex;i++)
	{
		if(inorder[i]>inorder[max])
			max=i;
	}
	return max;
}

btnode *constructtree(int inorder[], int sindex, int eindex)
{
	if(sindex>eindex)
		return NULL;
	int max=findmaxindex(inorder,sindex,eindex);
	btnode *temp=newnode(inorder[max]);
	if(sindex==eindex)
		return temp;
	temp->left=constructtree(inorder,sindex,max-1);
	temp->right=constructtree(inorder,max+1,eindex);
	return temp;
}

void printInorder (btnode* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder (node->right);
}
 
/* Driver program to test above functions */
int main()
{
   /* Assume that inorder traversal of following tree is given
         40
       /   \
      10     30
     /         \
    5          28 */
 
    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    btnode *root = constructtree(inorder, 0, len - 1);
 
    /* Let us test the built tree by printing Insorder traversal */
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}