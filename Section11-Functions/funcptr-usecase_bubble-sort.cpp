// TODO: Implement bubble sort using fucntion pointers for comparison logic

#include <iostream>
using namespace std;

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

void bubble_sort(int arr[], int length, bool (*comparison)(int, int))
{
    int i, j, temp;
    
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (comparison(arr[j], arr[j + 1]))
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array[] = {23, 12, 2, 6, 21, 46, 13, 14, 14, 13};
    int length = sizeof(array) / sizeof(array[0]);

    cout << "Ascending:\n";
    bubble_sort(array, length, ascending);
    for (auto i : array) cout << i << " ";

    cout << "\nDescending:\n";
    bubble_sort(array, length, descending);
    for (auto i : array) cout << i << " ";
    
    return 0;
}