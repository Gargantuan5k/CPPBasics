#include <iostream>
using namespace std;

int main()
{
    char inputStr[20];
    cout << "Enter your name: ";
    cin.getline(inputStr, sizeof(inputStr));
    /* 
    * The cin.getline() method takes two args: The character array to store the line in and the number of characters expected in the input.
    * While you can hardcode the second argument according to the usecase, this program will accept as many characters as the user inputs.
    * sizeof(inputStr) is used here, since each character is given 1 byte in a char array, sizeof(charArray) will return its length.
    */

    cout << "Hello " << inputStr << " :)";
}


