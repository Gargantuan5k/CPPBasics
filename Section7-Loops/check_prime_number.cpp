#include <iostream>
using namespace std;

bool checkPrimeNumber(int num)
{
    int sumFactors = 0;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sumFactors += i;
        }
    }

    return sumFactors == 1;     // Sum of factors is 1 when 1 is the only factor (prime number)
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checkPrimeNumber(num))
        cout << num << " is prime" << endl;
    else
        cout << num << " is not prime" << endl;
        
    return 0;
}