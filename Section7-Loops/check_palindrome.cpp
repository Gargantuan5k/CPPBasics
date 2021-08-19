#include <iostream>
using namespace std;

bool isPalindrome(int num)
{
    int digit, reverse = 0, nonMutatedNum = num;
    while (num)
    {
        digit = num % 10;
        num /= 10;
        reverse = (reverse * 10) + digit;
    }

    return reverse == nonMutatedNum;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << (isPalindrome(num) ? "Palindrome" : "Not Palindrome");

    return 0;
}