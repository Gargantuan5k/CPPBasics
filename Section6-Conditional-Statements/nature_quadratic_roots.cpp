#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, disc, root1, root2;
    cout << "Enter values of a, b, c: ";
    cin >> a >> b >> c;
    disc = (b * b) - (4 * a * c);

    if (disc == 0)
    {
        root1 = -b / 2 * a;
        root2 = root1;

        cout << "Roots are real and equal: " << root1 << " and " << root2 << endl;
    }
    else if (disc > 0)
    {
        root1 = (-b + sqrt(disc)) / (2 * a);
        root2 = (-b - sqrt(disc)) / (2 * a);

        cout << "Roots are real and unequal: " << root1 << " and " << root2 << endl;
    }
    else
    {
        cout << "Roots are imaginary" << endl;
    }

    return 0;
}