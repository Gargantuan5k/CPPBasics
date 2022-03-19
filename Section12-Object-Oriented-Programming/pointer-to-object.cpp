#include <iostream>
#include "./rect-class.hpp"

using namespace std;

int main()
{
    // Accessing object properties directly
    Rect rectangle1;
    rectangle1.length = 10;
    rectangle1.breadth = 20;
    cout << "length: " << rectangle1.length << ", breadth: " << rectangle1.breadth << endl;

    // Using pointer on stack
    Rect rectangle2;
    Rect *rect2_ptr = &rectangle2;
    rect2_ptr->length = 30;
    rect2_ptr->breadth = 50;
    cout << "length: " << rect2_ptr->length << ", breadth: " << rect2_ptr->breadth << endl;

    // Using pointer to obj on heap
    Rect *rectangle3 = new Rect;
    rectangle3->length = 100;
    rectangle3->breadth = 150;
    cout << "area: " << rect2_ptr->get_area() << ", perimeter: " << rect2_ptr->get_perimeter() << endl;

    delete rectangle3;

    return 0;
}