// Method 1 is based on level order traversal

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
	btnode *nextRight;
	btnode(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
		this->nextRight=NULL;
	}
};

btnode *newnode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

void ConnectNodesAtSameLevel(btnode *root)
{
	if(!root)
		return;
	queue<btnode *> queue;
	queue.push(root);
	queue.push(NULL);
	while(!queue.empty() && queue.front())
	{
		btnode *temp = queue.front();
		queue.pop();
		temp->nextRight = queue.front();
		if(temp->left)
			queue.push(temp->left);
		if(temp->right)
			queue.push(temp->right);
		if(!queue.front()){
			queue.push(NULL);
			queue.pop();
		}
	}

}

//using level order but only works for complete binary tree

void connectrecur(btnode *root)
{
	if(!root)
		return;
	if(root->left)
		root->left->nextRight=root->right;
	if(root->right)
		root->right->nextRight= root->nextRight?root->nextRight->left:NULL;
	connectrecur(root->left);
	connectrecur(root->right);
}

//wrapper
void connect(btnode *root)
{
	if(!root)
		return;
	root->nextRight=NULL;
	connectrecur(root);
}


int main()
{
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /
    3
  */
  btnode *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
 
  // Populates nextRight pointer in all nodes
  //ConnectNodesAtSameLevel(root);
 connect(root);
  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
 
  getchar();
  return 0;
}