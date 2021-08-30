#include <iostream>
using namespace std;

int main()
{
    int array[] = {8, 4, 12, 37, 36, 25, -2, 10, 15, 25};
    int minElement = array[0];

    for (auto element : array)
    {
        minElement = element < minElement ? element : minElement;
    }

    cout << "Smallest element is: " << minElement << endl;
    return 0;
    
}