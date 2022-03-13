#include <iostream>

using namespace std;

int maxim(int a = 0, int b = 0, int c = 0)
{
    return a > b && a > c ? a : (b > a && b > c ? b : c);
}

int main()
{
    cout << maxim(5, 3, 10) << endl;
    cout << maxim(45, 9) << endl;
    cout << maxim(5) << endl;

    return 0;
}