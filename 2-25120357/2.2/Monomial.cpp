#include "Monomial.h"
#include <sstream>
#include <iostream>
#include <cmath>

void Monomial::input(){ 
    char line[100];
    do{
        std::cout << "Enter coef: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> coef));

    do{
        std::cout << "Enter expo: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> expo) || expo < 0);
}
void Monomial::output() const{
    if (coef == 0.0 || expo == 0){
        std::cout << coef << "\n";
    }
    else if (expo == 1){
        std::cout << coef << "*x\n";
    }
    else{
        std::cout << coef << "*(x^" << expo << ")\n"; 
    }
}

float Monomial::getCoef() const{
    return coef;
}
void Monomial::setCoef(float coef){
    this -> coef = coef;
}

int Monomial::getExpo() const{
    return expo;
}
void Monomial::setExpo(int expo){
    if (expo < 0){
        throw std::out_of_range("He so mu phai la so nguyen khong am");
    }
    this -> expo = expo;
}

float Monomial::evaluate(float x) const{
    float num = (float)pow(x, expo);
    float res = coef * num;
    return res;
}
Monomial Monomial::derive() const{
    Monomial res;
    if (expo == 0){
        res.coef = 0.0;
    }
    else{
        res.coef = coef * expo;
        res.expo = expo - 1;
    }
    return res;
}
Monomial Monomial::mul(const Monomial &other) const{
    Monomial res;
    res.coef = coef * other.coef;
    res.expo = expo + other.expo;
    return res;
}