#include <iostream>
using namespace std;

int IterativeBinarSearch(int a[], int key ,int low ,int high)
{
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
		{
			high = mid-1;
		}
		else
			low = mid+1;
	}
}

int RecursiveBinarySearch(int a[], int key, int low, int high)
{
	if(low<=high)
	{
		int mid = (low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			return RecursiveBinarySearch(a,key,low, mid-1);
		return RecursiveBinarySearch(a, key , mid+1,high);
	}
	else
		return -1;

}


int main()
{
	int a[10]={1,2,4,5,6,7,8,12,111};
	cout<<IterativeBinarSearch(a,12,0,9)<<endl;;
	cout<<RecursiveBinarySearch(a,12,0,9)<<endl;
}