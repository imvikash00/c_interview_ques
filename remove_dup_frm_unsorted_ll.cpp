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
	node *temp = NULL;
	node *prev = head;
	for(;head;head = head->next)
	{
		prev = head;
		for(temp=head->next;temp;prev = temp,temp=temp->next)
		{

			if(temp->data==head->data)
			{
				prev->next=temp->next;
				delete temp;
				temp = prev;
			}
		}
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
	push(&head,10);
	push(&head,11);
	push(&head,12);
	push(&head,11);
	push(&head,11);
	push(&head,12);
	push(&head,10);
	print(head);
	remove_dup(&head);
	//del(&head);
	print(head);
	return 0;
}