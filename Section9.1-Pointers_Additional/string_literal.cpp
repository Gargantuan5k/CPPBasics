#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char chArray[18] = "Lorem Ipsum Dolor";
    int length = strlen(chArray);
    cout << "String: " << (string) chArray << endl << "Length: " << length << endl;
    
    for (char item : chArray)
    {
        cout << item << endl;
    }
}