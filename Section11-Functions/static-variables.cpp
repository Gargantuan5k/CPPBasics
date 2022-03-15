#include <iostream>

using namespace std;

void useless_function()
{
    int regular_var = 10;
    static int static_var = 20;

    regular_var++;
    static_var++;

    cout << "Non-static: " << regular_var << endl << "Static: " << static_var << endl;
}

int main()
{
    
    useless_function();
    useless_function();
    useless_function();
    useless_function();

    /* 
    ! EXPLANATION 
    * when a function is called, variables are created for it inside its stackframe and are deleted once the function terminates.
    * But when we make a variable static, it remains in memory throughout the execution of the program.
    * Similar behaviour is shown by global variables, but the difference is that static variables are block-scoped and cannot be accessed outside their scope.
    */

    return 0;
}