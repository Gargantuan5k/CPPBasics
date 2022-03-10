#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string my_str = "hello world";
    string::iterator iter;
    string::reverse_iterator rev_iter;
     

    for (iter = my_str.begin(); iter != my_str.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    for (rev_iter = my_str.rbegin(); rev_iter != my_str.rend(); ++rev_iter)
    {
        cout << *rev_iter << " ";
    }

    for (iter = my_str.begin(); iter != my_str.end(); ++iter)
    {
        *iter -= 32;
    }

    cout << endl << my_str << endl;

    return 0;
}