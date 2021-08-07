#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

float cylinderVolume(float r, float h)
{
    return M_PI * (r * r) * h;
}

int main()
{
    float radius, height;
    cout << "Enter radius and height: ";
    cin >> radius >> height;
    cout << 
        "Volume of cylinder with radius " << radius << "and height " << height << " is " << cylinderVolume(radius, height) << endl;
    return 0;
}