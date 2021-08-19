#include <iostream>
using namespace std;

void factorial(int num)
{
    int fac = 1;
    for (int i = 1; i <= num; i++)
    {
        fac *= i;
    }

    cout << fac << endl;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Factorial of " << num << " is ";
    factorial(num);

    return 0;
}