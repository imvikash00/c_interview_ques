#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
};

void print(node *head)
{
	node *head1=head;
	while(head->next!=head1)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<head->data<<"->"<<head->next->data<<endl;
}
node *creatll(int n)
{
	int i=n;
	node *head = NULL;
	node *last=NULL;
	while(i>0)
	{
		node *temp = new node;
		temp->data = (i);
		temp->next = head;
		head = temp;
		if(i==n)
			last = head;
		i--;
	}
	last->next = head;
	//print(head);
	return head;
}

node *getlastmanstanding(node *head)
{
	while(head->next != head)
	{
		node *next=NULL;
		next = head->next;
		//cout<<head->data<<"->";
		head->next=head->next->next;
		delete next;
		head = head->next;
		//cout<<head->data<<endl;
	}
	//cout<<head->data<<endl;
	return head;
}


int main()
{
	int n;
	cin>>n;
	node *head=creatll(n);
	print(head);
	cout<<getlastmanstanding(head)->data<<endl;;

	return 0;
}