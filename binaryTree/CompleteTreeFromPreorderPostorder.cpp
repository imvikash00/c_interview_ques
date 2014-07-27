// If a tree is complete i.e has two or zero nodes then tree can be constructed from preorder and postorder
/*

         1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \  
8    9 
Let us consider the two given arrays as pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
In pre[], the leftmost element is root of tree. Since the tree is full and array size is more than 1. The value next to 1
 in pre[], must be left child of root. So we know 1 is root and 2 is left child. How to find the all nodes in left 
 subtree? We know 2 is root of all nodes in left subtree. All nodes before 2 in post[] must be in left subtree.
 Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree, and the elements {6, 7, 3} are in right subtree.
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

int searchpost(int key,int post[], int spost, int epost)
{
	for(int i=spost;i<=epost;i++)
	{
		if(post[i]==key)
			return i;
	}
}


btnode *constructtree(int pre[], int post[], int spost, int epost, int size)
{
	static int preindex=0;
	//cout<<"preindex="<<preindex<<endl;
	if(preindex>=size || spost>epost)
		return NULL;
	
	btnode *temp=newNode(pre[preindex]);
	++preindex;
	if(spost==epost)
		return temp;
	int i=searchpost(pre[preindex],post,spost,epost);
	
	temp->left=constructtree(pre,post,spost,i,size);
	temp->right=constructtree(pre,post,i+1,epost-1,size);  //need to pass epost-1 bexon need to exclude the root
	return temp;
}


void printInorder (btnode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );

    btnode *root = constructtree(pre, post,0, size-1,size);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}