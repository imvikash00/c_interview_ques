// a tree can be folded if right and left subtree are structure was
// mirror image of each other


/*
Mthod 1:
1. convert left subtree to its mirror ie mirror(root->left);
2. check is structure is same for left and right and store result
3. convert to original tree using mirror(root->left)
4. return stored result
*/

/*
Method 2:
1. jst check if root->left and root->right are structure wise mirror images

*/


#include <iostream>
#include <cstdio>
#include <algorithm>
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
		this->left = NULL;
		this->right=NULL;
	}
	~btnode();
	
};

btnode *newNode(int data)
{
	btnode *temp=new btnode(data);
	return temp;
}
//converts tree to it mirror
void mirror(btnode *root)
{
	if(!root)
		return;
	mirror(root->left);
	mirror(root->right);
	btnode *temp=root->right;
	root->right = root->left;
	root->left = temp;
}

//method 2 trying---working
bool IsMirror(btnode *root1, btnode *root2)
{
	if(!root1 && !root2)
		return true;
	if((root1 && root2) && IsMirror(root1->left, root2->right) && IsMirror(root1->right, root2->left))
		return true;
	return false;
}

//method 2 wrapper
bool IsFoldablev2(btnode *root)
{
	if(!root)
		return false;
	return IsMirror(root->left,root->right);
}

bool IsStructuralSame(btnode *root1, btnode *root2)
{
	if(!root1 && !root2)
		return true;
	if((!root1 && root2) || (root1 && !root2))
		return false;
	return (root1 && root2) && IsStructuralSame(root1->left,root2->left) && IsStructuralSame(root1->right, root2->right);
}

bool IsFoldable(btnode *root)
{
	if(!root)
		return false;
	mirror(root->left);
	bool result=IsStructuralSame(root->left,root->right);
	mirror(root->left);
	return result;
}


int main(void)
{
  /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->left = newNode(5);

  if(IsFoldablev2(root) == true)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }

  getchar();
  return 0;
}