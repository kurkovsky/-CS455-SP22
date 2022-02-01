#include <iostream>
using namespace std;

int main(){
    /*  primitive built-in data types:
    Boolean	                bool
    Character	            char
    Integer	                int
    Floating point	        float
    Double floating point	double
    Valueless	            void
    Wide character	        wchar_t -- platform specific */
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of bool : " << sizeof(bool) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;

/* type modifiers:
    signed
    unsigned
    short
    long */
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of unsighed int : " << sizeof(unsigned int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;

/* new type declaration with typedef */
    typedef unsigned char letter;
    letter letterA = 'A';
    cout << "Here's my letter A: " << letterA << endl;

/* enumerated types */
    enum color {red, orange, yellow, green, blue, indigo, violet} c;
    c = blue;

    enum days {mon, tue, wed, thu, fri, sat, sun} day;
    day = thu;

/* integer literals
    21      decimal
    0234    octal
    0x3A    hexidecimal
    51u     unsigned int
    9879879879875l     long
    30ul    unsigned long */
    
    return 0;
}