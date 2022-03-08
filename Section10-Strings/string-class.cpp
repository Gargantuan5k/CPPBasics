#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string myStr = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    string userStr;

    cout << "Declared string: " << myStr << endl << "Enter a string: ";
    getline(cin, userStr);
    cout << "User string: " << userStr << endl;
    return 0;
}