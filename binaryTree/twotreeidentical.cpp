#include <iostream>
#include <cstdio>
using namespace std;

class btnode{
public:
	int data;
	btnode *left;
	btnode *right;
};

btnode *newNode(int data)
{
	btnode *temp=new btnode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool identicalTrees(btnode *root1, btnode *root2)
{
	if(!root1 && !root2)
		return true;
	if(!root1 && root2)
		return false;
	if(root1 && !root2)
		return false;
	
	if(root1->data==root2->data)
		return identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right);
	else
		return false;

}

bool identicalTreesv2(btnode *root1, btnode *root2)
{
	if(!root2 && !root1)
		return true;
	if(root1 && root2)
	{
		return
		(
			root1->data == root2->data && identicalTreesv2(root2->left,root1->left) && identicalTreesv2(root2->right,root1->right)
		);
	}
	//if one is null
	return false;
}



int main()
{
    btnode *root1 = newNode(1);
    btnode *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 

    if(identicalTrees(root1, root2) && identicalTreesv2(root2,root1))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");

    getchar();
  return 0;
}