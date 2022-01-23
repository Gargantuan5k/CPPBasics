#include <cstdlib>
#include <cstdio>

int main()
{
    int *p;
    p = (int *)malloc(sizeof(int)); // Allocate 4B for integer, use pointer p
    *p = 69;

    printf("The address that p points to: %d\nThe value stored there: %d\n", p, *p);
    free(p);
    printf("The address that p points to: %d\nThe value stored there (will be garbage now, after freeing): %d\n", p, *p);

    p = (int *)malloc(sizeof(int) * 3); // Allocate 12B for 3 integers in array, use pointer p
    p[0] = 69;
    p[1] = 4;
    p[2] = 20;

    printf("The address that p points to: %d\nThe values in array: ", p);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *(p + i));
    }
    free(p);
    printf("\nThe address that p points to: %d\nThe value stored there (will be garbage now, after freeing): %d\n", p, *p);

    return 0;
}