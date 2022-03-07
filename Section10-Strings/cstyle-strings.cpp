#include <iostream>
using std::cout;
using std::endl;

int main()
{
    // Initialise string in character array of any size
    char str1[10] = "Hello";
    cout << str1 << endl; // Prints as string, will not print any values after str1[5] even though the array is of size 10

    // Automatically detect size of character array using []
    char str2[] = "Lorem";
    cout << str1 << " Size of array = " << sizeof(str2) / sizeof(str2[0]) << endl; // size is 6 because "Lorem" + '\0'

    // Manually declare each element of char array
    char str3[] = {'i', 'p', 's', 'u', 'm', '\0'};
    cout << str3 << endl;

    // Use char pointer to get string in heap
    char *str4 = "world"; // Bad practice, dont do this practically
    std::string str5 = "world"; // Better than line20

    return 0;
}