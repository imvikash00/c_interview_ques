#include <iostream>
#include <cstdio>
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
	temp->next=*head_ref;
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

node *addll(node *head1, node *head2)
{
	
	int carry = 0,sum=0;;
	node *head=NULL;
	node dummy;
	head = &dummy;
	bool head1Null = false, head2Null = false;
	while(head1 || head2)
	{
		if(!head1)
			head1Null = true;
		if(!head2)
			head2Null = true;
		node *temp = new node;
		/*if(head1Null)
			sum = 0+head2->data+borrow;
		else if(head2Null)
			sum = head1->data+0+borrow;
		else
			sum = head1->data+head2->data+borrow;*/
		sum = carry + (head2Null?0:head2->data)+(head1Null?0:head1->data);
		if(sum>9)
		{
			temp->data = sum-10;
			carry = sum/10;
		} 
		else
		{
			temp->data = sum;
			carry = 0;
		}
		head->next = temp;
		head = temp;
		if(!head1Null)
			head1 = head1->next;
		if(!head2Null)
			head2=head2->next;
	}
	head->next = NULL;
	return dummy.next;
}

int main(void)
{
     node* res = NULL;
     node* first = NULL;
     node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is \n");
    print(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is \n");
    print(second);
 
    // Add the two lists and see result
    res = addll(first, second);
    printf("Resultant list is \n");
    print(res);
 
   return 0;
}