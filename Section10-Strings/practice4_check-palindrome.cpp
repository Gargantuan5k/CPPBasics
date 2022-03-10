#include <iostream>
#include <string>

using namespace std;

bool check_palindrome(string str)
{
    string::reverse_iterator rev_iter;
    string rev_str = "";

    for (rev_iter = str.rbegin(); rev_iter != str.rend() ; ++rev_iter)
    {
        *rev_iter = tolower(*rev_iter); // eliminate case-sensitivity
        rev_str += *rev_iter;
    }

    return rev_str == str;
}

int main()
{
    string palindromic = "racecar";
    string non_palindromic = "hello";

    cout << check_palindrome(palindromic) << endl;
    cout << check_palindrome(non_palindromic) << endl;

    return 0;
}