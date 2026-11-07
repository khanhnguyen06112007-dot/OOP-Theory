#ifndef FRACTION_H
#define FRACTION_H
class Fraction{
private:
    int m_num;
    int m_den;
public:
    Fraction();
    Fraction(int num, int den);
    Fraction(int value);
    Fraction(const Fraction &other);
    void printFraction() const;
};
#endif