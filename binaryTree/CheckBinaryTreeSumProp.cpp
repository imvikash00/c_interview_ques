// check if root->data = sum of data of left + sum of data of right subtree

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


//Method 1 find sum of left and right tree and then compare it with root->data

int left_right_subtree_sum(btnode *root)
{
	if(!root)
		return 0;
	return root->data+left_right_subtree_sum(root->right)+left_right_subtree_sum(root->left);
}

bool IsSumTree(btnode *root)
{
	if(!root)
		return true;
	if(!root->left && !root->right)  // leaf node is also consider a sum tree
		return true;
	return (root->data==(left_right_subtree_sum(root->right)+left_right_subtree_sum(root->left))) && IsSumTree(root->left) && IsSumTree(root->right);
}



/*Method 2 
1) If the node is a leaf node then sum of subtree rooted with this node is equal to value of this node.
2) If the node is not a leaf node then sum of subtree rooted with this node is twice the value of this 
node (Assuming that the tree rooted with this node is SumTree).
*/

bool isleaf(btnode *root)
{
	if(!root)
		return false;
	if(root->left == NULL && root->right==NULL)
		return true;
	return false;
}

bool IsSumTreev2(btnode *root)
{
	int ls=0,rs=0;
	if(!root)
		return true;
	if(isleaf(root))
		return true;
	if(IsSumTreev2(root->left) && IsSumTreev2(root->right))
	{
		if(!root->left)
			ls=0;
		else if(isleaf(root->left))
			ls=root->left->data;
		else
			ls = 2*root->left->data;  // 2 time because root->data + (left tree+ right tree data) assuming left and right
										// subtree are already sum property tree 
		if(!root->right)
			rs=0;
		else if(isleaf(root->right))
			rs=root->right->data;
		else
			rs = 2*root->right->data;
		return root->data == ls+rs;
	}
	return false;
}

int main()
{
    btnode *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(IsSumTreev2(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");
 
    getchar();
    return 0;
}