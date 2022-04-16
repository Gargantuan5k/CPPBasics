#include <iostream>

struct Lorem
{
    int ipsum;
    int dolorem;

    void lipsum()
    {
        std::cout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit." << std::endl;
    }
};
//! NOTE: struct is a feature of C as well. However, C structures cannot have functions as members.
//* Difference between class and struct is that all data members in structs are public by default, while they are private by default in classes.

int main()
{
    Lorem test;
    test.ipsum = 10;
    test.dolorem = 20;
    test.lipsum();

    return 0;
}