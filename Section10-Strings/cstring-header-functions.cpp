#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    char str1[] = "Hello World";
    char str2[] = "Lorem ipsum";
    char str3[] = " dolor sit amet";
    char str4[] = "Lorem ipsum";
    char str5[] = "Mhm very nice string definitely not gonna copy this";
    char str6[50] = "";
    char str7[50] = "";

    cout << "Length of string " << str1 << ": " << strlen(str1) << endl;

    strcat(str2, str3);
    cout << str2 << endl;

    strncat(str4, str3, 6);
    cout << str4 << endl;

    strcpy(str6, str5);
    cout << str6 << endl;

    strncpy(str7, str6, 3);
    cout << str7 << endl;

    cout << strstr(str4, "sum") << endl;
    cout << (strstr(str4, "Hello") != NULL ? strstr(str4, "Hello") : "Not found") << endl;

    cout << strchr("Programming", 'n') << endl;

    cout << strrchr("Programming", 'r') << endl;

    cout << strcmp("Hello", "Hello") << endl; // 0, strings equal
    cout << strcmp("Aardvark", "Zulu") << endl; // -ve, first string higher in ASCII order
    cout << strcmp("Zulu", "Aardvark") << endl; // +ve, second string higher in ASCII order
    cout << strcmp("hello", "Hello") << endl; // +ve, second string higher in ASCII order

    long int x = strtol("696969", NULL, 10);
    float y = strtof("6969.69", NULL);
    long int z = strtol("aa289", NULL, 16);
    cout << x << " " << y << " " << z << endl;

    char strToTokenize[] = "key1=10;key2=20;key3=30;key4=40";
    char *token = strtok(strToTokenize, "=;");
    while (token)
    {
        cout << token << " ";
        token = strtok(NULL, "=;");
    }

    return 0;
}