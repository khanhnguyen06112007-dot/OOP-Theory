#include <iostream>
#include "Fraction.h"


int main() {
    Fraction p1(1, 2), p2(3, 4);
    Fraction F;
    std::cout << "Enter Fraction F: ";
    std::cin >> F;

    std::cout << "p1 = " << p1;
    std::cout << "p2 = " << p2;
    std::cout << "Fraction F: " << F;

    Fraction p3 = p1 + p2;
    std::cout << "p1 + p2 = " << p3;

    Fraction p4 = p1 * p2;
    std::cout << "p1 * p2 = " << p4;

    std::cout << "p1 > p2 : " << (p1 > p2) << "\n";
    std::cout << "p1 == p2: " << (p1 == p2) << "\n";
    
    p1 += p2;
    std::cout << "p1 += p2 -> p1 = " << p1;

    p1++;
    std::cout << "p1++ -> p1 = " << p1;

    float f = (float)p1;
    std::cout << "(float)p1 = " << f;

    int i = (int)p2;
    std::cout << "(int)p2 = " << i << "\n";

    return 0;
}