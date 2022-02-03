// illustration of the difference in passing parameters 
// as pointers and as references

#include <iostream>
using namespace std;

// trivial non-working example of what happens when we attempt 
// to use pass-by-value to swap values of two variables
// using a function
void swapval(int x, int y){
    int z = x;
    x = y;
    y = z;
}

//swap two numbers using pass by pointer
void swapptr(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

//swap two numbers using pass by reference
void swapref(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}

/*
Reference variables vs pointer variables:
    * A pointer can be re-assigned while reference cannot, and must be assigned at initialization only.
    * Pointer can be assigned NULL directly, whereas reference cannot.
    * Pointers can iterate over an array, we can use ++ to go to the next item that a pointer is pointing to.
    * A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
    * A pointer to a class/struct uses '->'(arrow operator) to access it’s members whereas a reference uses a '.'(dot operator)
    * A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.
*/
int main(){
    int a=3, b=5;
    cout << "Before the swap" << endl;
    cout << "a = " << a << " b = " << b << endl;

    swapval(a,b); 
    cout << "After the swap by value" << endl;
    cout << "a = " << a << " b = " << b << endl;

    //to be continued in the next class 

    swapptr(&a,&b); 
    cout << "After the swap by pointer" << endl;
    cout << "a = " << a << " b = " << b << endl;

    swapref(a,b); 
    cout << "After the swap by reference" << endl;
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}