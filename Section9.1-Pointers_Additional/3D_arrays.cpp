#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int primes[2][2][3] = {{{2, 3, 5}, {7, 9, 11}}, {{13, 17, 19}, {23, 29, 31}}};
    int (*ptr)[2][3] = primes;

    cout << ptr << endl; // Expected: Address of primes[0] = 0x61fedc in test
    cout << *ptr << endl; // Expected: Value at primes[0] = Address of primes[0][0] = 0x61fedc in test
    cout << *ptr + 1 << endl; // Expected: Value at primes[0] + 1 = Address of primes[0][1] = 0x61fee8 in test
    cout << *(ptr + 1) << endl; // Expected: Value at primes[1] = Address of primes[1][0] = 0x61ef4 in test
    cout << *(*(*(ptr + 1) + 1) + 2) << endl; // Expected: Value at primes[1][1][2] = 31
    cout << primes[1][1][2] << endl; // Expected: Same value as previous statement, but this one is easier to write/read 

    return 0;
}