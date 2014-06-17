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
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;;
}

node * segregateEvenOdd(node *head)
{
	node *last = NULL, *temp = head;
	node *prev = NULL, *next = NULL;;
	node *result = NULL;
	while(temp->next)
	{
		temp = temp->next;
	}
	last = temp;
	cout<<last->data<<endl;
	while(head!=temp->next)
	{
		if((head->data)%2 != 0)
		{
			next = head->next;
			last->next = head;
			last = last->next;
			head = next;
			if(prev)
				prev->next = next;
			cout<<last->next->data<<endl;

		}
		else
		{
			if(!result)
			{
				result = head;
				cout<<result->data<<endl;
			}
				
				prev = head;
				head = head->next;
		}
	}
	last->next = NULL;
	return result;
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    node* head = NULL;
 
    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 3);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
 
    //printf("\n Original Linked list ");
    print(head);
 
    head = segregateEvenOdd(head);
 
    //printf("\n Modified Linked list ");
    print(head);
 
    return 0;
}