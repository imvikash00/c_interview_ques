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
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

void recursiveReverse(node **head, node **prev)
{
	if(!(*head)){
		cout<<(*prev)->data<<endl;
		*head = *prev;
		cout<<"===="<<(*head)->data<<endl;
		return;
	}
	static int i = 1;
	if(i==1)
	{
		cout<<"first time"<<endl;
		//*prev=NULL;
	}
	else
		*prev = (*prev)->next;
	i++;
	cout<<(*prev)->data;	
	recursiveReverse(&((*head)->next),&(*prev));
	cout<<"----"<<(*head)->data<<" "<<(*prev)->data<<endl;;
	(*head)->next = *prev;
}

node *IterativeReverse(node *head)
{
	if(!head || !(head->next))
		return head;
	node *temp = NULL;
	node *current = head;
	/*node *next = head->next;
	while(current)
	{
		current->next = temp;
		temp = current;
		current = next;
		if(current==NULL)
			break;
		next = next->next;
	}*/ // OR

	node *next ;
	while(current)
	{
		next = current->next;
		current->next = temp;
		temp = current;
		current = next;
	}
	return temp;
}


int main(){
	node *head=NULL;
	
	push(&head,1);
	push(&head,2);
	//push(&head,3);
	print(head);
	node *temp = head;
	//recursiveReverse(&head,&temp);
	head = IterativeReverse(head);
	print(head);
}