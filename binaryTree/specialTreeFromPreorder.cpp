/*
Given an array ‘pre[]‘ that represents Preorder traversal of a spacial binary tree where every node 
has either 0 or 2 children. One more array ‘preLN[]‘ is given which has only two possible values ‘L’ and ‘N’. 
The value ‘L’ in ‘preLN[]‘ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates 
that the corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.
*/

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

btnode* createTree(int pre[], char preLN[], int *sindex, int len)
{
	if(*sindex>len)
		return NULL;

	btnode *temp=newNode(pre[*sindex]);
	*sindex+=1;
	if(preLN[*sindex-1]=='N')
	{
		temp->left=createTree(pre,preLN,sindex, len);
		temp->right=createTree(pre,preLN,sindex,len);
	}
	return temp;

}

void printPreorder (btnode* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    /* first recur on left child */
    printPreorder (node->left);

    /* then print the data of node */
    

    /* now recur on right child */
    printPreorder (node->right);
}

/* Driver function to test above functions */
int main()
{
    btnode *root = NULL;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15,23};
    char preLN[] = {'N', 'N', 'L', 'L', 'N','L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    // construct the above tree
    int sindex=0;
    root = createTree(pre, preLN, &sindex,5);

    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printPreorder (root);

    return 0;
}