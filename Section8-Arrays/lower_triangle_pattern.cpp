#include <iostream>
using namespace std;

int main()
{
    int dimensions = 5;  // 5x5

    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (i >= j)
                cout << "* ";
        }
        cout << endl;
    }
    return 0;
}