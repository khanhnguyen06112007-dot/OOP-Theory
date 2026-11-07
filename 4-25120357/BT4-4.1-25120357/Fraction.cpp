#include "Fraction.h"
#include <stdexcept>
#include <sstream>
int gcd(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void Fraction::simplify(){
    int GCD = gcd(m_num, m_den);
    m_num /= GCD;
    m_den /= GCD;
    if (m_den < 0){
        m_den *= -1;
        m_num *= -1;
    }
}
Fraction::Fraction() : m_num(0), m_den(1){}
Fraction::Fraction(int num, int den){
    if (den == 0){
        throw std::invalid_argument("Mau so phai khac 0");
    }
    m_num = num;
    m_den = den;
    this -> simplify();
}

Fraction Fraction::operator + (const Fraction &other){
    Fraction f;
    f.m_num = this -> m_num * other.m_den + this -> m_den * other.m_num;
    f.m_den = this -> m_den * other.m_den;
    f.simplify();
    return f;
}
Fraction Fraction::operator * (const Fraction &other){
    Fraction f;
    f.m_num = this -> m_num * other.m_num;
    f.m_den = this -> m_den * other.m_den;
    f.simplify();
    return f;
}

bool Fraction::operator > (const Fraction &other){
    return this -> m_num * other.m_den > this -> m_den * other.m_num;
}
bool Fraction::operator < (const Fraction &other){
    return this -> m_num * other.m_den < this -> m_den * other.m_num;
}
bool Fraction::operator == (const Fraction &other){
    return this -> m_num * other.m_den == this -> m_den * other.m_num;
}
bool Fraction::operator >= (const Fraction &other){
    return this -> m_num * other.m_den >= this -> m_den * other.m_num;
}
bool Fraction::operator <= (const Fraction &other){
    return this -> m_num * other.m_den <= this -> m_den * other.m_num;
}
bool Fraction::operator != (const Fraction &other){
    return !(*this == other);
}

Fraction& Fraction::operator = (const Fraction &other){
    if (this != &other){
        m_num = other.m_num;
        m_den = other.m_den;
    }
    return *this;
}
Fraction& Fraction::operator += (const Fraction &other){
    *this = *this + other;
    this -> simplify();
    return *this;
}
Fraction& Fraction::operator *= (const Fraction &other){
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator ++(){
    m_num += m_den;
    this -> simplify();
    return *this;
}
Fraction Fraction::operator ++(int){
    Fraction f = *this;
    m_num += m_den;
    this -> simplify();
    return f;
}
Fraction& Fraction::operator --(){
    m_num -= m_den;
    this -> simplify();
    return *this;
}
Fraction Fraction::operator --(int){
    Fraction f = *this;
    m_num -= m_den;
    this -> simplify();
    return f;
}

Fraction::operator float(){
    return (float)m_num / m_den;
}
Fraction::operator int(){
    return m_num / m_den;
}
std::istream& operator >> (std::istream &in, Fraction &f){
    in >> f.m_num >> f.m_den;
    return in;
}
std::ostream& operator << (std::ostream &out, const Fraction &f){
    out << f.m_num << "/" << f.m_den << "\n";
    return out;
}