#include <iostream>
#include "helpers.hpp"

class RationalNumber
{
private:
    int p;
    int q;
    
public:
    RationalNumber(int p = 0, int q = 1)
    {
        this->p = p;
        this->q = (q != 0 ? q : 1);
    }

    RationalNumber operator+(RationalNumber rvalue)
    {
        RationalNumber sum;
        int l = lcm(this->q, rvalue.q);
        int new_thisp = this->p * (l / this->q);
        int new_rvaluep = rvalue.p * (l / rvalue.q);

        sum.p = new_thisp + new_rvaluep;
        sum.q = l;

        return sum;
    }

    friend std::ostream &operator<<(std::ostream &, RationalNumber &);
};
std::ostream &operator<<(std::ostream &o, RationalNumber &value)
{
    std::cout << value.p << '/' << value.q;
    return o;
}

int main()
{
    RationalNumber a(3, 7), b(4, 14);
    RationalNumber c = a + b;

    std::cout << c << std::endl;

    return 0;
}