#include <iostream>

using namespace std;

int glob_num = 100; // This variable is accessible to all functions

void useless_function()
{
    int scoped_num2 = 30; // This variable is accessible only to useless_function
    cout << glob_num << endl << scoped_num2 << endl;
    // cout << scoped_num1 here is invalid, as it is not accessible by functions other than main
}

int main()
{
    int scoped_num1 = 25; // This is accessible only to main
    cout << glob_num << endl << scoped_num1 << endl;

    useless_function();

    // cout << scoped_num2 here is invalid, as it is not accessible by functions other than useless_function

    return 0;
}