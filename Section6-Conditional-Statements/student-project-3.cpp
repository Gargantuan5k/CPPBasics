#include <iostream>
using namespace std;

int main()
{
    float amt, discount = 0.0f;

    cout << "Enter amount: ";
    cin >> amt;

    if (amt < 100)
    {
    }

    else if (amt >= 100 && amt < 500)
    {
        discount = 10.0f;
    }

    else if (amt >= 500)
    {
        discount = 20.0f;
    }

    cout << "Initial bill amount: " << amt << endl;
    cout << "Discount: " << discount << "%" << endl;
    cout << "Bill amount after discount: " << (float) (amt - ((discount/100) * amt));

    return 0;
}