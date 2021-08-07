#include <iostream>
using namespace std;

int sumOfFirstN(int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n;

    cout << "Enter number n: ";
    cin >> n;

    cout << "Sum of first " << n << " natural numbers is " << sumOfFirstN(n) << endl;
    return 0;
}