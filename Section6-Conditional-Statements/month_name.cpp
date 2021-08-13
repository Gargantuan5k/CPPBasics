#include <iostream>
using namespace std;

int main()
{
    int monthNum;
    string monthName;

    cout << "Enter month number: ";
    cin >> monthNum;

    if (monthNum == 1)
    {
        monthName = "Jan";
    }
    else if (monthNum == 2)
    {
        monthName = "Feb";
    }
    else if (monthNum == 3)
    {
        monthName = "Mar";
    }
    else if (monthNum == 4)
    {
        monthName = "Apr";
    }
    else if (monthNum == 5)
    {
        monthName = "May";
    }
    else if (monthNum == 6)
    {
        monthName = "Jun";
    }
    else if (monthNum == 7)
    {
        monthName = "Jul";
    }
    else if (monthNum == 8)
    {
        monthName = "Aug";
    }
    else if (monthNum == 9)
    {
        monthName = "Sep";
    }
    else if (monthNum == 10)
    {
        monthName = "Oct";
    }
    else if (monthNum == 11)
    {
        monthName = "Nov";
    }
    else if (monthNum == 12)
    {
        monthName = "Dec";
    }
    else
    {
        monthName = "Invalid month number";
    }

    cout << monthName;
    return 0;
}