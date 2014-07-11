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

void print(node *head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

void PairWiseSwap(node **head)
{
	if(*head==NULL || (*head)->next==NULL)
		return;
	node *current = *head;
	node *next = current->next;
	*head = next;
	node *prev = NULL;
	for(;current->next;current=current->next, next = current->next)
	{
		cout<<"current "<<current->data<<endl;
		cout<<"next "<<next->data<<endl;
		current->next = next->next;
		next->next = current;
		if(prev)
		{
			prev->next = next; 
		}
		prev = current;
		//cout<<"current "<<current->data<<endl;
		//cout<<"next "<<next->data<<endl;
		if(next->next==NULL || !current->next)
			break;
	}
}

int main()
{
  struct node *start = NULL;

  /* The constructed linked list is:
   1->2->3->4->5 */
  
  //push(&start, 7);
  //push(&start, 6);
  //push(&start, 5);
  //push(&start, 4);
  //push(&start, 3);
  push(&start, 2);
  push(&start, 1);

  //printf("\n Linked list before calling  pairWiseSwap() ");
  print(start);

  PairWiseSwap(&start);

  //printf("\n Linked list after calling  pairWiseSwap() ");
  print(start);
  return 0;
}