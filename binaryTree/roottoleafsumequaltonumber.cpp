#include <iostream>
#include <cstdio>
using namespace std;

class btnode
{
public:
	int data;
	btnode * left;
	btnode *right;
	btnode(int data)
	{
		this->data=data;
		this->left = NULL;
		this->right = NULL;
	}
	~btnode()
	{
		delete this;
	}
	
};


btnode *newnode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

bool cheksum(int path[],int pathlen, int sum)
{
	int sumpath = 0;
	for(int i=0;i<pathlen;i++)
		sumpath+=path[i];
	if(sumpath == sum)
	{
		cout << "Path is "<<endl;
		for(int i=0;i<pathlen;i++)
			cout<<path[i]<<" ";
		return true;
	}
	else
		return false;
}

bool findpath(int sum,btnode* root, int path[], int pathlen)
{
	if(!root)
		return false;
	if(root)
	{
		//path[pathlen]=root->data;
		//pathlen++;
		//or
		pathlen+=root->data;
	}
	if(!root->right && !root->left)
	{
		//return cheksum(path,pathlen,sum);
		//or
		//	
		return (sum==pathlen);
	}
	return findpath(sum,root->right,path,pathlen) || findpath(sum,root->left,path,pathlen);
}


bool hasPathSum(btnode* node, int sum)
{
  /* return true if we run out of tree and sum==0 */
  if (node == NULL)
  {
     return (sum == 0);
  }
 
  else
  {
    bool ans = 0;  
 
    /* otherwise check both subtrees */
    int subSum = sum - node->data;
 
    /* If we reach a leaf node and sum becomes 0 then return true*/
    if ( subSum == 0 && node->left == NULL && node->right == NULL )
      return 1;
 
    if(node->left)
      ans = ans || hasPathSum(node->left, subSum);
    if(node->right)
      ans = ans || hasPathSum(node->right, subSum);
 
    return ans;
  }
}



int main()
{

  int sum = 21;

  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
    int path[500];
    int pathlen=0;
 btnode *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);

  root->left->right = newnode(5);
  root->right->left = newnode(9);

  if(findpath(sum,root,path, pathlen))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);

  getchar();
  return 0;
}