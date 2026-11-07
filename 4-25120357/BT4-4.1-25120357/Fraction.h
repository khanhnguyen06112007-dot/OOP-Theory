#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
class Fraction{
private:
    int m_num;
    int m_den;
    void simplify();
public:
    Fraction();
    Fraction(int num, int den);

    Fraction operator + (const Fraction &other);
    Fraction operator * (const Fraction &other);

    bool operator > (const Fraction &other);
    bool operator < (const Fraction &other);
    bool operator == (const Fraction &other);
    bool operator >= (const Fraction &other);
    bool operator <= (const Fraction &other);
    bool operator != (const Fraction &other);

    Fraction& operator = (const Fraction &other);
    Fraction& operator += (const Fraction &other);
    Fraction& operator *= (const Fraction &other);

    Fraction& operator ++();
    Fraction operator ++(int);
    Fraction& operator --();
    Fraction operator --(int);

    operator float();
    operator int();

    friend std::istream& operator >> (std::istream &in, Fraction &f);
    friend std::ostream& operator << (std::ostream &out, const Fraction &f);
};
#endif