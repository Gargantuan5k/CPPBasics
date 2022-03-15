#include <iostream>

using namespace std;

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int num1 = 10, num2 = 20;
    swap(num1, num2);  // Won't work as passed value, will not mutate original value in these vars.
    int sum = add(num1, num2); // will work as passed value, returns int stored in sum

    cout << num1 << " " << num2 << " " << sum << endl;

    return 0;
}