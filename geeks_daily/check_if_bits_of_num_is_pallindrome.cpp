#include <iostream>
using namespace std;

//function to check if kth bit is set or not

bool kthbitset(unsigned int x, unsigned int k)
{
	return ((x>>(k-1))&0x01);
}

bool isPalindrome(unsigned int x)
{
//l is left most bit and r is right most bit
	//r is calculate using sizeof 

	int l=1, r=sizeof(x)*8;  //get the no. of bits in x
	while(l<=r)
	{
		if(kthbitset(x,l)!=kthbitset(x,r)) //if last n first bit is not same 
										// return false 
			return false;
		l++;r--;
	}
	return true;  //if no bit is diff return true

}

int main()
{
	unsigned int x = 3<<15 + 1<<16;
	x = 1<<31 + 1;
	if(isPalindrome(x))
		cout<<"this is Palindrome"<<endl;
	return 0;
}