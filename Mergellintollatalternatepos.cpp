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
	temp->data  = val;
	temp->next = *head_ref;
	*head_ref = temp;
}

void printList(node *head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}


void merge(node *head1, node **head2)
{
	node *temp = head1;
	while(head1 && *head2)
	{
		node *temp3 = (head1)->next;
		(head1)->next = *head2;
		node *temp2= (*head2)->next;
		(*head2)->next = temp3;
		head1 = temp3;
		*head2 = temp2;

	}
	head1 = temp;
}




int main()
{
     node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);

     printList(p);

     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
    
     printList(q);

     merge(p, &q);

     printList(p);

     printList(q);
return 0;
}