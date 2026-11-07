#include "Fraction.h"
#include <iostream>

int main(){
    Fraction f1;
    std::cout << "Fraction f1: ";
    f1.printFraction();

    Fraction f2(5);
    std::cout << "Fraction f2: ";
    f2.printFraction();

    Fraction f3(2, 7);
    std::cout << "Fraction f3: ";
    f3.printFraction();

    Fraction f4(f3);
    std::cout << "Fraction f4: ";
    f4.printFraction();

    return 0;
}