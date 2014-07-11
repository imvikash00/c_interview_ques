/*
Consider the following simple C++ code with normal pointers.

MyClass *ptr = new MyClass();
ptr->doSomething();
//  We must do delete(ptr) to avoid memory leak
Using smart pointers, we can make pointers to work in way 
that we don’t need to explicitly call delete. Smart pointer 
is a wrapper class over a pointer with operator like * and -> overloaded. 
The objects of smart pointer class look like pointer, but can do many things 
that a normal pointer can’t like automatic destruction (yes, we don’t have to 
explicitly use delete), reference counting and more.
The idea is to make a class with a pointer, destructor and overloaded operators like * and ->. 
Since destructor is automatically called when an object goes out of scope, the dynamically alloicated memory 
would automatically deleted (or reference count can be decremented). 
*/
/*
	Usage:
int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}
*/


#include <iostream>
using namespace std;

template <class T>
class SmartPtr
{
	T *ptr;
public:
	explicit SmartPtr(T *p = NULL) { ptr = p;}
	~SmartPtr() {delete ptr;}
	T & operator * () {return *ptr;}
	T *operator -> () {return ptr;}
};
