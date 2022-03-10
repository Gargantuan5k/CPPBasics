#include <iostream>

using namespace std;

int pow(int x, int y)
{
    int ans = 1;
    for (int i = 0; i < y; i++)
        ans *= x;

    return ans;
}

int main()
{
    cout << pow(2, 5);

    return 0;
}