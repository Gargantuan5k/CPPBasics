#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int myArray[5] = {3, 6, 8, 9, 10};

    for (int i = 0; i < sizeof(myArray) / sizeof(int); ++i)
    {
        cout << "Address of element at index " << i << ": " << myArray + i << endl;
        cout << "Element at index " << i << ": " << *(myArray + i) << endl;

        // Address can also be printed as &myArray[i]
        // Element can also be printed as myArray[i]
    }

    return 0;
}