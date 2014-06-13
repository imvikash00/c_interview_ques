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

bool detectloop(node *head)
{
	node *slow = head;
	node *fast = head;
	if(fast == fast->next)
	{
		cout<<fast->data;
		return true;
	}
	if(!fast)
		return false;

	while(fast && fast->next)
	{
		fast = fast->next;
		if(fast==slow){
			cout<<fast->data;
			return true;
		}
		fast = fast->next;
		slow = slow->next;
		if(fast==slow){
			cout<<fast->data;
			return true;
		}
	}
	return false;
}

node *loopstart(node *head)
{
	node *slow = head;
	node *fast = head;
	bool loopexsit=false;
	if(fast == fast->next)
		loopexsit = true;
	if(!fast)
		 loopexsit =false;

	while(fast && fast->next)
	{
		fast = fast->next;
		if(fast==slow){
			loopexsit=true;
			break;
		}
		fast = fast->next;
		slow = slow->next;
		if(fast==slow){
			loopexsit=true;
			break;
		}
	}
	if(loopexsit)
	{
		cout<<fast->data<<" "<<slow->data<<endl;
		fast=head;
		while(fast!=slow)
		{
			
			slow=slow->next;
			if(fast==slow)           //need to do this because if slow n fast as behind each other they will never meet if cond. in not checked
				break;
			fast=fast->next;
		}
		return slow;
	}
	return NULL;
}

//commenting to use loopstart() function in intersect_of_linkedlist.cpp

/*int main()
{
	node *head = NULL;
	 push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);

  
  head->next->next->next->next =   head->next->next->next ;
  if(detectloop(head))
  	cout<<(loopstart(head))->data;
  else
  	cout<<"loop doesnt exsits";

  return 0;
}*/
