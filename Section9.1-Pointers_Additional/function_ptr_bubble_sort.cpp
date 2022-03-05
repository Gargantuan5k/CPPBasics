#include <iostream>
using std::cout;

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

void bubbleSort(int arr[], int length, bool (*compare)(int, int))
{
    int i, j, temp;

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 4, 1, 5, 2};
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]), ascending);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}
