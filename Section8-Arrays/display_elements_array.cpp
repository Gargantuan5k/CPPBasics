#include <iostream>
using namespace std;

int main()
{
    int array[] = {2, 4, 6, 8, 10};

    for (auto element : array)
    {
        cout << element << " ";
    }
    
    return 0;
}