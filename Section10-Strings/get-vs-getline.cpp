#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void useGet()
{
    char name[50], name2[50];
    cout << "enter your full name: ";
    cin.get(name, 50);
    cout << "Hello " << name << endl;

    cout << "Enter name again: ";
    cin.get(name2, 50);
    cout << "Hello " << name2 << endl;

    /* Problem is that cin.get() does not consider the trailing newline character after you press enter, instead that character is accepted by the next cin.get()
       The \n is taken by the next cin.get() function, so it takes an empty input and proceeds, therefore no wait to enter again
    */
}

void useGetLine()
{
    char name[50], name2[50];
    cout << "Enter your full name: ";
    cin.getline(name, 50);
    cout << "Hello " << name << endl;

    cout << "Enter name again: ";
    cin.getline(name2, 50);
    cout << "Hello " << name2 << endl;

    /*
    using cin.getline() solves the previously encountered problem, it accepts the trailing \n character as well, so there is a waiting prompt the second time
    */
}

void useGetWithFix()
{
    char name[50], name2[50];
    cout << "Enter your full name: ";
    cin.get(name, 50);
    cout << "Hello " << name << endl;

    cin.ignore(); // ignore trailing \n character, so it doesnt get accepted by the next cin.get()

    cout << "Enter name again: ";
    cin.get(name2, 50);
    cout << "Hello " << name2 << endl;
}

int main()
{
    // useGet();
    useGetLine();
    useGetWithFix();

    return 0;
}