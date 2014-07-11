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

//TODO: need an iterative procedure for merge funtion

//Recursive implementation of merge function
node *Merge(node *a, node *b)
{
	if(!a && !b)
		return NULL;
	if(!a)
		return b;
	if(!b)
		return a;
	node *head=NULL;
	if(a->data <= b->data)
		{
			head = a;;
			head->next = Merge(a->next, b);
			

		}
		else
		{
			head= b;
			head->next=Merge(a,b->next);
			
		}

	return head;
}


//if odd length then extra node goes to first linked list
//make slow stop one node before the mid of the ll by starting
// fast from head->next;

void split(node *head, node **a, node **b)
{
	if(!head)
		return;
	if(!head->next)
	{
		*a = head;
		return ;
	}
	node *fast = head->next;
	node *slow = head;
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

void MergeSort(node **head_ref)
{
	if(*head_ref == NULL || !(*head_ref)->next)
		return ;
	node *head = *head_ref;
	node *a=NULL, *b=NULL;
	split(head,&a,&b);
	//print(a);print(b);
	MergeSort(&a);
	MergeSort(&b);
	*head_ref = Merge(a,b);
	//print(*head_ref);
}


int main()
{
  node *a = NULL;
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);
  print(a);
  MergeSort(&a);
  print(a);
  return 0;
}