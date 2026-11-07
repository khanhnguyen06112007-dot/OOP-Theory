#include "Fraction.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
//=====================
//support function
int gcd(int a, int b){
    while(b){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
//======================

void Fraction::input(){
    char line[100];
    do{
        std::cout << "Enter numerator: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> (this -> numerator)));

    do{
        std::cout << "Enter denominator: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> denominator) || denominator == 0);
}

void Fraction::output() const{
    std::cout << numerator << "/" << denominator << "\n";
}

int Fraction::getNum() const{
    return numerator;
}

void Fraction::setNum(int num){
    this -> numerator = num;
}

int Fraction::getDenom() const{
    return denominator;
}

void Fraction::setDenom(int den){
    if (den == 0){
        throw std::invalid_argument("Mau so phai khac 0");        
    }
    denominator = den;
}

Fraction Fraction::reduce() const{
    Fraction result;
    int gc = gcd(numerator, denominator);
    result.numerator = numerator / gc;
    result.denominator = denominator / gc;
    return result;
}

Fraction Fraction::inverse() const{
    if (numerator == 0){
        throw std::invalid_argument("Tu so bang 0 thi khong the nghich dao");
    }
    Fraction result;
    result.numerator = denominator;
    result.denominator = numerator;
    return result;
}

Fraction Fraction::add(const Fraction &other) const{
    if (other.denominator == 0){
        throw std::invalid_argument("Mau so phai khac 0");
    }
    Fraction result;
    result.numerator = (this -> numerator * other.denominator) + (this -> denominator * other.numerator);
    result.denominator = (this -> denominator * other.denominator);
    return result;
}

bool Fraction::compare(const Fraction &other) const{
    if (other.denominator == 0){
        throw std::invalid_argument("Mau so phai khac 0");
    }
    long long num1 = numerator * other.denominator;
    long long num2 = denominator * other.numerator;

    if (num1 == num2){
        return 0;
    }
    else if (num1 > num2){
        return 1;
    }
    else{
        return -1;
    }
}

