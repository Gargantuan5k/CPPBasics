#include <iostream>
using namespace std;

int main()
{
    int array2D[5][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24}
    };

    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            cout << array2D[row][col] << endl;
        }
    }
    return 0;
}