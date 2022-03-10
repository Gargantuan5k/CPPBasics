#include <iostream>

using namespace std;

int max_(int a, int b, int c)
{
    if (b > a && b > c)
        return b;
    if (c > a && c > b)
        return c;
        
    return a;
}

int main()
{
    cout << max_(60, 9, 69) << endl;

    return 0;
}