#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter year: ";
    cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
            if (year % 400 == 0)
                cout << "Leap year";
            else
                cout << "Ordinary year";
        else
            cout << "Leap year";
    }
    else
    {
        cout << "Ordinary year";
    }

    return 0;
}