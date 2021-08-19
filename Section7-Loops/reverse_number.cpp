#include <iostream>
#include <cmath>
using namespace std;

void reverseNumber(int num)
{
    while (num)
    {
        cout << num % 10;
        num /= 10;
    }
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;   

    cout << num << " -> ";
    reverseNumber(num);

    return 0;
}