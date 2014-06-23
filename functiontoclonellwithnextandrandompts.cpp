#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node *random;

	/* data */
};

node *clonell(node *head)
{
	node *current  = head;
	node *clone=NULL;
	while(current)
	{
		node *temp=new node;
		temp->data = current->data;
		temp->next = current->random;
		current->random = temp;
		temp->random = NULL;
		current = current->next;
	}
	current = head;
	while(current)
	{
		node *temp = current->random;
		temp->random = temp->next->random;  
		//if i do this now then would b able to rpair the original list
		//temp->next = current->next->random;
		current = current->next;
	}
	current = head;
	while(current)
	{
		node *temp = current->random;
		if(!clone)
			clone=temp;
		node *next = current->next->random;
		current->random = temp->next;
		temp->next=next;
	}
	return clone;

}

int main(){
	return 0;
}