#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
};

void push(node **head_ref,int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = *head_ref;
	*head_ref=temp;
}

void remove_dup(node **head_ref)
{
	node *head = *head_ref;
	if(head==NULL || (head)->next==NULL)
		return;
	node *temp=NULL;
	while(head)
	{
		while((head)->data == ((head)->next)->data)
		{
			temp = (head)->next;
			(head)->next = (head)->next->next;
			delete temp;
			if((head)->next == NULL)
				break;
		}
		head = (head)->next;
	}
}

void print(node *head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

void del(node **head)
{
	node *temp = NULL;
	node *hea = *head;
	while(hea)
	{
		temp = hea;
		hea = hea->next;
		delete temp;
	}
	*head = hea;;

}

int main()
{
	node *head=NULL;
	push(&head,1);
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,1);
	push(&head,4);
	push(&head,4);
	print(head);
	remove_dup(&head);
	//del(&head);
	print(head);
	return 0;
}