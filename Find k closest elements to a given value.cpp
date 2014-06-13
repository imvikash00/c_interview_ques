#include <iostream>
using namespace std;


int bsearch(int a[], int key, int low, int high)
{
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			high = mid-1;
		else 
			low = mid+1;
	}
}

int main()
{

	int a[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<bsearch(a,10,0,9);
	return 0;

}