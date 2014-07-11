/*
Sorting can be used to reduce the time complexity to O(n*n). Following are the detailed steps.
1) Sort list b in ascending order, and list c in descending order.
2) After the b and c are sorted, one by one pick an element from list a and find the pair by traversing both b and c.
*/


#include <iostream>
using namespace std;

class node
{
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


/* A function to chech if there are three elements in a, b and c whose sum 
   is equal to givenNumber.  The function assumes that the list b is sorted
   in ascending order and c is sorted in descending order. */
bool find3musketeers(node *head1, node *head2, node *head3, int sum)
{
	int rem;
	node *temp2=head2, *temp3=head3;
	for(node *temp=head1;temp;temp=temp->next)
	{
		rem = sum-temp->data;
		cout<<"rem="<<rem<<endl;
		if(rem<0)
			return false;
		head2=temp2;
		head3=temp3;
		for(;head2 && head3;)
		{
			cout<<"req="<<(head2->data+head3->data)<<endl;
			if(rem == (head2->data + head3->data))
			{
				cout<<temp->data<<"->"<<head2->data<<"->"<<head3->data<<endl;
				return true;
			}
			else if(rem > (head3->data + head2->data))
			{
				head2 = head2->next;	
			}
			else
				head3 = head3->next;
		}	
	}	
	return false;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    node* headA = NULL;
    node* headB = NULL;
    node* headC = NULL;
 
    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);
 
    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
 
    /*create another sorted linked list 'c' 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);
 
    int givenNumber = 25;
 
    find3musketeers(headA, headB, headC, givenNumber);
 
    return 0;
}




