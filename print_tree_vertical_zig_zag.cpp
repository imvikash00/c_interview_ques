#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node* root,int verticalLevel,map< int,vector<int> >& m) {
	if(!root) return;
	m[verticalLevel].push_back(root->key);
	getVerticalOrder(root->left,verticalLevel-1,m);
	getVerticalOrder(root->right,verticalLevel+1,m);
}

void printVerticalOrder(Node* root) {
	map < int,vector<int> > m;
	int verticalLevel = 0;
	getVerticalOrder(root,verticalLevel,m);

	map< int,vector<int> > :: iterator it;
	
	int flip=1;
	for(it=m.begin();it!=m.end();it++) {
		for(int i=0;i<it->second.size()&&flip;++i) {
			cout<<it->second[i]<<" ";
		}
		for(int i=it->second.size()-1;i>=0&&!flip;i--) {
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
		flip=1-flip;
	}
}

int main() {

	Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);

    return 0;
}
