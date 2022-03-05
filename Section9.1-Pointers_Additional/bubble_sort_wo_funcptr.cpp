#include <iostream>
using std::cout;
using std::endl;

void bubbleSort(int array[], int length, bool ascDescFlag = true)
{
    int temp, i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (ascDescFlag)
            {
                if (array[j] > array[j + 1]) // sort ascending
                {
                    // swapping logic
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
            else
            {
                if (array[j] < array[j + 1]) // sort descending
                {
                    // swapping logic
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {3, 1, 8, -3, 7, 9, 2, 4, 5, 2, 1, 8, 9, 2, 4, 5, 3};
    bubbleSort(arr, (sizeof(arr) / sizeof(arr[0])));
    for (auto i : arr)
        cout << i << " ";

    return 0;
}
