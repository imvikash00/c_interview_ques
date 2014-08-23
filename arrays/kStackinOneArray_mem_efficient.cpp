#include <iostream>
#include <cstdio>
using namespace std;

class kstack{
	int *arr;
	int *top;
	int *next;
	int n,k;
	int free;
	public:
		kstack(int k1, int n1)
		{
			n = n1; k = k1;
			arr = new int[n];
			top = new int[k];
			next = new int[n];
			for(int i=0;i<n;i++)
				next[i]=i+1;
			next[n-1]=-1;
			free = 0;
			for(int i=0;i<k;i++)
				top[i] = -1;
		}

		bool isfull(){return (free ==-1);}
		bool isempty(int sn){
			return (top[sn] == -1);
		}
		void push(int item, int sn)
		{
			if(isfull())
			{
				cout<<"Stack Overflow\n";
				return;
			}
			int i = free;
			free = next[i];
			next[i]=top[sn];
			top[sn]=i;
			arr[i]=item;
		
		}	

		int pop(int sn)
		{
			if(isempty(sn))
			{
				cout<<"Stack underflow\n";
				return -1;
			}
			int i=top[sn];
			top[sn] = next[i];
			next[i]=free;
			free=i;
			return arr[i];
		}
};

int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kstack ks(k, n);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
 
    return 0;
}