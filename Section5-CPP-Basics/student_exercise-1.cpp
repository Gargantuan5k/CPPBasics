#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
    float radius;
    cout << "Enter radius of circle: ";
    cin >> radius;

    cout << "Area is " << M_PI * (pow(radius, 2));
    return 0;
}