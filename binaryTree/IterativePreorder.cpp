#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
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

void iterativePreorder(btnode *root)
{
	if(!root)
		return;
	stack<btnode *> stack;
	stack.push(root);
	while(!stack.empty())
	{
		btnode *temp=stack.top();
		stack.pop();
		cout<<temp->data<<" ";
		if(temp->right)
			stack.push(temp->right);
		if(temp->left)
			stack.push(temp->left);
		
	}
}

int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  btnode *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
  return 0;
}