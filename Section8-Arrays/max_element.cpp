#include <iostream>
using namespace std;

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5};
    int maxElement = array[0];

    for (auto element : array)
    {
        maxElement = element > maxElement ? element : maxElement;
    }
    
    cout << "The maximum element is " << maxElement << endl;

    return 0;
}