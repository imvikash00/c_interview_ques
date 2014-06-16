/*We can always use pointer arithmetic to change the beginning part.
For example (str + i) gives us address of i’th character. To limit the ending, we can use width specifier 
in printf which can be passed as an argument when * is used in format string.
*/

#include <iostream>
#include <cstdio>
using namespace std;
//prints substring of str[] between low and high both inclusive
void substring(char s[], int low, int high){

printf("%.*s\n",high-low+1,s+low);
}

int main()
{
char s[]= "Thisisfun";
substring(s,3,5);
return 0;


}
