/*
TODO: Implement Nth Fibonacci number recursively.
* Fibonacci(n) = Fibonacci(n - 1) + Fibonacci(n - 2) 
*/

#include <iostream>

using namespace std;

int fibo(int n)
{
    return n == 0 || n == 1 ? n : (fibo(n - 1) + fibo(n - 2)); 
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Nth fibonacci for n = " << n << ": " << fibo(n) << endl;

    //! NOTE: Computing Nth fibonacci recursively is not very efficient, with a time complexity of O(Φ^n), or O(((1 + √5)/2)^n)

    return 0;
}