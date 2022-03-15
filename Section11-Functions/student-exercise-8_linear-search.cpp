// TODO: Implement linear array search using functions
#include <iostream>

using namespace std;

int linear_search(int value, int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    int value, array[] = {2, 4, 5, 7, 10, 9, 13}, loc, length = sizeof(array) / sizeof(array[0]);
    cout << "Enter value to search for: ";
    cin >> value;

    loc = linear_search(value, array, length);

    if (loc >= 0)
        cout << "Value found at index " << loc << endl;

    else
        cout << "Value not found" << endl;

    return 0;
}