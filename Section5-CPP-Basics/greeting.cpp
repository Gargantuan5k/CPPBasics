#include <iostream>
using namespace std;

int main()
{
    string uname;
    cout << "Enter your name please: ";
    getline(cin, uname);
    cout << "Hello " << uname << ", welcome to C++ :)";

    return 0;
}