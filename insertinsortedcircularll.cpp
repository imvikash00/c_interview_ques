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
	if(temp!=NULL){
	do
	{
		cout<<head->data<<"->";
		head = head->next;
	}while(head!=temp);
	}
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

void sortedinsert(node **head, node *new_node)
{
	node *current = new node;
	current = *head;
	if(!*head)
	{
		*head = new_node;
		(*head)->next = new_node;
	}	
	else if((current)->data > new_node->data)
	{
		int temp = new_node->data;
		new_node->data = current->data;
		current->data = temp;
		new_node->next = current->next;
		current->next = new_node;
	}
	else
	{
		while((current)->next->data<new_node->data && current->next!=*head)
		{
			current = (current)->next;
		}
		new_node->next = (current)->next;
		current->next = new_node;
	}
}




 int main()
{
  int arr[] = { 12,56, 2, 11, 1, 90};
  int list_size, i;
 
  /* start with empty linked list */
  node *start = NULL;
  node *temp = NULL;
 
  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< 6; i++)
  {
    temp = new node;;
    temp->data = arr[i];
     print(start);
    sortedinsert(&start, temp);
  }
 
  print(start);
  return 0;
}