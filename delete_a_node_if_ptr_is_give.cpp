#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
};


void push(node **head_ref, int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next=*head_ref;
	*head_ref = temp;
}

void deletenode(node **ptr){
	if(*ptr==NULL)
		return;
	if((*ptr)->next==NULL)
	{
		
		node *temp = *ptr;
		*ptr = (*ptr)->next;
		delete temp;
		return;
	}
	node *temp = (*ptr)->next;
	(*ptr)->data = temp->data;
	(*ptr)->next = temp->next;
	delete temp;
}

void print(node *head_ref)
{
	while(head_ref)
	{
		cout<<head_ref->data<<"->";
		head_ref = head_ref->next;

	}
	cout<<"NULL"<<endl;
}

int main()
{
	node *head = NULL;
	node *temp;
	push(&head,1);
	temp=head;
	push(&head,2);
	
	push(&head,3);
	
	push(&head,4);
	push(&head,5);
	
	print(head);
	deletenode(&temp);
	print(head);
	return 0;

}