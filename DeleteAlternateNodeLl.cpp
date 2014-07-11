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
	temp->next = *head_ref;
	*head_ref = temp;
}

void print(node *head)
{
	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

void DeleteAlternateNodes_iterative(node *head)
{
	if(head == NULL || head->next == NULL)
		return;
	node *next = NULL;
	while(head->next)
	{
		next = head->next;
		head->next = next->next;
		delete next;
		head= head->next;
		if(head == NULL)
			break;
	}
}

void DeleteAlternateNodes_recursive(node *head)
{
	if(head == NULL || head->next == NULL)
		return;
	node *next = head->next;
	head->next = next->next;
	delete next;
	DeleteAlternateNodes_recursive(head->next);
}

int main()
{
	node *head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,6);
	print(head);
	DeleteAlternateNodes_recursive(head);
	//DeleteAlternateNodes_iterative(head);
	print(head);
	return 0;
}