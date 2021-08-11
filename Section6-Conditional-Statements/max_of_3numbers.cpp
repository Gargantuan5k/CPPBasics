#include <iostream>
using namespace std;

int main()
{
    int a, b, c, _max;
    cout << "Enter 3 numbers: ";
    cin >> a >> b >> c;

    if (a > b && a > c)
    {
        _max = a;
    }
    else
    {
        if (b > c)
        {
            _max = b;
        }
        else
        {
            _max = c;
        }
    }

    cout << "Max of " << a << ", " << b << " and " << c << " is " << _max << endl;
    return 0;
}