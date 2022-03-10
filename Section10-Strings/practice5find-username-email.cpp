#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_email_validity(string email)
{
    for (string::iterator it = email.begin(); it != email.end(); ++it)
    {
        if (!((*it >= 48 && *it <= 57) || (*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122) || (*it == 95 || *it == 46 || *it == 64)) || email.find('@') == string::npos)
            return false;
    }

    return true;
}

string find_username(string email)
{
    string uname = "";
    for (string::iterator it = email.begin(); it != email.end(); ++it)
    {
        if (*it != '@')
            uname += *it;
        else
            break;
    }

    return uname;
}

int main()
{
    string email;
    cout << "Enter an email address: ";
    getline(cin, email);

    cout << (check_email_validity(email) ? find_username(email) : "Invalid Email!") << endl;

    return 0;
}