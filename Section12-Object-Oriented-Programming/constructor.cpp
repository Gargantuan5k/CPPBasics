#include <iostream>

using namespace std;

typedef double db;

class Rectangle
{
    private:
    db length;
    db breadth;

    public:
    // Default / Non-parameterized constrcutor
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }

    // Parameterized constructor
    Rectangle(db length, db breadth)
    {
        Rectangle::length = length;
        Rectangle::breadth = breadth;
    }

    /*
    ! NOTE
    * There is no need to write a separate Default constructor here, you can simply assign default values to the parameters of the parameterized constructor.
    Rectangle (db length = 0, db breadth = 0) { ... } 
    * The above will work the same way, and eliminate the need for an explicit Default constructor.
    */

    // Copy constructor
    Rectangle(Rectangle(&copy))
    {
        length = copy.length;
        breadth = copy.breadth;
    }

    // Accessors
    db get_length() { return length; }
    db get_breadth() { return breadth; }

    // Mutators
    void set_length(db length) { Rectangle::length = length; }
    void set_breadth(db breadth) { Rectangle::breadth = breadth; }

    // Calculated properties
    db get_area() { return length * breadth; }
    db get_perimeter() { return 2 * (length + breadth); }
};

int main()
{
    // Non-parameterised construction
    Rectangle r1;
    cout << r1.get_length() << " " << r1.get_breadth() << endl;

    // Parameterized construction
    Rectangle r2(10, 30);
    cout << r2.get_length() << " " << r2.get_breadth() << endl;

    // Copied construction
    Rectangle r3(50, 100);
    Rectangle r4(r3);

    cout << r3.get_length() << " " << r3.get_breadth() << endl;
    cout << r4.get_length() << " " << r4.get_breadth() << endl;

    return 0;
}