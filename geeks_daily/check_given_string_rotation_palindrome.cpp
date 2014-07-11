/*
O(n2)
Try evry rotation of given string and then check if it is a palindrome of not




Algo. only
O(n)
create a temp string of size 2n. Copy the original 
string into it twice.Now find a pallindromic substring of lenght n in this temp string
if  size of substring =n then return true;
else false
Note: we can find whether there is a palindrome substring of size n or not in O(n) using 
Longest Palindrome substring;

*/
