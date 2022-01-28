#include <iostream>
using std::cout;
using std::endl;

int addNums(int a, int b)
{
    return a + b;
}

int main()
{
    int (*funcPtr)(int, int) = &addNums; // or just = addNums;
    int niceNumber = (*funcPtr)(60, 9); // or just funcPtr(60, 9);

    cout << niceNumber << endl;

    return 0;
}