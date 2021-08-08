#include <iostream>
using namespace std;

void oddEven(int num)
{
    cout << ((num % 2 == 0) ? "Even" : "Odd") << endl;
}

int main()
{
    oddEven(5);
    oddEven(6);
    return 0;
}