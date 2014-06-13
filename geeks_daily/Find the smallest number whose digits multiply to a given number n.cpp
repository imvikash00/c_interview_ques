/*
prob. Statement : Given a number ‘n’, find the smallest number ‘p’ such that if we multiply all digits of ‘p’, we get ‘n’. 
The result ‘p’ should have minimum two digits.
Examples:

Input:  n = 36
Output: p = 49 
// Note that 4*9 = 36 and 49 is the smallest such number

*/

/*
Algo:
For a given n, following are the two cases to be considered.
Case 1: n < 10 When n is smaller than n, the output is always n+10. For example for n = 7, output is 17. For n = 9, output is 19.

Case 2: n >= 10 Find all factors of n which are between 2 and 9 (both inclusive). The idea is to start searching from 9 so that the number of digits in result are minimized. For example 9 is preferred over 33 and 8 is preferred over 24.
Store all found factors in an array. The array would contain digits in non-increasing order, so finally print the array in reverse order.

*/

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
		cout<<head->data;
		head=head->next;
	}
}

void GetSmallest(int n, node **head)
{
	if(n<10)
	{
		push(head,n);
		push(head,1);
		return;
	}
	for(int i=9;i>1;i--)
	{
		if(n%i==0)
		{
			push(head,i);
			n = n/i;
			i=9;
		}
	}
}

int GetSmallest(int n)
{
	if(n<10)
		return n+10;
	int output=0,m=1;
	for(int i=9;i>1;i--)
	{
		if(n%i==0)
		{

			output += (m*i);
			m=m*10;
			n = n/i;
			i=9;
		}
	}
	if(n==1)
		return output;
	else
		return -1;
}

int main()
{
	node *head=NULL;
	int n;
	cout<<"Enter the no.";
	cin>>n;
	GetSmallest(n,&head);
	cout<<GetSmallest(n)<<endl;;	
	/*if(!head)
		cout<<"No such no.";
	else 
	{
		cout<<"The the no. is ";
		print(head);
		cout<<"\n";
	}*/
	return 0;
}