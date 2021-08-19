#include <iostream>
using namespace std;

bool checkPerfectNumber(int num)
{
    int sumFactors = 0;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sumFactors += i;
        }
    }

    return sumFactors == num;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checkPerfectNumber(num))
    {
        cout << num << " is a perfect number." << endl;
    }
    else
    {
        cout << num << " is not a perfect number." << endl;
    }

    return 0;
}