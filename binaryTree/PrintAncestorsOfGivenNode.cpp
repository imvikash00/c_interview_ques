// prints anestors of given new

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
//method 2
bool PrintAncestorsv2(btnode *root, int key)
{
	if(!root)
		return false;
	if(root->data==key)
		return true;
	if(PrintAncestorsv2(root->left,key) || PrintAncestorsv2(root->right,key))
	{
		cout<<root->data<<" ";
		return true;
	}
	return false;
}
//method 1
void PrintAncestor(int arr[], int len)
{
	for(int i=0;i<len-1;i++)
	{
		cout<<arr[i];
	}
}

void GetAncestor(btnode *root, int arr[], int len, int key)
{
	if(!root)
		return;
	if(root)
	{
		arr[len++]=root->data;
	}
	if(root->data==key)
		PrintAncestor(arr,len);
	if(root->left)
		GetAncestor(root->left,arr,len,key);
	if(root->right)
		GetAncestor(root->right,arr,len,key);
}

int main()
{

  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  btnode *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
  int arr[500];

  //GetAncestor(root,arr,0, 7);
  PrintAncestorsv2(root,7);
  getchar();
  return 0;
}