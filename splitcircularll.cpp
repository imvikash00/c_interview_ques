#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
};


 //or we could use a do while loop
void print(node *head)
{
	node *temp=head;
	/*if(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}*/
	do
	{
		cout<<head->data<<"->";
		head = head->next;
	}while(head!=temp);
	
	cout<<"NULL"<<endl;
}


void push(node **head_ref, node **tail_ref, int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = *head_ref;
	*head_ref = temp;
	if(*tail_ref == NULL)
		*tail_ref = *head_ref;
	else
	{
		(*tail_ref)->next = *head_ref;
	}
}

//first list is contained in head pointer and second is returned by the function

node * split(node *head)
{
	node *temp = head;
	node *slow = head;
	node *fast = head;
	while(fast->next != temp)
	{
		fast = fast->next;
		if(fast->next!=temp)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	node *next = slow->next;
	slow->next = temp;
	fast->next = next;
	return next;
}	

  int main(){
  /* Initialize lists as empty */
  node *head = NULL;
  node *tail = NULL;
  node *head2 = NULL;  
 
  /* Created linked list will be 12->56->2->11 */
  push(&head,&tail, 12); 
  push(&head, &tail,56);   
  push(&head,&tail, 2);   
  push(&head, &tail,11);
  push(&head, &tail,13);      
   
  print(head);
  /* Split the list */
  head2=split(head);
  
  //printf("\nFirst Circular Linked List");
  print(head);  
 
  //printf("\nSecond Circular Linked List");
  print(head2);  
   
  //getchar();
  return 0;
} 