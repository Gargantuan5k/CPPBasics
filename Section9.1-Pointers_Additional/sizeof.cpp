#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int a = 1025;         // 1025 = 00000000 00000000 00000100 00000001
    int *p;               // int pointer
    p = &a;               // reference to a=1025
    char *p0 = (char *)p; // cast &a to char* and store in pointer p0

    cout << "Address at int pointer = " << (int)p << " Value = " << (int)*p << endl;               // Address of first byte in integer 1025 and value of 4 byte integer (= 00000000 00000000 00000100 00000001 = 1025)
    cout << "Address at int pointer + 1 = " << (int)p + 1 << " Value = " << (int)*(p + 1) << endl; // Address after 4 bytes and value of the 4 bytes there (= garbage)

    cout << "Address at char pointer = " << (int)p0 << " Value = " << (int)*p0 << endl;               // Address of first byte in 1025 (only 1 byte because p0 is char) and integer value of that byte (= 00000001 = 1)
    cout << "Address at char pointer + 1 = " << (int)p0 + 1 << " Value = " << (int)*(p0 + 1) << endl; // Address of 2nd byte in 1025 and integer value of that byte (= 00000100 = 4)

    return 0;
}