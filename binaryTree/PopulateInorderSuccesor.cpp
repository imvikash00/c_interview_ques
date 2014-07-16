#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class btnode{
public:
	int data;
	btnode *left;
	btnode *right;
	btnode *next;
	btnode(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
		this->next=NULL;
	}
};

btnode *newnode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}


// need to use reverse inorder and remember previously visted node
void PopulateInorderSuccesor(btnode *root)
{
	if(!root)
		return;
	static btnode *temp=NULL;
	PopulateInorderSuccesor(root->right);
	root->next=temp;
	temp=root;
	PopulateInorderSuccesor(root->left);
}

//remove the use of static variable by paasing reference of the node
void PopulateInorderSuccesorv2(btnode *root, btnode **next_ref);

void populateNext(btnode *root)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    btnode *next = NULL;
 
    PopulateInorderSuccesorv2(root, &next);
}


void PopulateInorderSuccesorv2(btnode *root, btnode **next_ref)
{
	if(!root)
		return;
	PopulateInorderSuccesorv2(root->right,next_ref);
	root->next = *next_ref;
	*next_ref = root;
	PopulateInorderSuccesorv2(root->left,next_ref);
}

int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    btnode *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(12);
    root->left->left  = newnode(3);
 
    // Populates nextRight pointer in all nodes
    //PopulateInorderSuccesor(root);
 	populateNext(root);
    // Let us see the populated values
    btnode *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }
 
    return 0;
}