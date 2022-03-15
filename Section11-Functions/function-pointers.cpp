#include <iostream>

using namespace std;

int min_(int a, int b)
{
    return a < b ? a : b;
}

int max_(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int (*func_ptr)(int, int);

    func_ptr = min_;
    cout << (*func_ptr)(10, 5) << endl;

    func_ptr = max_;
    cout << (*func_ptr)(10, 5) << endl;

    return 0;
}