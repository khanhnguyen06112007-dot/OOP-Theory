#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int m_num;
    int m_den;
    void normalize();

public:
    Fraction();
    Fraction(int a, int b = 1);
    ~Fraction();

    int getNum() const;
    int getDen() const;

    Fraction* add(const Fraction &other) const;

    friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
};

#endif // FRACTION_H
