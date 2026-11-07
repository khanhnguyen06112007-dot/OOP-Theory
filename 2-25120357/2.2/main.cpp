#include "Monomial.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

int main(){
    Monomial first;
    Monomial second;

    std::cout << "Enter first Monomial: \n";
    first.input();
    std::cout << "First monomial is: ";
    first.output();

    std::cout << "Enter second Monomial: \n";
    second.input();
    std::cout << "Second monomial is: ";
    second.output();

    char line[100];
    float x;
    do{
        std::cout << "Enter value of x to compute first monomial: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> x));

    std::cout << "Value of first monomial by x = " << x << " is: ";
    std::cout << std::fixed << std::setprecision(2) << first.evaluate(x) << "\n";

    Monomial multiple = first.mul(second);
    std::cout << "multiple of two monomial is: ";
    multiple.output();

    Monomial der = second.derive();
    std::cout << "Derive of second Monomial is: ";
    der.output();

    std::cout << "Test getcoef, getexpo, setcoef, setexpo: \n";
    std::cout << "coef of First monomial is: " << first.getCoef() << "\n";
    std::cout << "expo of First monomial is: " << first.getExpo() << "\n";

    try{
        char line[100];
        float coef;
        do{
            std::cout << "Enter coef you want to change in Second monomial: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> coef));
        second.setCoef(coef);

        int expo;
        do{ 
            std::cout << "Enter expo you want to change in Second monomial: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> expo));
        second.setExpo(expo);

        std::cout << "Second monomial after changing is: ";
        second.output();
    }catch(std::out_of_range &error){
        std::cout << "Error: " << error.what() << "\n";
    }

    return 0;
}