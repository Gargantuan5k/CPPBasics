#include <cmath>
#include <iostream>

int rootsOfQuadraticEquation(int a, int b, int c)
{
    float root1 = (float) (-b + (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);
    float root2 = (float) (-b - (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);

    std::cout << root1 << " " << root2 << std::endl;
    return 0;
}

int main()
{
    rootsOfQuadraticEquation(1, 1, 1);
}