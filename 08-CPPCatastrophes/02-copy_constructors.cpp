// this example illustrates the danger of relying on a copy constructor generated by C++

#include <iostream>
using namespace std;

typedef int Bar;
class Foo {
    public:
        Foo(int d=0) : m_Bar(d) {};
        // if not declared explicitly, C++ will always automatially generate a copy constructor
        // and an overloaded assignment operator for any class
        // Foo(const Foo &f);             
        // Foo& operator=(const Foo &f);  
        Bar getBar() { return m_Bar; }
    private:
        Bar m_Bar;
};

int ParseFoo(Foo f) {
    return f.getBar();
}

class DumbPtrHolder {
    public:
        DumbPtrHolder(int *p=0) : m_ptr(p) {}        
        ~DumbPtrHolder() { delete m_ptr; }
        friend void ParseDumbData(DumbPtrHolder d); 
    private:
        //DumbPtrHolder(DumbPtrHolder &d);
        int* m_ptr;
};

void ParseDumbData(DumbPtrHolder d) {
    for(int i=0; i< 3; i++) cout << d.m_ptr[i] << " ";
    cout << endl;
}

int main() {
// C++ will always automatially generate these two methods for any class
// Foo(const Foo& rhs)                  // copy constructor
// Foo& operator=( const Foo& rhs )     // overloaded assignment operator

// these methods will get invoked here:
    Foo foo1, foo2(5);
    Foo foo3(foo2);  // copy constructor
    Foo foo4 = foo3; // assignment

// Pass by value invokes copy constructor
    cout << "foo1 " << ParseFoo(foo1) << endl;
    cout << "foo2 " << ParseFoo(foo2) << endl;
    cout << "foo3 " << ParseFoo(foo3) << endl;
    cout << "foo4 " << ParseFoo(foo4) << endl;

// everything works great up to this point

    int *pData = new int[100];
    DumbPtrHolder Holder1(pData);
// no copy constructor declared in DumbPtrHolder
// a copy of the object will be created by performing a member-by-member copy
// result: two copies of pData pointer, which leads to calling the destructor twice
    ParseDumbData(Holder1);

// exploit:
// When a program calls free() twice with the same argument,
// the program's memory management data structures become corrupted.
// This corruption can cause the program to crash or, in some circumstances,
// cause two later calls to malloc() to return the same pointer.
// If malloc() returns the same value twice and the program later gives the attacker
// control over the data that is written into this doubly-allocated memory,
// the program becomes vulnerable to a buffer overflow attack.

// solution:
// If you have a class that controls resources, and a bitwise copy of the fields in the class
// would result in an unstable situation, then consider the following options:
// 1. Declare a private copy constructor and assignment operator with no implementation.
//    private:
//       Foo( const Foo& rhs ); // copy
//       Foo& operator=( const Foo& rhs ); // assignment
//    If a class external to the Foo class invokes one of these, you’ll get a compile error that a
//    private method has been invoked
// 2. Change the ParseDumbData: use call by reference instead of call by value
//    void ParseDumbData(DumbPtrHolder d) --> void ParseDumbData(DumbPtrHolder &d)
}