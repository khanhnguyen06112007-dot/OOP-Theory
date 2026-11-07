#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
private:
    int numerator;
    int denominator;
public:
    void input();
    void output() const;

    int getNum() const;
    void setNum(int num);

    int getDenom() const;
    void setDenom(int den);

    Fraction reduce() const;
    Fraction inverse() const;
    Fraction add(const Fraction &other) const;
    bool compare(const Fraction &other) const;
};
#endif