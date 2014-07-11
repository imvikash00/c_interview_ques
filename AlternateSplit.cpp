/*
 Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists ‘a’ and ‘b’. 
 The sublists should be made from alternating elements in the original list. So if the original list is 0->1->0->1->0->1 
 then one sublist should be 0->0->0 and the other should be 1->1->1.
*/

 #include <iostream>
 using namespace std;

 class node {
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

void AlternatingSplit(node **head,node **head1, node **head2)
{
	node *temp = *head;
	*head = NULL;
	while(temp)
	{

		*head1 = temp;
		*head2 = (temp)->next;
		temp = temp->next;
	}
}