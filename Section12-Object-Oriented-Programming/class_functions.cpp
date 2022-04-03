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
    void get_length();
    void get_breadth();

    // facilitators
    int get_area();
    int get_perimeter();

    // inspectors
    bool is_square();

    // destructor
    ~Rectangle();
};

int main()
{
    return 0;
}