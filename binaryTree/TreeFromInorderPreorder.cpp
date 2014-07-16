#include <iostream>
#include <cstdio>
using namespace std;

class btnode
{
public:
	char data;
	btnode *left;
	btnode *right;
	btnode(char data)
	{
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	}
	~btnode()
	{
		//delete this;
	}
	
};

btnode *newNode(char data)
{
	btnode *temp = new btnode(data);
	return temp;
}

int findinorder(char inorder[], char searchchar, int startindex, int endindex)
{
	for(int i=startindex;i<=endindex;i++)
	{
		if(inorder[i]==searchchar)
			return i;
	}

}

btnode * CreateTree(char preorder[], char inorder[], int startindex, int endindex)
{
	static int preorderindex = 0;
	if(startindex>endindex)
		return NULL;
	
	btnode *temp = newNode(preorder[preorderindex]);//new btnode(preorder[preorderindex]);
	preorderindex++;
	if(startindex==endindex)
		return temp;
	int j = findinorder(inorder,temp->data,startindex,endindex);

	
	temp->left = CreateTree(preorder,inorder,startindex,j-1);
	temp->right=CreateTree(preorder,inorder,j+1,endindex);
	return temp;
}

void inorder(btnode *head)
{
	if(head)
	{
		inorder(head->left);
		cout<<head->data<<" ";
		inorder(head->right);
	}
	else
	  return;
}

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  btnode *root = CreateTree(in, pre, 0, 5);

  /* Let us test the built tree by printing Insorder traversal 
  */printf("\n Inorder traversal of the constructed tree is \n");
 	inorder(root);
  getchar();
}

/*#include<cstdio>
#include<cstdlib>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
/*struct node
{
  char data;
  struct node* left;
  struct node* right;
};

/* Prototypes for utility functions */
/*int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);

/* Recursive function to construct binary of size len from
   Inorder traversal in[] and Preorder traversal pre[].  Initial values
   of inStrt and inEnd should be 0 and len -1.  The function doesn't
   do any error checking for cases where inorder and preorder
   do not form a tree */
/*struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;

  if(inStrt > inEnd)
     return NULL;

  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  /*struct node *tNode = newNode(pre[preIndex++]);

  /* If this node has no children then return */
  /*if(inStrt == inEnd)
    return tNode;

  /* Else find the index of this node in Inorder traversal */
  /*int inIndex = search(in, inStrt, inEnd, tNode->data);

  /* Using index in Inorder traversal, construct left and
     right subtress */
 /* tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);

  return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
   The function assumes that value is present in in[] */
/*int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
*/
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
/*struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
*/
/* This funtcion is here just to test buildTree() */
/*void printInorder(struct node* node)
{
  if (node == NULL)
     return;

  /* first recur on left child */
  /*printInorder(node->left);

  /* then print the data of node */
  //printf("%c ", node->data);

   //now recur on right child 
  //printInorder(node->right);//
//}

/* Driver program to test above functions */
/*int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  //printf("\n Inorder traversal of the constructed tree is \n");
  //printInorder(root);
  //getchar();
//}*/
//*/