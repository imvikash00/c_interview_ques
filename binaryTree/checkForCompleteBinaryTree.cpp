/*A complete binary tree is a binary 
tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible
*/

//Method

/*
Level order traversal could be used

1. A node shoud hve to children
2. If a node doesn't have left child then it shoudn't hve right child
3, If a node doesn't hve right child then that shoud be the end of the binary tree
   we could test that by checking for null in the queue

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
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

bool isCompleteBT(btnode *root)
{
	if(!root)
		return true;
	queue<btnode *> queue;
	queue.push(root);
	bool flag = false;
	//queue.push(NULL);
	while(!queue.empty() )
	{
		btnode *temp= queue.front();
		queue.pop();
		if(temp->left)
		{
			queue.push(temp->left);
			if(flag==true)
				return false;
		}
		else
			flag = true;
		if(temp->right)
		{
			queue.push(temp->right);
			if(flag==true)
				return false;
		}
		else
			flag = true;
		
	}
	return true;

}

int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
	btnode *root  = newNode(1);
  root->left         = newNode(2);
  //root->right        = newNode(3);
  //root->left->left   = newNode(4);
  //root->left->right  = newNode(5);
  //root->right->left = newNode(6);

  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");

  return 0;
}
