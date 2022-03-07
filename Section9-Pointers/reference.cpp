#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int x = 10;
    int &y = x; // y is a reference to x
    // int &y; is not correct, reference must be declared and initialised on the same line
    // &y = someOtherVariable; is also not correct, references are permanently tied to their variables.

    cout << x << endl;
    cout << y << endl; // same output as prev line

    x++; // value of x becomes 11
    y++; // value of x becomes 12
    cout << x << endl;

    cout << &x << " " << &y << endl; // same address

    cout << sizeof(x) << " " << sizeof(y) << endl; // both 4B (y does not occupy any extra memory, it is just another name for the same memory location as x)

    y = 20;
    cout << x << endl; // value will be 20

    return 0;
}