#include <iostream>
using namespace std;

void positiveNegative(int num)
{
    cout << ((num >= 0) ? "Positive" : "Negative") << endl;
}

int main()
{
    positiveNegative(1);
    positiveNegative(0);
    positiveNegative(-43);
    return 0;
}