#include <iostream>
#include <cmath>

class ComplexNum
{
private:
    int real;
    int imag;

public:
    ComplexNum(int real = 0, int imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }

    ComplexNum operator+(ComplexNum rvalue)
    {
        ComplexNum sum;
        sum.real = this->real + rvalue.real;
        sum.imag = this->imag + rvalue.imag;

        return sum;
    }

    ComplexNum operator+(int rvalue)
    {
        ComplexNum sum;
        sum.real = this->real + rvalue;
        sum.imag = this->imag;

        return sum;
    }

    int operator>(ComplexNum rvalue)
    { return this->get_modulus() > rvalue.get_modulus(); }

    int operator<(ComplexNum rvalue)
    { return this->get_modulus() < rvalue.get_modulus(); }

    int operator==(ComplexNum rvalue)
    { return this->get_modulus() == rvalue.get_modulus(); }

    int get_real() { return this->real; }
    int get_imag() { return this->imag; }
    float get_modulus() { return sqrt((this->real * this->real) + (this->imag * this->imag)); }
};

int main()
{
    ComplexNum a = ComplexNum(4, 5); // 4 + 5i
    ComplexNum b = ComplexNum(6, 2); // 6 + 2i
    ComplexNum c = a + b;
    ComplexNum d = ComplexNum(10, 7);
    ComplexNum e = d + 3;

    std::cout << c.get_real() << " + " << c.get_imag() << "i" << std::endl;
    std::cout << e.get_real() << " + " << e.get_imag() << "i" << std::endl;

    std::cout << (bool) (a > b) << std::endl;
    std::cout << (bool) (c == d) << std::endl;

    return 0;
}