#include <iostream>
#include <cstdio>
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

void inOrder(btnode *root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void MirrorTree(btnode *root)
{
	if(!root)
		return;
	MirrorTree(root->right);
	MirrorTree(root->left);
	btnode *temp=root->right;
	root->right = root->left;
	root->left = temp;
}
//Makes a new tree which is the mirror of the previous tree
btnode *MakeMirrorTree(btnode *root)
{
	if(!root)
		return NULL;
	btnode *root1 = new btnode(root->data);
	root1->right=MakeMirrorTree(root->left);
	root1->left=MakeMirrorTree(root->right);
	return root1;
}

int main()
{
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
  
  /* Convert tree to its mirror */
  root=MakeMirrorTree(root); 
  
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");  
  inOrder(root);
  
  getchar();
  return 0;  
}