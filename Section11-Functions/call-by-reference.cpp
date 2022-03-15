#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;

    cout << "Before swapping\na = " << a << " b = " << b << endl;

    swap(a, b);

    cout << "After swapping\na = " << a << " b = " << b << endl;

    return 0;
}
/*
! NOTE
* When calling by reference, the compiler copies the called function into the scope of the calling function and treats it like an inline function.
* Therefore, if the function logic is complicated (loops etc), it may have bugs when called by reference.
* Also, calling such a function multiple times will result in it being copied multiple times; increasing compilation time & memory usage.
* So you should only call simple functions (such as the one in this example) by reference, or just avoid it altogether.
* To mutate passed values in a more complex function, you should call by address instead.
*/