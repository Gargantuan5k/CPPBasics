#include <iostream>
using namespace std;

void multiplicationTableWhile(int num)
{
    int i = 1;
    while (i <= 10)
    {
        cout << num << " * " << i << " = " << num * i << endl;
        ++i;
    }
}

void multiplicationTableFor(int num) 
{
    for (int i = 1; i <= 10; ++i)
    {
        cout << num << " * " << i << " = " << i * num << endl;
    }
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Using for loop:" << endl;
    multiplicationTableFor(num);

    cout << "Using while loop:" << endl;
    multiplicationTableWhile(num);

    return 0;
}