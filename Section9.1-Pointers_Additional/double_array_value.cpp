#include <iostream>
using namespace std;

void doubleArray(int array[], int length)   // int array[] is the same as int *array[] here.
{
    for (int i = 0; i < length; i++)  // We are taking the length of the array as a parameter.
    {
        array[i] *= 2;   // same as array[i] = array[i] * 2
    }
}

int main()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    int length = sizeof(myArray) / sizeof(myArray[0]);
    cout << "Original array: ";
    for (int i : myArray) {   // : is a new feature of C++ 11, which allows you to use a variable for the value of an array element instead of index
        cout << i << " ";
    }

    doubleArray(myArray, length);
    cout << "\nDoubled array: ";
    for (int j : myArray) {
        cout << j << " ";
    }
}