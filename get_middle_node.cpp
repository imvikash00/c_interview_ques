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

int count_occ(node *head, int val){
	int count = 0;
	while(head && head->next)
	{
		if(head->data == val)
			count++;
		head = head->next;
	}
	return count;
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

node *getmiddle_count(node *head)
{
	int count =1 ;
	node *temp = head;
	while(head && head->next)
	{
		count++;
		head = head->next;
	}
	int pos = count/2;
	cout<<"pos="<<pos<<endl;
	while(pos!=0)
	{
		temp=temp->next;
		pos--;
	}
	return temp;
}

node *getmiddle(node *head)
{
	node *slow, *fast;
	fast = head;
	slow = head;
	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast==NULL)
			return slow;
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
	node *head=NULL; //very imp. if u dont put such declaration then c the output
	push(&head,1);
	push(&head,2);
	push(&head,5);
	push(&head,5);
	push(&head,5);
	//push(&head,6);
	print(head);
	cout<<"==================\n";
	cout<<(getmiddle(head))->data<<endl<<(getmiddle_count(head))->data<<endl<<count_occ(head,5);
}