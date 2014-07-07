#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

class btnode{
public:
	int data;
	btnode *left;
	btnode *right;

	btnode(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};


btnode *newNode(int data)
{
	btnode *temp=new btnode(data);
	return temp;
}
//returns no. of leaves too
int Levelorder(btnode *root)
{
	int leafs=0;
	if(!root)
		return leafs;
	queue<btnode*> my_queue;
	my_queue.push(root);
	my_queue.push(NULL);
	while(!my_queue.empty())
	{
		cout<<(my_queue.front())->data<<" ";
		root=my_queue.front();
		my_queue.pop();
		if(root->left)
			my_queue.push(root->left);
		if(root->right)
			my_queue.push(root->right);
		if(!root->left && !root->right)
			leafs++;
		if(my_queue.front()==NULL)
		{
			cout<<endl;
			my_queue.pop();
			if(!my_queue.empty())
				my_queue.push(NULL);
		}
	}
	return leafs;
}

int height(btnode *root)
{
	if(!root)
		return 0;
	int right = height(root->right);
	int left = height(root->left);
	if(right>left)
		return 1+right;
	else
		return 1+left;
}


void levelorderv2(btnode *root,int level)
{
	if(!root)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else
	{
		levelorderv2(root->left,level-1);  //if u change the order of left and right then we can print the level from reverse
		levelorderv2(root->right,level-1);
	}
}

void levelorderv2_helper(btnode* root)
{
	int level = height(root);
	for(int i=1;i<=level;i++)
		levelorderv2(root,i);
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
 
  printf("Level Order traversal of binary tree is \n");
  levelorderv2_helper(root);
 
 // getchar();
  return 0;
}

