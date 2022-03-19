#include <cmath>

/*
! INFO
This code has been copied from ./classes-syntax.cpp for reusability purposes,
but the coded from ./classes-syntax.cpp shall remain in the file
*/

class Rect
{
    private:
    double pythagoras(double a, double b)
    {
        return sqrt(a * a + b * b);
    }

    public:
    double length;
    double breadth;     

    double get_area()
    {
        return length * breadth;
    }

    double get_perimeter()
    {
        return 2 * (length + breadth);
    }

    double get_diagonal()
    {
        return pythagoras(length, breadth);
    }
};