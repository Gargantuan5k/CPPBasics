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
    int sumMatrix[3][3];

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            sumMatrix[row][col] = matrixA[row][col] + matrixB[row][col];
        }
    }

    cout << "Sum matrix:" << endl;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            cout << sumMatrix[row][col] << (!(col == 2 && row == 2) ? ", " : "");
        }
        cout << endl;
    }
    return 0;
}