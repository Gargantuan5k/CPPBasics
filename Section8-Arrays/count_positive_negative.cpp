#include <iostream>
using namespace std;

int main()
{
    int array[] = {3, 5, -2, 9, -4, 10, -24, 19, 81, -7, 12, 13}, numPos = 0, numNeg = 0;

    for (auto element : array)
    {
        if (element > 0)
        {
            ++numPos;
        }
        else if (element < 0)
        {
            ++numNeg;
        }
    }

    cout << "There are " << numPos << " positive elements and " << numNeg << " negative elements.";
    return 0;
}