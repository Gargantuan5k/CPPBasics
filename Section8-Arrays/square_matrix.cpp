#include <iostream>
using namespace std;

int main()
{
    int count = 0;

    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            cout << ++count << ' ';
        }
        cout << endl;
    }
    
    return 0;
}