#include <iostream>
using namespace std;

int main()
{
    int dimensions = 4; // 4x4

    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}