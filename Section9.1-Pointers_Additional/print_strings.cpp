#include <cstdio>

void printStr(char str[]) // or char *str
{
    while (*str != '\0')
    {
        printf("%c", *str);
        str++;    // We can do this because str is a pointer to char array (implicit)
    }
}

int main()
{
    char myChArray[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    printStr(myChArray);

    return 0;
}