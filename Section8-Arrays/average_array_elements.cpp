#include <iostream>
using namespace std;

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int sum = 0;
    float avg;

    for (auto element : array)
    {
        sum += element;
    }

    avg = (float) sum / (sizeof(array) / sizeof(array[0]));
    cout << "Average of elements: " << avg << endl;
    return 0;
}