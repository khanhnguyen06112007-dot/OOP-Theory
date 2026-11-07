#include "Polynomial.h"

// void normalize(Polynomial &p){
//     int realDegree = p.m_degree;
//     while (realDegree > 0 && p.m_coefs[realDegree] == 0) {
//         realDegree--;
//     }
//     if (realDegree != p.m_degree) {
//         double* newCoeffs = new double[realDegree + 1];
//         for (int i = 0; i <= realDegree; ++i) {
//             newCoeffs[i] = p.m_coefs[i];
//         }
//         delete[] p.m_coefs;
//         p.m_coefs = newCoeffs;
//         p.m_degree = realDegree;
//     }
// }
Polynomial::Polynomial(){
    m_degree = 0;
    m_coefs = new double[m_degree + 1];
    m_coefs[0] = 0.0;
}
Polynomial::Polynomial(int degree, const double *coefs){
    if (degree < 0){
        throw std::invalid_argument("Bac da thuc khong duoc am");
    } 
    if (coefs == nullptr){
        throw std::invalid_argument("con tro mang he so khong duoc null");
    }
    m_degree = degree;
    m_coefs = new double[m_degree + 1];
    for (int i = 0; i <= m_degree; i++){
        this -> m_coefs[i] = coefs[i];
    }
}

Polynomial::Polynomial(const Polynomial &other){
    this -> m_degree = other.m_degree;
    this -> m_coefs = new double[this -> m_degree + 1];
    for (int i = 0; i <= this -> m_degree; i++){
        this -> m_coefs[i] = other.m_coefs[i];
    }
}

Polynomial::~Polynomial(){
    delete[] m_coefs;
}

Polynomial& Polynomial::operator = (const Polynomial &other){
    if (this != &other){
        delete[] this -> m_coefs;
        this -> m_degree = other.m_degree;
        this -> m_coefs = new double[this -> m_degree + 1];
        for (int i = 0; i <= this -> m_degree; i++){
            this -> m_coefs[i] = other.m_coefs[i];
        }
    }
    return *this;
}

Polynomial Polynomial::operator + (const Polynomial &other) const{
    int maxDeg = std::max(this -> m_degree, other.m_degree);
    double *tmpCoefs = new double[maxDeg + 1]{0};
    for (int i = 0; i <= this -> m_degree; i++){
        tmpCoefs[i] += this -> m_coefs[i];
    }
    for (int i = 0; i <= other.m_degree; i++){
        tmpCoefs[i] += other.m_coefs[i];
    }
    Polynomial result(maxDeg, tmpCoefs);
    delete[] tmpCoefs;
    return result;
}

Polynomial Polynomial::operator - (const Polynomial &other) const{
    int maxDeg = std::max(this -> m_degree, other.m_degree);
    double *tmpCoefs = new double[maxDeg + 1]{0};
    for (int i = 0; i <= this -> m_degree; i++){
        tmpCoefs[i] += this -> m_coefs[i];
    }
    for (int i = 0; i <= other.m_degree; i++){
        tmpCoefs[i] -= other.m_coefs[i];
    }
    Polynomial result(maxDeg, tmpCoefs);
    delete[] tmpCoefs;
    return result;
}

Polynomial Polynomial::operator * (const Polynomial &other) const{
    int newDeg = this -> m_degree + other.m_degree;
    double *tmpCoefs = new double[newDeg + 1]{0};
    for (int i = 0; i <= this -> m_degree; i++){
        for (int j = 0; j <= other.m_degree; j++){
            tmpCoefs[i + j] += this -> m_coefs[i] * other.m_coefs[j];
        }
    }
    Polynomial result(newDeg, tmpCoefs);
    delete[] tmpCoefs;
    return result;
}

bool Polynomial::operator > (const Polynomial &other) const{
    int degree1 = this -> m_degree;
    int degree2 = other.m_degree;
    while(degree1 > 0 && this -> m_coefs[degree1] == 0){
        degree1--;
    }
    while(degree2 > 0 && other.m_coefs[degree2] == 0){
        degree2--;
    }
    if (degree1 != degree2){
        return degree1 > degree2;
    }
    for (int i = degree1; i >= 0; i--){
        if (this -> m_coefs[i] != other.m_coefs[i]){
            return this -> m_coefs[i] > other.m_coefs[i];
        }
    }
    return false;
}

bool Polynomial::operator < (const Polynomial &other) const{
    return (other > (*this));
}

bool Polynomial::operator == (const Polynomial &other) const{
    int degree1 = this -> m_degree;
    int degree2 = other.m_degree;
    while(degree1 > 0 && this -> m_coefs[degree1] == 0){
        degree1--;
    }
    while(degree2 > 0 && other.m_coefs[degree2] == 0){
        degree2--;
    }
    if (degree1 != degree2){
        return false;
    }
    for (int i = degree1; i >= 0; i--){
        if (this -> m_coefs[i] != other.m_coefs[i]){
            return false;
        }
    }
    return true;
}

bool Polynomial::operator != (const Polynomial &other) const{
    return !(*this == other);
}

bool Polynomial::operator >= (const Polynomial &other) const{
    return !(*this < other);
}

bool Polynomial::operator <= (const Polynomial &other) const{
    return !(*this > other);
}

Polynomial Polynomial::operator !() const{
    if (m_degree == 0) {
        return Polynomial(); 
    }
    int newDeg = m_degree - 1;
    double* tempCoeffs = new double[newDeg + 1];
    for (int i = 1; i <= m_degree; ++i) {
        tempCoeffs[i - 1] = this -> m_coefs[i] * i;
    }
    Polynomial result(newDeg, tempCoeffs);
    delete[] tempCoeffs;
    return result;
}

Polynomial Polynomial::operator ~() const{
    if (m_degree == 0 && this -> m_coefs[0] == 0) {
        return Polynomial();
    }
    int newDeg = m_degree + 1;
    double* tempCoeffs = new double[newDeg + 1]{0.0}; 
    for (int i = 0; i <= m_degree; ++i) {
        tempCoeffs[i + 1] = 1.0 * this -> m_coefs[i] / (i + 1);
    }
    Polynomial result(newDeg, tempCoeffs);
    delete[] tempCoeffs;
    return result;
}

std::istream& operator>>(std::istream& in, Polynomial& p) {
    std::string line;
    int deg = 0;
    char extra;
    while (true) {
        std::cout << "Nhap bac cua da thuc (so nguyen >= 0): ";
        std::getline(in >> std::ws, line);
        std::stringstream ssDeg(line);
        if ((ssDeg >> deg) && deg >= 0 && !(ssDeg >> extra)) {
            break; 
        }
        std::cout << "  -> [Loi] Bac da thuc phai la mot so nguyen khong am duy nhat! Vui long nhap lai.\n";
    }

    double* tempCoeffs = new double[deg + 1];
    for (int i = deg; i >= 0; --i) {
        while (true) {
            std::cout << "  Nhap he so cua x^" << i << ": ";
            if (!std::getline(in >> std::ws, line)) { 
                delete[] tempCoeffs;
                return in;
            }
            std::stringstream ssCoeff(line);
            if ((ssCoeff >> tempCoeffs[i]) && !(ssCoeff >> extra)) {
                break; 
            }
            std::cout << "  -> [Loi] He so phai la mot so thuc hop le! Vui long nhap lai he so x^" << i << ".\n";
        }
    }

    delete[] p.m_coefs;
    p.m_degree = deg;
    p.m_coefs = tempCoeffs;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    if (p.m_degree == 0 && p.m_coefs[0] == 0) {
        out << 0;
        return out;
    }

    bool firstTerm = true;
    for (int i = p.m_degree; i >= 0; --i) {
        double c = p.m_coefs[i];
        if (c == 0) continue;
        if (!firstTerm) {
            out << (c > 0 ? " + " : " - ");
        } else if (c < 0) {
            out << "-";
        }

        out << (c < 0 ? -c : c);

        if (i > 0) {
            out << "x";
            if (i > 1) out << "^" << i;
        }
        firstTerm = false;
    }

    if (firstTerm) out << 0;
    return out;
}