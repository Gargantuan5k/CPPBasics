#include <iostream>
using namespace std;

float _max(float a, float b)
{
    return a > b ? a : b;
    //* This is the same as:
    // if (a > b)
    // {
    //     return a;
    // }
    // else
    // {
    //     return b;
    // }
}

int main()
{
    float a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "The greater number of the two is " << _max(a, b);

    return 0;
}