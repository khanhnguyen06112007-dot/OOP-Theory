#ifndef MONOMIAL_H
#define MONOMIAL_H
#include <iostream>
class Monomial{
private:
    double coef;
    int expo;
public:
    Monomial(double coef, int expo);

    Monomial operator + (const Monomial &other);
    Monomial operator * (const Monomial &other);

    bool operator > (const Monomial &other);
    bool operator < (const Monomial &other);
    bool operator == (const Monomial &other);
    bool operator >= (const Monomial &other);
    bool operator <= (const Monomial &other);
    bool operator != (const Monomial &other);

    Monomial& operator = (const Monomial &other);
    Monomial& operator += (const Monomial &other);
    Monomial& operator *= (const Monomial &other);

    Monomial& operator ++();
    Monomial operator ++(int);
    Monomial& operator --();
    Monomial operator --(int);
    
    Monomial operator !();
    
    friend std::istream& operator >> (std::istream &in, Monomial &m);
    friend std::ostream& operator << (std::ostream &out, const Monomial &m);
};
#endif