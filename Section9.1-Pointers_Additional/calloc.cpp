#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int *ptr = (int *)calloc(1, sizeof(int));
    cout << "Address to which ptr points: " << ptr << "\nValue stored there after calloc: " << *ptr << endl;
    *ptr = 69;
    cout << "Value stored at *ptr after manual initialisation: " << *ptr << endl;
    free(ptr);

    int *ptr2 = (int *)calloc(3, sizeof(int));
    cout << "Address to which ptr2 points: " << ptr2 << "\nValue stored there after calloc:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << ptr2[i] << " ";
    }

    ptr2[0] = 69;
    ptr2[1] = 4;
    ptr2[2] = 20;
    cout << "\nValues stored at ptr2 after initialisation:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << ptr2[i] << " ";
    }
    free(ptr2);

    return 0;
}