// TODO: Illustrate recursion by implementing loop behaviour using recursive function
#include <iostream>

using namespace std;

void recursive_function(int num)
{
    if (num > 0)
    {
        cout << num << " ";
        recursive_function(num - 1);
    }
}

int main()
{
    int num = 10;

    cout << "Behaviour with recursive function:" << endl;
    recursive_function(num);

    //* This behaviour is the same as a for loop: for (int i = num; i > 0; i--) cout << i << " "; Illustrated below:
    cout << endl << "Behaviour with for loop:" << endl;
    for (int i = num; i > 0; i--) cout << i << " ";

    return 0;
}