#include <iostream>
#include <cmath>
using namespace std;

bool checkArmstrongNumber(int num)
{
    int sum = 0, digit, nonMutatedNum = num;

    while (num)
    {
        digit = num % 10;
        sum += (digit * digit * digit);
        num /= 10;
    }

    return sum == nonMutatedNum;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checkArmstrongNumber(num))
        cout << num << " is an armstrong number";
    else
        cout << num << " is not an armstrong number";

    return 0;
}