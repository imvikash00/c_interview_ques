// check is given tree is subtree of another tree

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

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

bool isIdentical(btnode *root1, btnode *root2)
{
	if(!root1 && !root2)
		return true;
	if((root1->data== root2->data) && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right))
		return true;
	return false;
}

bool isSubtree(btnode *root1, btnode *root2)
{
	if(!root1 && !root2)
		return true;
	if(isIdentical(root1 , root2))
		return true;
	else
		return isSubtree(root1->left, root2) || isSubtree(root1->right,root2);
}

int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    btnode *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    btnode *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if( isSubtree(T, S) )
        printf("Tree S is subtree of tree T");
    else
        printf("Tree S is not a subtree of tree T");
 
    getchar();
    return 0;
}