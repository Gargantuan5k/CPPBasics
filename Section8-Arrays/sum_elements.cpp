#include <iostream>
using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    for (auto element : array)
    {
        sum += element;
    }

    cout << "Sum of elements is: " << sum << endl; 
    return 0;
}