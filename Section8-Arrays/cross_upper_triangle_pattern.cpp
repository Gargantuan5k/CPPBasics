#include <iostream>
using namespace std;

int main()
{
    int dimensions = 5;

    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (i + j <= dimensions - 1)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}