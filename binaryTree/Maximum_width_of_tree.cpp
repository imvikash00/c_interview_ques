// Maximum of total no. of nodes at each level
// could be easily done with level order traversal

//goin to do with preorder

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class btnode{
public:
	int data;
	btnode *left;
	btnode *right;
	btnode(int data)
	{
		this->data;
		this->left=NULL;
		this->right=NULL;
	}
};


btnode *newNode(int data){
	btnode *temp=new btnode(data);
	return temp;
}

int height(btnode* root)
{
	if(!root)
		return 0;
	else 
		return (max(height(root->right),height(root->left))+1);
}

void getwidtheachlevel(btnode *root, int count[], int level)
{
	if(root)
	{
		count[level]++;
		getwidtheachlevel(root->left,count,level+1);
		getwidtheachlevel(root->right,count,level+1);
	}
}


int getwidth(btnode *root)
{
	if(!root)
		return 0;
	int h= height(root);
	int *count = new int[h];
	for(int i=0;i<h;i++)
		count[i]=0;
	int level=0;
	getwidtheachlevel(root, count, level);
	int max=-1;
	for(int i=0;i<h;i++)
		if(max < count[i])
			max=count[i];
	return max;
}


int main()
{
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);
  root->right->right->left  = newNode(6);
  root->right->right->right  = newNode(7);

  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8
              /  \
             6   7
  */
  printf("Maximum width is %d \n", getwidth(root));
  getchar();
  return 0;
}