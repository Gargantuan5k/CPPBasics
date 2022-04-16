#include <iostream>

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

    int get_real() { return this->real; }
    int get_imag() { return this->imag; }

    friend ComplexNum operator+(ComplexNum, ComplexNum);
};
ComplexNum operator+(ComplexNum c1, ComplexNum c2)
{
    ComplexNum sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

int main()
{
    ComplexNum a(5, 7);
    ComplexNum b(3, 4);
    ComplexNum c = a + b;

    std::cout << c.get_real() << " + " << c.get_imag() << "i" << std::endl;

    return 0;
}