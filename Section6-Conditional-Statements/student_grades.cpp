#include <iostream>
using namespace std;

typedef int marks;

int main()
{
    marks m1, m2, m3;
    float total, avg;

    cout << "Enter marks for 3 subjects: ";
    cin >> m1 >> m2 >> m3;
    total = m1 + m2 + m3;
    avg = total / 3;

    if (avg >= 60)
    {
        cout << 'A';
    }
    else if (avg >= 35 && avg < 60)
    {
        cout << 'B';
    }
    else
    {
        cout << 'C';
    }

    return 0;
}