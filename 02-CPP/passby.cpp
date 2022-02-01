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

int main(){
    int a=3, b=5;
    cout << "Before the swap" << endl;
    cout << "a = " << a << " b = " << b << endl;

    swapval(a,b); 
    cout << "After the swap by value" << endl;
    cout << "a = " << a << " b = " << b << endl;

    //to be continued in the next class 

    return 0;
}