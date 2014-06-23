#include <iostream>
#include <cstdio>
using namespace std;

class node{
public:
	int data;
	node *next;
	node *prev;
};

void push(node **head_ref, int val)
{
	node *temp = new node;
	temp->data = val;
	if(*head_ref)
		(*head_ref)->prev = temp;
	temp->next = *head_ref;
	temp->prev = NULL;
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

void reverse(node **head_ref){
	node *head = *head_ref;
	while(head)
	{
		node *temp = head->prev;
		head->prev = head->next;
		head->next = temp;
		if(head->prev==NULL)
			*head_ref = head;

		head = head->prev;
		
	}
}

int main()
{
  /* Start with the empty list */
  node* head = NULL;
  
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 10->8->4->2 */
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);
  
  printf("\n Original Linked list ");
  print(head);
  
  /* Reverse doubly linked list */
  reverse(&head);
  
  //printf("\n Reversed Linked list ");
  print(head);           
  
  //getchar();
}