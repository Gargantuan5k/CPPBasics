#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

double radiusOfCircle(double r)
{
    return (double) M_PI * (pow(r, 2));    // Or M_PI * (r * r)
}

int main()
{
    double radius;
    cout << "Enter radius of circle: ";
    cin >> radius;
    cout << "Area of circle with radius " << radius << " is " << radiusOfCircle(radius) << endl;

    return 0;
}