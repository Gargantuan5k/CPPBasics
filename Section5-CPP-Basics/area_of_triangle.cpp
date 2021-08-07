#include <iostream>
#include <cmath>

using namespace std;

int area(int base, int height)
{
    // a = ½bh
    return (base * height) / 2;
}

int areaHeronsFormula(int a, int b, int c)
{
    // a = √(s(s - a)(s - b)(s - c))
    int s = (a + b + c) / 2;
    int area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

int main()
{
    int a, b, c, base, height;
    char choice;

    cout << "1/2 BH formula (B) (needs base and height) or Heron's formula (H) (needs sides)?: ";
    cin >> choice;

    if (choice == 'B')
    {
        cout << "Enter base and height: ";
        cin >> base >> height;
        cout << "Area is " << area(base, height);
    }
    else
    {
        cout << "Enter sides a, b, c: ";
        cin >> a >> b >> c;
        cout << "Area is " << areaHeronsFormula(a, b, c);
    }

    return 0;
}