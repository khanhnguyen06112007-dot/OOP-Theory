#include "Fraction.h"
#include <stdexcept>

static int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        int res = a % b;
        a = b;
        b = res;
    }
    return a;
}

void Fraction::normalize() {
    if (m_den == 0) {
        throw std::invalid_argument("Mau so phai khac 0");
    }
    int GCD = gcd(m_num, m_den);
    if (GCD != 0) {
        m_num /= GCD;
        m_den /= GCD;
    }
    if (m_den < 0) {
        m_num = -m_num;
        m_den = -m_den;
    }
}

Fraction::Fraction() : m_num(0), m_den(1) {}

Fraction::Fraction(int a, int b) : m_num(a), m_den(b) {
    normalize();
}

Fraction::~Fraction() {}

int Fraction::getNum() const {
    return m_num;
}

int Fraction::getDen() const {
    return m_den;
}

Fraction* Fraction::add(const Fraction &other) const {
    int num = m_num * other.m_den + m_den * other.m_num;
    int den = m_den * other.m_den;
    return new Fraction(num, den);
}

std::ostream& operator<<(std::ostream &out, const Fraction &f) {
    if (f.m_den == 1) {
        out << f.m_num;
    } else {
        out << f.m_num << "/" << f.m_den;
    }
    return out;
}
