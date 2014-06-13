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
	cout<<"NULL"<<endl;
}


/*void GetNewLLRecursive(node *head1, node *head2, node **newheadtail)
{
	if(head1 && head2)
	{
		if(head1->data == head2->data)
		{
			node *temp = new node;
			*newhead = temp;
			temp->data = head1->data;
			temp->next = NULL
			GetNewLLRecursive(head1->next, head2->next, temp);
		}
		else if(head1->data > head2->data)
			GetNewLLRecursive
	}
}
*/

node *GetNewLLRecursive(node *head1, node *head2)
{
	if(!head1 || !head2)
		return NULL;
	if(head1->data > head2->data)
		return GetNewLLRecursive(head1,head2->next);
	if(head1->data < head2->data)
		return GetNewLLRecursive(head1->next, head2);
	node *temp = new node;
	temp->data = head1->data;
	temp->next = GetNewLLRecursive(head1->next, head2->next);
	return temp;
}


void GetNewLL(node *head1, node *head2, node **newhead)
{
	while(head1 && head2)
	{
		if(head1->data == head2->data)
		{
			node *temp = new node;
			temp->data = head1->data;
			temp->next = *newhead;
			*newhead = temp;
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data > head2->data)
		{
			head2 = head2->next;
		}
		else
			head1 = head1->next;
	}
}


int main()
{
	struct node* a = NULL;
  struct node* b = NULL;
  struct node *intersect = NULL;
 
  /* Let us create the first sorted linked list to test the functions
   Created linked list will be 1->2->3->4->5->6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);                                  
  print(a);
  /* Let us create the second sorted linked list 
   Created linked list will be 2->4->6->8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);
  print(b);             
  //GetNewLL(a,b,&intersect);
  intersect = GetNewLLRecursive(a,b);
  cout<<"out";
  print(intersect);
  return 0;
}
