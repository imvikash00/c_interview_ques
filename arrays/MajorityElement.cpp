#include <iostream>
#include <cstdlib>
using namespace std;

//basic using 2 for loops
int MajorityElev1(int a[], int len)
{
	int maj = 0;
	int prevcount=-1;
	for(int i=0;i<len;i++)
	{

		int count=0;
		for(int j=0;j<len;j++)
		{
			if(a[j]==a[i])
				count++;
		}
		if(count>prevcount)
		{
			prevcount = count;
			maj=i;
		}

	}	
	return a[maj];
}

bool ismajor(int a[],int x, int len)
{
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]==x)
			count++;
	}
	if(count>len/2)
		return true;
	else
		return false;

}

int MajorityElev2(int a[], int len)
{
	int maj=a[0];
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(count==0)
			maj = a[i];
		if(maj == a[i])
			count++;
		else
			count--;

	}
	cout<<maj;
	if(ismajor(a,maj,len))
		return maj;
	else
		return -1;
}

int main()
{
    int a[] = {1, 3, 3, 3, 2};
    cout<<MajorityElev1(a, 5);
    //getchar();
    return 0;
}