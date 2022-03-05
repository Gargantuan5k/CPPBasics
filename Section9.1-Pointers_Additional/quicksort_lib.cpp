#include <iostream>
#include <cstdlib>
using std::cout;

int ascending(const void *a, const void *b)
{
    int a_ = *((int *)a);
    int b_ = *((int *)b);

    return a_ - b_; // Positive value if a > b, negative if a < b, works as ascending comparison
}

int main()
{
    int array[5] = {3, -1, 8, 2, -6};

    qsort(array, 5, sizeof(int), ascending);

    for (auto num : array)
        cout << num << " ";

    return 0;
}