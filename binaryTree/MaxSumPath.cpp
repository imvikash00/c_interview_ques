
/*
Solution
1) First find the leaf node that is on the maximum sum path. In the following code getTargetLeaf() does this by assigning the result to *target_leaf_ref.
2) Once we have the target leaf node, we can print the maximum sum path by traversing the tree. In the following code, printPath() does this.

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

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}


bool printmaxpath(btnode *root, btnode **target_leaf)
{
	if(!root)
		return false;
	if(root==*target_leaf || printmaxpath(root->left,target_leaf) || printmaxpath(root->right,target_leaf))
	{
		cout<<root->data<<" ";
		return true;
	}
	return false;
}

void getTargetLeaf(btnode *root, btnode **target_leaf, int curr_sum, int *max_sum)
{
	if(!root)
	{
		return;
	}
	curr_sum = curr_sum+root->data;
	if(root->left==NULL && root->right==NULL)
	{
		*max_sum = curr_sum > *max_sum ? curr_sum: *max_sum;
		*target_leaf = root;
	}
	getTargetLeaf(root->left,target_leaf,curr_sum,max_sum);
	getTargetLeaf(root->right,target_leaf,curr_sum,max_sum);
}

void maxsumpath(btnode *root)
{
	if(!root)
		return;
	btnode *target_leaf=NULL;
	int max=INT_MIN;
	getTargetLeaf(root,&target_leaf,0,&max);
	printmaxpath(root,&target_leaf);
	cout<<"Max sum is "<<max<<endl;
}

int main()
{
    btnode *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    printf ("Following are the nodes on the maximum sum path \n");
    maxsumpath(root);
    //printf ("\nSum of the nodes is %d ", sum);
 
    getchar();
    return 0;
}