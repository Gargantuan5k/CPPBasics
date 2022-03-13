// TODO: Write overloaded functions for min of 2 int, min of 3 int, min of 2 float
#include <iostream>

using namespace std;

int min_(int a, int b)
{
    return (a < b ? a : b);
}

int min_(int a, int b, int c)
{
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

float min_(float a, float b)
{
    return (a < b ? a : b);
}

int main()
{
    cout << min_(10, 5);
    cout << min_(12, 7, 9);
    cout << min_(18.0f, 9.0f);

    return 0;
}