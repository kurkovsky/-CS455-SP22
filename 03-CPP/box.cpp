// a simple illustration of some object-oriented features of C++
// also: exception handling

#include <iostream>
#include <stdexcept>

using namespace std;

class Box {
private:
    int length;
    int width;
    int height;
    int id;
public:
    Box();
    Box(int l, int w, int h);
    ~Box();
    void Hi();
    int Volume();
    void Shrink(int factor);
};

Box::Box(){
    length = width = height = 0;
    id = rand() % 1000;      // a unique id in the range 0..99
}

Box::Box(int l, int w, int h){
    length = l;
    width = w;
    height = h;
    id = rand() % 1000;
}

Box::~Box(){
    cout << id <<": you are killing me!" << endl;
}

void Box::Hi() {
    cout << id << ": Hi, I'm a box (" << length << "x" << width << "x" << height << ")" << endl;
}

int Box::Volume(){
    return length*width*height;
}

Box* testBox() {    // illustrate how constructors/destructors work with dynamically allocated objects
    Box *x = new Box(1,2,3);
    x->Hi();
    return x;    
}

void Box::Shrink(int factor){ // divides all dimensions of the box by the value of factor
    if(factor==0) {           // exclude the possibility of division by zero
        throw runtime_error("Attempted to divide by zero");
    }

    // length = length / factor;
    length /= factor;
    width /= factor;
    height /= factor;
}
void scopeTest() {  // illustrate how constructors/destructors work with local objects
    Box c(4,5,6);
    c.Hi();
}

int main() {
    srand(time(nullptr));   // seed the random number generator
    Box A;
    Box B(30,40,50);
    A.Hi();
    B.Hi();
    cout << "Volume of A is " << A.Volume() << endl;
    cout << "Volume of B is " << B.Volume() << endl;

    try {
        B.Shrink(0);
    } catch(runtime_error &e) {
        cout << "Exception occurred: " << e.what() << endl;
    }
    B.Hi();

    Box *test = testBox();
    cout << "Volume of test is " << test->Volume() << endl;
    delete test;

    return 0;
}