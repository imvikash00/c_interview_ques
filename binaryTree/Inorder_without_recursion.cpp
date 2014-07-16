#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

class btnode{
public:
	int data;
	btnode *left;
	btnode *right;
	btnode(int data)
	{
		this->data= data;
		this->left= NULL;
		 this->right=NULL;
	}
};

btnode *newNode(int data)
{
	btnode *temp = new btnode(data);
	return temp;
}

void print_iterative_inorder(btnode *root)
{
	stack<btnode *> stack;
	stack.push(root);
	while(!stack.empty())
	{

		while(root->left)
		{

			stack.push(root->left);
			root=root->left;
		}
		cout<<stack.top()->data<<" ";
		root= stack.top();
		stack.pop();
		while(root->right)
		{
			stack.push(root->right);
			root=root->right;
		}
	}


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

  print_iterative_inorder(root);

  getchar();
  return 0;
}

