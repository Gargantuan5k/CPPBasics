#include <iostream>

using namespace std;

int my_var = 50; // global

int main()
{
    int my_var = 30; // local to main scope

    if (true)
    {
        int my_var = 10; // local to if block
        cout << "if-block scope: " << my_var << endl;
    }

    cout << "main function scope: " << my_var << endl;
    cout << "global scope: " << ::my_var << endl;
    
    /*
    ! NOTE
    * If a local variable and a global variable have the same name, the global variable cannot be accessed normally in the local scope.
    * To access a global variable with the same name as a local variable, use the scope resolution operator ::<variable_name> (as done in line 18)
    */

    return 0;
}