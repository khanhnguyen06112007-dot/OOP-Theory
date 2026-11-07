#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <algorithm>
class Polynomial{
private:
    int m_degree;
    double *m_coefs;
public:
    Polynomial();
    Polynomial(int degree, const double *m_coefs);
    Polynomial(const Polynomial &other);
    ~Polynomial();

    Polynomial &operator = (const Polynomial &other);
    Polynomial operator + (const Polynomial &other) const;
    Polynomial operator - (const Polynomial &other) const;
    Polynomial operator * (const Polynomial &other) const;

    bool operator > (const Polynomial &other) const;
    bool operator < (const Polynomial &other) const;
    bool operator == (const Polynomial &other) const;
    bool operator >= (const Polynomial &other) const;
    bool operator <= (const Polynomial &other) const;
    bool operator != (const Polynomial &other) const;

    Polynomial operator !() const;
    Polynomial operator ~() const;

    friend std::istream& operator >> (std::istream &in, Polynomial &p);
    friend std::ostream& operator << (std::ostream &out, const Polynomial &p);
};
#endif