/*
Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7

Solution:
We need to check the Horizontal Distances from root for all nodes. If two nodes have 
the same Horizontal Distance (HD), then they are on same vertical line. The idea of HD is simple. 
HD for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance 
and a left edge is considered as -1 horizontal distance. For example, in the above tree, HD for Node 4 is 
at -2, HD for Node 2 is -1, HD for 5 and 6 is 0 and HD for node 7 is +2.
We can do inorder traversal of the given Binary Tree. While traversing the tree, we can recursively 
calculate HDs. We initially pass the horizontal distance as 0 for root. For left subtree, we pass the 
Horizontal Distance as Horizontal distance of root minus 1. For right subtree, we pass the Horizontal 
Distance as Horizontal Distance of root plus 1

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


void VerticalSum(btnode *root, int horizontaldis,int arr[])
{
	if(root)
	{
		VerticalSum(root->left,horizontaldis-1,arr);
		int prev = arr[horizontaldis];
		arr[horizontaldis] = prev+root->data;
		VerticalSum(root->right,horizontaldis+1,arr);
	}
}

void VerticalSumWrapper(btnode *root)
{
	if(!root)
		return;
	int arr[100]={0};
	VerticalSum(root,0,arr);
	for(int i=0;i<100;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	btnode *root= newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left = newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	VerticalSumWrapper(root);
	return 0;
}