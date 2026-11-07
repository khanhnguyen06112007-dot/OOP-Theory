#include "Monomial.h"
#include <stdexcept>
#include <sstream>
Monomial::Monomial(double coef, int expo){
    if (expo < 0){
        throw std::invalid_argument("So mu trong don thuc bi am");
    }
    this -> coef = coef;
    this -> expo = expo;
}

Monomial Monomial::operator + (const Monomial &other){
    if (this -> expo != other.expo){
        throw std::invalid_argument("Khong the cong neu khac so mu");
    }
    return Monomial(this -> coef + other.coef, this -> expo);
}
Monomial Monomial::operator * (const Monomial &other){
    return Monomial(this -> coef * other.coef, this -> expo + other.expo);
}

bool Monomial::operator > (const Monomial &other){
    if (this -> expo != other.expo){
        return this -> expo > other.expo;
    }
    return this -> coef > other.coef;
}
bool Monomial::operator < (const Monomial &other){
    if (this -> expo != other.expo){
        return this -> expo < other.expo;
    }
    return this -> coef < other.coef;
}
bool Monomial::operator == (const Monomial &other){
    return (this -> coef == other.coef && this -> expo == other.expo);
}
bool Monomial::operator >= (const Monomial &other){
    if (this -> expo != other.expo){
        return this -> expo >= other.expo;
    }
    return this -> coef >= other.coef;
}
bool Monomial::operator <= (const Monomial &other){
    if (this -> expo != other.expo){
        return this -> expo <= other.expo;
    }
    return this -> coef <= other.coef;
}
bool Monomial::operator != (const Monomial &other){
    return !(*this == other);
}

Monomial& Monomial::operator = (const Monomial &other){
    if (this != &other){
        this -> coef = other.coef;
        this -> expo = other.expo;
    }
    return *this;
}
Monomial& Monomial::operator += (const Monomial &other){
    if (this -> expo != other.expo){
        throw std::invalid_argument("Khong the cong khac so mu");
    }
    *this = *this + other;
    return *this;
}
Monomial& Monomial::operator *= (const Monomial &other){
    *this = *this * other;
    return *this;
}

Monomial& Monomial::operator ++(){
    expo++;
    return *this;
}
Monomial Monomial::operator ++(int){
    Monomial a = *this;
    expo++;
    return a;
}
Monomial& Monomial::operator --(){
    expo--;
    return *this;
}
Monomial Monomial::operator --(int){
    Monomial m = *this;
    expo--;
    return m;
}
    
Monomial Monomial::operator !(){
    if (expo == 0) {
        return Monomial(0, 0); 
    }
    return Monomial(coef * expo, expo - 1);
}    
std::istream& operator >> (std::istream &in, Monomial &m){
    in >> m.coef >> m.expo;
    return in;
}
std::ostream& operator << (std::ostream &out, const Monomial &m){
    out << m.coef << "*(x^" << m.expo << ")";
    return out;
}