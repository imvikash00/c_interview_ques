/*
	Basic approach is that we could have a array of 256 which vl store the count of each character
	Now again vl loop over the string and check if the character has count==1 in the array.
	But v could avoid the second loop by storing the index when the character was first encountered
	in the array itself becoz string might b large but array is jst 256 in length.
*/

//code for 2nd method

#include <iostream>
#include <cstdio>
	#include <cstdlib>
	#include <climits>
	using namespace std;

	#define No_of_chars 256
typedef struct countarray
{
	int count;
	int index;
}countarray;

//returns the count array
	countarray *getcountarray(char *str)
	{
		countarray *count;
		count=new countarray[No_of_chars];
		for(int i=0;i<No_of_chars;i++)
		{
			count[i].count=0;
			count[i].index=-1;
		}
		for(int i=0;*(str+i);i++)
		{
			(count[*(str+i)].count)++;
			if(count[*(str+i)].count==1)
				count[*(str+i)].index=i;
		}
		return count;
	}

	char firstnonrepeatingchar(char *str)
	{
		countarray *array;
		array = getcountarray(str);
		int result = INT_MAX;
		for(int i=0;i<No_of_chars;i++)
		{
			if(array[i].count==1 && result > array[i].index)
				result = array[i].index;
		}
		delete[] (array);
		return (str[result]);
	}

	int main()
	{
		char str[] = "geeksforgeeks";
		cout<<"First non repeating character is "<<firstnonrepeatingchar(str)<<endl;		
		return 0;
	}