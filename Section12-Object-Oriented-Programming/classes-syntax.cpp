#include <iostream>
#include <cmath>

using namespace std;

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

int main()
{
    Rect r1, r2;
    // cout << sizeof(r1); // double (8B) * 2 = 16B

    r1.length = 20.0;
    r1.breadth = 10.0;

    cout << r1.get_area() << endl << r1.get_perimeter() << endl << r1.get_diagonal() << endl;

    return 0;
}