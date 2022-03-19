/*
* A safer Rect class: Write Accessor and Mutator functions to prevent mishandling of data!
* Properties of the class have been kept private, to prevent mishandling and intelligent Mutator function have
* -been written in their stead.
*/

#include <cmath>

using namespace std;

typedef double db;

class SafeRect
{
    private:
    db length, breadth;

    db pythagoras(db a, db b)
    {
        return sqrt(a * a + b * b);
    }

    public:
    void set_length(db l)
    {
        length = (l > 0 ? l : 0);
    }

    void set_breadth(db b)
    {
        breadth = (b > 0 ? b : 0);
    }

    db get_length()
    {
        return length;
    }

    db get_breadth()
    {
        return breadth;
    }

    db get_area()
    {
        return length * breadth;
    }

    db get_perimeter()
    {
        return 2 * (length + breadth);
    }

    db get_diagonal()
    {
        return pythagoras(length, breadth);
    }
};