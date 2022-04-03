#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // constructor
    Rectangle(); // non-parameterized constructor
    Rectangle(int l, int b); // parameterized constructor
    Rectangle(Rectangle &rect); // copy constructor

    // mutators
    void set_length(int l);
    void set_breadth(int breadth);
    
    // accessors
    int get_length();
    int get_breadth();

    // facilitators
    int get_area();
    int get_perimeter();

    // inspectors
    bool is_square();
};

// scope resolution for writing functions for the above class:

Rectangle::Rectangle()
{
    Rectangle::length = 0;
    Rectangle::breadth = 0;
}

Rectangle::Rectangle(int l, int b)
{
    Rectangle::length = l;
    Rectangle::breadth = b;
}

Rectangle::Rectangle(Rectangle &rect)
{
    Rectangle::length = rect.length;
    Rectangle::breadth = rect.breadth;
}

void Rectangle::set_length(int l)
{
    Rectangle::length = l;
}

void Rectangle::set_breadth(int breadth)
{
    Rectangle::breadth = breadth;
}

int Rectangle::get_length()
{
    return Rectangle::length;
}

int Rectangle::get_breadth()
{
    return Rectangle::breadth;
}

int Rectangle::get_area()
{
    return Rectangle::length * Rectangle::breadth;
}

int Rectangle::get_perimeter()
{
    return 2 * (Rectangle::length + Rectangle::breadth);
}

bool Rectangle::is_square()
{
    return Rectangle::length == Rectangle::breadth;
}


int main()
{
    Rectangle my_rect(25, 60);
    Rectangle another_rect(45, 45);

    cout << my_rect.get_area() << ' ' << my_rect.is_square() << endl;
    cout << another_rect.get_area() << ' ' << another_rect.is_square() << endl;

    return 0;
}