// TODO: Create a function to accept a size, make an array of given size, populate with nums from 1-size(incl) and return the array
#include <iostream>

using namespace std;

int *get_array(int size)
{
    int *array = new int[size];
    for (int i = 1; i <= size; i++)
        *(array + (i - 1)) = i; // or array[i-1] = i

    return array;
}

int main()
{
    int size = 69;
    int *arr = get_array(size);

    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " "; // or array[i] << " "

    delete[] arr; //! IMPORTANT! Always free memory in heap once you're done using it

    return 0;
}