#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int *p;
    p = new int;
    *p = 69;

    cout << "The address that p points to: " << p << "\nThe value stored there: " << *p << endl;
    delete p;
    cout << "The address that p points to: " << p << "\nThe value stored there (garbage after deleting): " << *p << endl;

    p = new int[3];
    p[0] = 69;
    p[1] = 4;
    p[2] = 20;

    cout << "The address that p points to: " << p << "\nThe values in array: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << p[i] << " ";
    }
    delete[] p;
    cout << "\nThe address that p points to: " << p << "\nThe value stored there (garbage after deleting): " << *p << endl;

    return 0;
}