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

bool isPalindrome(node *head, node **head_ref)
{
	if(head==NULL)
		return true;
	if(isPalindrome(head->next,&(*head_ref)))
	{
		cout<<head->data<<" "<<(*head_ref)->data<<endl;
		if(head->data == (*head_ref)->data)
		{
			
			*head_ref = (*head_ref)->next;
			return true;
		}

		return false;
	}
	return false;
}

void print_reverse_ll(node *head)
{
	if(head==NULL)
		return;
	print_reverse_ll(head->next);
	cout<<head->data<<endl;
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
	push(&head,2);
	push(&head,1);
	push(&head,1);
	node *temp = head;
	//print_reverse_ll(head);
	print(head);
	if(isPalindrome(head,&temp))
		cout<<" is a palindrome";
	else
		cout<<" is not a palindrome";
	return 0;
}