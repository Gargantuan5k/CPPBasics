#include <iostream>
using std::cout;
using std::endl;

void sayHello()
{
    cout << "Hello World!" << endl;
}

int *add(int *num1, int *num2)
{
    int *sum = (int *)malloc(sizeof(int));
    *sum = *num1 + *num2;

    return sum;
}

int main()
{
    int num1 = 60;
    int num2 = 9;
    int *sum = add(&num1, &num2);

    sayHello();

    cout << "sum is: " << *sum << endl;

    free(sum);
    cout << *sum;
    return 0;
}