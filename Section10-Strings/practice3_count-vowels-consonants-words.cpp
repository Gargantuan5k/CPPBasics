#include <iostream>
#include <string>

using namespace std;

int count_vowels(string str)
{
    int count = 0;
    string::iterator i;
    for (i = str.begin(); i != str.end(); ++i)
    {
        if (tolower(*i) == 'a' || tolower(*i) == 'e' || tolower(*i) == 'i' || tolower(*i) == 'o' || tolower(*i) == 'u')
        {
            count++;
        }
    }

    return count;
}

int count_consonants(string str)
{
    int count = 0;
    string::iterator i;
    for (i = str.begin(); i != str.end(); ++i)
    {
        if (tolower(*i) != 'a' && tolower(*i) != 'e' && tolower(*i) != 'i' && tolower(*i) != 'o' && tolower(*i) != 'u' && tolower(*i) != ' ')
        {
            count++;
        }
    }

    return count;
}

int count_words(string str)
{
    int count = 1; // always at least 1 word in string
    string::iterator i;
    for (i = str.begin(); i != str.end(); ++i)
    {
        if (*i == ' ')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string str = "LoreM iPSuM doloR SIT aMet";
    cout << "Vowels: " << count_vowels(str) << endl << "Consonants: " << count_consonants(str) << endl << "Words: " << count_words(str) << endl;
    return 0;
}