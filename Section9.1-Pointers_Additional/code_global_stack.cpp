#include <iostream>
using std::cout;
using std::endl;

int total;

int sq(int x)
{
    return x * x;
}

int sqOfSum(int x, int y)
{
    return sq(x + y);
}

int main()
{
    int a = 4, b = 8;
    total = sqOfSum(a, b);

    cout << "Square of sum is " << total << endl;

    return 0;
}