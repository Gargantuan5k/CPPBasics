#include <iostream>
using std::cout;
using std::endl;
// Tip: What I've done above (using std::cout; etc), is better practice than using namespace std directly, since it avoids polluting the workspace with
// variable names.

int main()
{
    int primesArray[2][3] = {{2, 3, 5}, {7, 9, 11}};
    cout << primesArray[0][2] << endl; // Expected value: 5

    int (*ptr)[3] = primesArray; // expects int array length = 3
    cout << ptr << endl; // Expected value: Address of primesArray[0] (0x61fef4 in test case)
    cout << *ptr << endl; // Expected value: Address of primesArray[0][0] (0x61fef4 in test case)
    cout << *ptr + 1 << endl; // Expected: Address of primesArray[0][1] (4 bytes higher than primesArray[0][0]) (0x61fef8 in test case)
    cout << *(ptr + 1) << endl; // Expected: Value at primesArray[1] = Address of primesArray[1][0] (12 bytes higher than primesArray[0][0]) (0x61ff00 in test)
    cout << *(*ptr + 1) << endl; // Expected: Value at primesArray[0][1] = 3

    cout << *(*(ptr + 1) + 2) << endl; // Expected: Value at primesArray[1][2] = 11

    return 0;
}