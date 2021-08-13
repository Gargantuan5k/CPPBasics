#include <iostream>
using namespace std;

int main()
{
    int dayNum;
    string dayStr;

    cout << "Enter day number: ";
    cin >> dayNum;

    if (dayNum == 1)
    {
        dayStr = "sun";
    }
    else if (dayNum == 2)
    {
        dayStr = "mon";
    }
    else if (dayNum == 3)
    {
        dayStr = "tue";
    }
    else if (dayNum == 4)
    {
        dayStr = "wed";
    }
    else if (dayNum == 5)
    {
        dayStr = "thu";
    }
    else if (dayNum == 6)
    {
        dayStr = "fri";
    }
    else if (dayNum == 7)
    {
        dayStr = "sat";
    }
    else
    {
        dayStr = "Invalid day number";
    }

    cout << dayStr;
    return 0;
}