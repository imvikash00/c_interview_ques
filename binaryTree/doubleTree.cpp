// each node is dublicated

/*
So the tree…

    2
   / \
  1   3
is changed to…

       2
      / \
     2   3
    /   /
   1   3
  /
 1

*/


#include <iostream>
 #include <cstdio>
 using namespace std;

 class btnode{
 public:
 	int data;
 	btnode *left;
 	btnode *right;
 	btnode(int data)
 	{
 		this->data = data;
 		this->left=NULL;
 		this->right = NULL;
 	}
 };


 btnode *newNode(int data)
 {
 	btnode *temp = new btnode(data);
 	return temp;
 }


void doubletree(btnode *root)
{
	if(!root)
		return;
	btnode *temp = newNode(root->data);
	btnode *rootleft = root->left;
	root->left = temp;
	temp->left=rootleft;
	doubletree(temp->left);
	doubletree(root->right);

}


void printInorder(btnode *root)
{
	if(!root)
		return ;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
 btnode *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  printf("Inorder traversal of the original tree is \n");
  printInorder(root);

  doubletree(root);
  
  printf("\n Inorder traversal of the double tree is \n");  
  printInorder(root);
   
  getchar();
  return 0;
}







