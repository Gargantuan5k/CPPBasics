// TODO: Change given uppercase string to lower
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string method1(string str)
{
    //* Method 1: Using for loop and ascii stuff (stupid)
    string::iterator iter;
    for (iter = str.begin(); iter != str.end(); ++iter)
    {
        if (*iter >= 65 && *iter <= 90) // check if character is [A-Z]
            *iter += 32; 
    }

    return str;
}

string method2(string str)
{
    //* Method 2: Using tolower() on each character w/ for loop
    string::iterator iter;
    for (iter = str.begin(); iter != str.end(); ++iter)
    {
        *iter = tolower(*iter);
    }

    return str;
}

string method3(string str)
{
    //* Method 3: Using std::transform
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main()
{
    string str = "HELLO";
    cout << "Method 1: " << method1(str) << endl
         << "Method 2: " << method2(str) << endl
         << "Method 3: " << method3(str) << endl;
    return 0;
}