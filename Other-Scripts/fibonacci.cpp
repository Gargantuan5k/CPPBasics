#include <cstdio>
#include <chrono>

#define UINT_MAX long long unsigned int
#define FUNC_CALL_RECURSIVE printf("[RECURSIVE] The %dth fibonacci number is %d\n", n, fiboRecursive(n))
#define FUNC_CALL_DYNAMIC printf("[DYNAMIC] The %dth fibonacci number is %d\n", n, fiboDynamic(n))

using namespace std::chrono;

UINT_MAX fiboRecursive(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fiboRecursive(n - 1) + fiboRecursive(n -2);
}

UINT_MAX fiboDynamic(int n)
{
    if (n == 0 || n == 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return (UINT_MAX) c;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    auto startRec = high_resolution_clock::now();
    FUNC_CALL_RECURSIVE;
    auto stopRec = high_resolution_clock::now();

    auto startDyn = high_resolution_clock::now();
    FUNC_CALL_DYNAMIC;
    auto stopDyn = high_resolution_clock::now();

    auto durationRec = duration_cast<seconds>(stopRec - startRec);
    auto durationDyn = duration_cast<nanoseconds>(stopDyn - startDyn);
    printf("Recursive %dth fibonacci: Took %d seconds\n", n, durationRec.count());
    printf("Dynamic %dth fibonacci: Took %d nanoseconds\n", n, durationDyn.count());

    return 0;
}