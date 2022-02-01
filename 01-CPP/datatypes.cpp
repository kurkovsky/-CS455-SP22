#include <iostream>
using namespace std;

int main(){
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of bool : " << sizeof(bool) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;

    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of unsighed int : " << sizeof(unsigned int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;

    typedef unsigned char letter;
    letter letterA = 'A';
    cout << "Here's my letter A: " << letterA << endl;

    enum color {red, orange, yellow, green, blue, indigo, violet} c;
    c = blue;

    enum days {mon, tue, wed, thu, fri, sat, sun} day;
    day = thu;

    return 0;
}