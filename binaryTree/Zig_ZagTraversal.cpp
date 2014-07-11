#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

class btnode{
public:
	int data;
	btnode *right;
	btnode *left;

	btnode(int data)
	{
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	}
};
void zigzag(btnode *root, bool itr, int level);
btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

int height(btnode *root)
{
	if(!root)
		return 0;
	int r=  height(root->right);
	int l = height(root->left);
	if(r>=l)
	{
		return 1+r;
	}
	else
		1+l;
}

void callzigzagforeachlevel(btnode *root)
{
	int level = height(root);
	bool itr=true;
	for(int i=1;i<=level;i++)
	{
		zigzag(root,itr,i);
		itr = !itr;
	}
}

void zigzag(btnode *root, bool itr, int level)
{
	if(!root)
		return;
	if(level==1)
		cout<<root->data<<" ";
	if(itr)
	{
		zigzag(root->left,itr,level-1);
		zigzag(root->right,itr,level-1);
	}
	else
	{
		zigzag(root->right,itr,level-1);
		zigzag(root->left,itr,level-1);
	}
}


void zigzagusingstack(btnode *root)
{
	if(!root)
		return;
	stack<btnode *> my_stack;
	stack<btnode *> my_stack1;
	my_stack.push(root);
	while(!my_stack.empty() || !my_stack1.empty()){
		while(!my_stack.empty())
		{
			cout<<(my_stack.top())->data<<" ";
			btnode *temp = my_stack.top();
			my_stack.pop();
			if(temp->right)
				my_stack1.push(temp->right);
			if(temp->left)
				my_stack1.push(temp->left);
			
		
		}
		while(!my_stack1.empty())
		{
			cout<<(my_stack1.top())->data<<" ";
			btnode *temp = my_stack1.top();
			my_stack1.pop();
			if(temp->left)
				my_stack.push(temp->left);
			if(temp->right)
				my_stack.push(temp->right);
		
		}
	}
	
}


int main()
{
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  root->right->left = newNode(6);
  root->right->right = newNode(7);
 
  printf("ZigZag traversal of binary tree is \n");
  zigzagusingstack(root);
 
 // getchar();
  return 0;
}
