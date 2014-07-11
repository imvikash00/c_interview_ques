#include <iostream>
#include <cstdio>
using namespace std;

class btnode
{
public:
	int data;
	btnode* left;
	btnode* right;

	btnode(int data)
	{
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

void deletetree(btnode *root)
{
	if(!root)
		return;
	deletetree(root->left);
	deletetree(root->right);
	cout<<"deleting "<<root->data<<endl;
	delete root;
}



int main()
{
    btnode *root = newNode(1);
    cout<<root->data;
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
  	deletetree(root);

    //printf("Hight of tree is %d", treesize(root));
  
    getchar();
    return 0;
}