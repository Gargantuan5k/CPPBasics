#include <iostream>

using namespace std;

int &useless_function(int &num)
{
    cout << num << endl;
    return num;
}

int main()
{
    int x = 69;
    useless_function(x) = 6969;
    /* 
    ? How does this work?
    * useless_function accepts a reference to a variable, in this case x
    * (This means that useless_function is copied inline into the main scope and can access x stored there thru reference &num=x)
    * useless_function(x) will make a reference &num = x, then cout the value stored at x
    * It will then return the same reference (as in line 8); so line 14 can be read as num = 6969; or x = 6969; (remember that num is a reference to x)
    * In this way, a function call can be an LVALUE in an expression.
    */

    return 0;
}