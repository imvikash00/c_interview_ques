#include <iostream>
using namespace std;
#include "detect_loop.cpp"

/*class node{
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
*/
int count(node *head)  //if count=1 then while(head->next){}
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}

node *getintersection(node *head1, node *head2, int diff_len)
{
	while(diff_len--)
	{
		head1 = head1->next;
	}
	while(head1->next!=head2->next){
		head2=head2->next;
		head1=head1->next;
	}
	return head2->next;

}



int main()
{
	node *newNode;
	node *head1 = new node;
	head1->data = 10;
	node *head2 = new node;
	head2->data=3;
	newNode = new node;
	newNode->data = 6;
	head2->next=newNode;
	newNode=new node;
	newNode->data = 9;
	head2->next->next=newNode;
	newNode=new node;
	newNode->data=15;
	head1->next = newNode;
	head2->next->next->next=newNode;
	newNode=new node;
	newNode->data=30;
	head1->next->next=newNode;
	head1->next->next->next=head2;
	 //making a circular loop and then detect loop start
	cout<<(loopstart(head1))->data;



	// to use count sub. method uncomment
	/*int count1 = count(head1);
	int count2 = count(head2);
	if(count1>count2)
		cout<<(getintersection(head1,head2,count1-count2))->data;
	else
		cout<<(getintersection(head2,head1,count2-count1))->data;
	*/
	return 0;
}