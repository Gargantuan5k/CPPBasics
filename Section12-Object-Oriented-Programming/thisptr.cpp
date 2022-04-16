#include <iostream>

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int length = 1, int breadth = 1)
    {
        // * Use `this` pointer to refer to same class, here `this` = Rectangle *this
        this->length = length;
        this->breadth = breadth;
    }

    void set_length(int length) { this->length = length; } // Length mutator

    void set_breadth(int breadth) { this->breadth = breadth; } // Breadth mutator

    int get_length() { return this->length; } // Length accessor

    int get_breadth() { return this->breadth; } // Breadth accessor

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main()
{
    Rectangle r1 = Rectangle(50, 30);

    std::cout << "Rectangle area: " << r1.area() << std::endl << "Rectangle perimeter: " << r1.perimeter() << std::endl;

    return 0;
}