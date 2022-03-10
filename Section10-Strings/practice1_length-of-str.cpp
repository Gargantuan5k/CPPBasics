#include <iostream>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// TODO: Find length of declared string and print

int method1(string str)
{
    //* Method 1 using std::string
    return str.size();
}

int method2(char cstr[])
{
    //* Method 2 using C-style string
    return strlen(cstr);
}

int method3(char cstr[])
{
    //* Method 3 using char array and for loop (why would you ever do this1)

    int len = 0;
    for (int i = 0; i < strlen(cstr); i++) // read this forloop condition and suffer
    {
        if (cstr[i] != '\0')
            len++;
    }

    return len;
}

int method4(string str)
{
    //* Method 4 using std::string and string::iterator (meh)
    string::iterator iter;
    int len = 0;

    for (iter = str.begin(); iter != str.end(); iter++)
    {
        len++;
    }

    return len;
}

int main()
{
    string str = "Lorem ipsum";
    char cstr[] = "Lorem ipsum";

    cout << method1(str) << endl << method2(cstr) << endl << method3(cstr) << endl << method4(str) << endl;
    
    return 0;
}