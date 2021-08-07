#include <iostream>
using namespace std;

float si(float p, float n, float r)
{
    return (p * n * r) / 100;
}

int main()
{
    float p, n, r;
    cout << "Enter Principal, Period and Rate: ";
    cin >> p >> n >> r;
    cout << "Simple interest is " << si(p, n, r);
    return 0;
}