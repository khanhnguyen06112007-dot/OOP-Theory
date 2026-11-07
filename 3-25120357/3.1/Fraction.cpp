#include "Fraction.h"
#include <stdexcept>
#include <iostream>
Fraction::Fraction(){
    m_num = 0;
    m_den = 1;
}

Fraction::Fraction(int num, int den){
    if (den == 0){
        throw std::invalid_argument("Mau so phai khac 0");
    }
    m_num = num;
    m_den = den;
}

Fraction::Fraction(int value){
    m_num = value;
    m_den = 1;
}

Fraction::Fraction(const Fraction &other){
    m_num = other.m_num;
    m_den = other.m_den;
}

void Fraction::printFraction() const{
    std::cout << m_num << "/" << m_den << "\n";
}