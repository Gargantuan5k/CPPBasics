#include <iostream>

using namespace std;

void increment(int &num)
{
    num++;
    cout << "Address of num in increment func: " << &num << endl;
}

int main()
{
    int x = 10;
    increment(x);
    cout << "x = " << x << endl;
    cout << "Address of num in main func: " << &x << endl;

    return 0;
}