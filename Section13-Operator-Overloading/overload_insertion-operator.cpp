#include <iostream>

class ComplexNum
{
private:
    int real;
    int imag;

public:
    ComplexNum(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    int get_real() { return real; }
    int get_imag() { return imag; }

    friend std::ostream &operator<<(std::ostream &, ComplexNum &);
};
inline std::ostream &operator<<(std::ostream &o, ComplexNum &c)
{
    std::cout << c.get_real() << " + " << c.get_imag() << "i";
    return o;
}

int main()
{
    ComplexNum cpx(5, 7); // 5 + 7i
    std::cout << cpx << std::endl;

    return 0;
}