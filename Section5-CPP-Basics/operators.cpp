#include <iostream>
using namespace std;

int main()
{
    // Weird thing about division when you have datatypes (like in C++)
    
    cout << 5.0 / 2.0 << "   <-- Use .0 (double)" << endl;
    cout << 5.0f / 2.0f << "   <-- Use .0f (float)" << endl;
    cout << (float) 5 / 2 << "   <-- Typecasting <(float) or (double) etc>" << endl;

    cout << 5 / 2 << "   <-- int / int = int" << endl;

    cout << 5 % 2 << "   <-- Modulus works as normal" << endl;

    return 0;
}