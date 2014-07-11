/*
	Preorder = can be used to clone tree
	postorder = can be used to delete tree
	inorder = to sort bst
*/



#include <iostream>
#include <cstdio>
using namespace std;

class node
{
public:
  	int data;
	node *left;
	node * right;
};


node* newNode(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void inorder(node *head)
{
	if(head)
	{
		inorder(head->left);
		cout<<head->data<<" ";
		inorder(head->right);
	}
	else
	  return;
}

void preorder(node *head)
{
   	if(head)
	{
	  cout<<head->data<<" ";
	  preorder(head->left);
	  preorder(head->right);
	}
	else
	  return;
}

void postorder(node *head)
{
	if(head)
	{
          postorder(head->left);
	  postorder(head->right);
	  cout<<head->data<<" ";
	}
	else
	  return;
}


int main()
{
     node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 

     printf("\n Preorder traversal of binary tree is \n");
     preorder(root);

     printf("\n Inorder traversal of binary tree is \n");
     inorder(root);  

     printf("\n Postorder traversal of binary tree is \n");
     postorder(root);

     //getchar();
     return 0;
}
