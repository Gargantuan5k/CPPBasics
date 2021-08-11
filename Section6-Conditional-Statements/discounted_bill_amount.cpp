#include <iostream>
using namespace std;

int main()
{
    int amount, disc;
    float disAmount;

    cout << "Enter amount: ";
    cin >> amount;

    if (amount >= 5000)
    {
        disc = 20; 
    }
    else if (amount >= 2000 && amount < 5000)
    {
        disc = 10;
    }
    else
    {
        disc = 5;
    }

    disAmount = amount - (((float) disc / 100) * amount);
    cout << disAmount << endl;

    return 0;
}