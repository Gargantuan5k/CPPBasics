#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int *ptr1, *ptr2, *ptr3;
    ptr1 = (int *)malloc(sizeof(int) * 5);

    for (int i = 1; i <= 5; i++)
    {
        ptr1[i - 1] = i;
    }

    // Now what if we'd like to extend this by 5 more elements? Let's use a new pointer for that.
    ptr2 = (int *)realloc(ptr1, 2 * sizeof(int) * 5);

    cout << "\nPrevious block addr: " << ptr1 << "\nNew block addr: " << ptr2 << "\nValues at ptr2: ";

    for (int i = 0; i < 10; i++)
    {
        cout << ptr2[i] << " ";
    }

    // Now what if we want to reduce the size of this array?
    ptr3 = (int *)realloc(ptr1, sizeof(int) * 5);

    cout << "\nPrevious block addr: " << ptr2 << "\nNew block addr: " << ptr3 << "\nValues at ptr3: ";

    for (int i = 0; i < 5; i++)
    {
        cout << ptr3[i] << " ";
    }

    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}