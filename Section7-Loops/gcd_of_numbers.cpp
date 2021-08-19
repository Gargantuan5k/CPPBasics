#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{
    while (num1 != num2)
    {
        if (num1 > num2)
            num1 -= num2;
        else if (num2 > num1)
            num2 -= num1;
    }

    return num1;
}

int main()
{
    int num1, num2;
    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;

    cout << "The GCD of " << num1 << " and " << num2 << " is " << (gcd(num1, num2));
    return 0;
}