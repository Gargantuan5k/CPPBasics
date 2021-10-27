#include <iostream>
using namespace std;

int sumOfElements(int array[], int size)
{
    int i, sum = 0;
    printf("Size of array in Bytes, will return size of int* (SOE): %d\nLength of array given as argument (SOE): %d\n", sizeof(array), size);

    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int main()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int mySum = sumOfElements(myArray, size);
    cout << "Sum of elements is " << mySum << endl;
}