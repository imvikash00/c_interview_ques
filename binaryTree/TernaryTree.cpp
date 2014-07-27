#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 50
using namespace std;

class node
{
public:
	char data;
	unsigned isEndOfString:1 ;
	node *left;
	node *eq;
	node *right;
};

node *newNode(char data)
{
	node *temp=new node;
	temp->data=data;
	temp->right=temp->left=temp->eq=NULL;
	temp->isEndOfString=0;
	return temp;
}

void insert(node **root, char *word)
{
	if(!(*root))
		*root=newNode(*word);
	if(*word < (*root)->data)
		insert(&(*root)->left,word);
	else if (*word > (*root)->data)
		insert(&(*root)->right,word);
	else
	{
		if(*(word+1))
			insert(&(*root)->eq,word+1);
		else
			(*root)->isEndOfString=1;
	}
}


void traverseTSTUtil(node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);

        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
int searchTST(node *root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    else if (*word > (root)->data)
        return searchTST(root->right, word);

    else
    {
        if (*(word+1) == '\0')
            return root->isEndOfString;

        return searchTST(root->eq, word+1);
    }
}

int main()
{
    node *root = NULL;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");

    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    searchTST(root, "cat")?  printf("Found\n"): printf("Not Found\n");

    return 0;
}