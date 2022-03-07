#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void oneWordIn()
{
    // This implementation only accepts first word entered by user, not entire line / multiple words
    char name1[100];
    cout << "Enter your name: ";
    cin >> name1;
    cout << "Hello " << name1 << " :)" << endl;
}

void multiWordIn()
{
    // cin.get() takes multiple words
    char name2[100];
    cout << "Enter your full name: ";
    cin.getline(name2, 100);
    cout << "Your full name is " << name2 << endl;
}

int main()
{
    // oneWordIn();
    multiWordIn();
    return 0;
}