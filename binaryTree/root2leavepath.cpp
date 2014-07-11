#include <iostream>
#include <cstdio>
using namespace std;

class btnode
{
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
	~btnode();

	/* data */
};

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

void printpath(int len, int path[])
{
	for(int i=0;i<len;i++)
		cout<<path[i]<<" ";
	cout<<endl;
}

void root2leavepath(btnode *root, int pathlen, int path[])
{
	if(root)
	{
		path[pathlen]=root->data;
		pathlen++;
	}
	if(!root)
		return;
	if(!root->left && !root->right){
		printpath(pathlen,path);
		return;
	}
	root2leavepath(root->left,pathlen,path);
	root2leavepath(root->right,pathlen,path);

}


int main()
{
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  int path[5000];
  /* Print all root-to-leaf paths of the input tree */
  root2leavepath(root,0,path);

  getchar();
  return 0;
}