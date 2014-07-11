#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
};

void Move2Front(node **head_ref)
{
	node *last = *head_ref;
	
	while(last->next->next)
	{
		last = last->next;
	}
	node *lastnode = last->next;
	last->next = NULL;
	lastnode->next = *head_ref;
	*head_ref = lastnode;

}

void push(node **head_ref, int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = *head_ref;
	*head_ref = temp;
}

void print(node *head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;

	}
	cout<<"NULL"<<endl;
}

int main()
{
node *head = NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
print(head);
Move2Front(&head);
print(head);
return 0;
}