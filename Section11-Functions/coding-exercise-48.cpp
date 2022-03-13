// TODO: Write a function template to find max of two numbers
#include <iostream>

using namespace std;

template <class T>

T max_ (T a, T b)
{
    return (a > b ? a : b);
}

int main()
{
    cout << max_(10, 5) << endl;
    cout << max_(12.5f, 17.3f);

    return 0;
}