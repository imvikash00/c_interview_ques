#include <iostream>
#include <cstdlib>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

void findpair(int a[], int x)
{
	int len = (sizeof(a))/sizeof(a[0]);
	len = (&a)[1] - a; //another way  to find the length of the array
	cout<<len; //not working though code is correct;
	len = 6;
	qsort(a,len, sizeof(int),comparator);
	
	int i,j;
	for(i=0,j=len-1;i<=j;)
	{
		if(a[i]+a[j]==x)
		{
			cout<<endl<<a[i]<<"+"<<a[j]<<"="<<x<<endl;
			return ;
		}
		else if((a[i]+a[j]) > x)
			j--;
		else
			i++;
	}
	cout<<"NO such element exist"<<endl;
}

//if the binmap[temp]==1 then temp is present in a 
// so a[i] and temp is the required pair

void findpairv2(int a[], int x,int len)
{
	int binmap[1000]={0}; //needs to know the range of no. say, 10000
	for(int i=0;i<len;i++)
	{
		int temp = x-a[i];
		if(temp>=0 && binmap[temp]==1)
			cout<<temp <<"+"<<a[i]<<endl;
		binmap[a[i]]=1;
	}
	
}

int main()
{
	int a[] = {1, 4, 45, 6, 10, -8};
	cout<<(((&a)[1])-a);
	int x;
	cin>>x;
	findpairv2(a,x,sizeof(a)/sizeof(a[0]));
	return 0;
}

