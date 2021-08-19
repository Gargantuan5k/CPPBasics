#include <iostream>
using namespace std;

void sumOfFirstN(int n)
{

    // Using for loop
    int sum1 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum1 += i;
    }

    // Using while loop
    int sum2 = 0, i = 1;
    while (i <= n)
    {
        sum2 += i;
        i++;
    }

    // A scalable solution using an algorithm (out of scope for now)
    int sum3 = (n * (n + 1)) / 2;

    cout << "Using for loop: " << sum1 << endl;
    cout << "Using while loop: " << sum2 << endl;
    cout << "Using a scalable method: " << sum3 << endl;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of first " << n << " natural numbers:" << endl;
    sumOfFirstN(n);
    
    return 0;
}