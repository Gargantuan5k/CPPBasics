#include <iostream>
using namespace std;

void charArrayWithoutNullTermination()
{
    char myCharArray[5];
    myCharArray[0] = 'L';
    myCharArray[1] = 'o';
    myCharArray[2] = 'r';
    myCharArray[3] = 'e';
    myCharArray[4] = 'm';

    cout << myCharArray << endl;
}


void charArrayWithNullTermination()
{
    char myCharArray[6];
    myCharArray[0] = 'L';
    myCharArray[1] = 'o';
    myCharArray[2] = 'r';
    myCharArray[3] = 'e';
    myCharArray[4] = 'm';
    myCharArray[5] = '\0';

    cout << myCharArray << endl;
}

int main()
{
    charArrayWithoutNullTermination();
    charArrayWithNullTermination();
}