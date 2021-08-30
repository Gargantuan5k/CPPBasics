#include <iostream>
using namespace std;

int main()
{
    int array[] = {0, 3, 9, 8, 3, 9, 1, 0, 4, 3, 2, 2, 7, 9};
    int key;
    int matches = 0;

    cout << "Enter element to find: ";
    cin >> key;

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        if (array[i] == key)
        {
            cout << key << " found at index " << i << endl;
            ++matches;
        }
    }

    if (matches == 0)
        cout << "No matches found";

    return 0;
}