#include <iostream>
using namespace std;

int main()
{
    int integerArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int sumElements = 0;

    for (int i = 0; i < 10; i++)
    {
        sumElements += integerArray[i];
    }

    cout << "Sum of elements: " << sumElements << endl;
    return 0;
}