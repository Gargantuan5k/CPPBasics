#include <iostream>
using namespace std;

void increment(int *ptr)
{
    (*ptr) += 1;
    cout << "Address of num in increment func: " << &*ptr << endl;
}

int main()
{
    int num = 10;
    increment(&num);
    cout << "Address of num in main func: " << &num << endl;
    cout << "Value of num after calling function: " << num << endl;

    return 0;
}