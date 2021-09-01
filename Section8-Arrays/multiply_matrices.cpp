#include <iostream>
using namespace std;

int main()
{
    int matrixA[3][3] = {
        {12, 15, 20},
        {34, 87, 65},
        {12, 44, 56}
    };
    int matrixB[3][3] = {
        {89, 76, 23},
        {12, 11, 76},
        {44, 78, 99}
    };
    int multMatrix[3][3];

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            multMatrix[row][col] = matrixA[row][col] * matrixB[row][col];
        }
    }

    cout << "Multiplied matrix:" << endl;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            cout << multMatrix[row][col] << (!(col == 2 && row == 2) ? ", " : "");
        }
        cout << endl;
    }
    return 0;
}