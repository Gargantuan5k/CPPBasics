#include <iostream>
using namespace std;

int main()
{
    int array[] = {2, 2, 3, 4, 5, 6, 7, 8, 8, 9, 9, 10, 12, 13, 21, 24, 45};
    int key;

    cout << "Enter element to search for: ";
    cin >> key;

    int low = 0, high = sizeof(array) / sizeof(array[0]), mid;

    while (high >= low)
    {
        mid = (low + high) / 2;

        if (key == array[mid])
        {
            cout << key << " found at index " << mid << endl;
            return 0;
        }

        else if (key < array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << key << " not found in given array.";
    return 0;
}