#include "Fraction.h"
#include <iostream>

int main(){
    Fraction first;
    Fraction second;

    std::cout << "Enter first Fraction\n";
    first.input();
    std::cout << "First fraction is: ";
    first.output();
    first = first.reduce();
    std::cout << "Reduction of first Fraction: ";
    first.output();

    std::cout << "Enter second Fraction\n";
    second.input();
    std::cout << "second fraction is: ";
    second.output();
    second = second.reduce();
    std::cout << "Reduction of second Fraction: ";
    second.output();

    int check = first.compare(second);
    if (check == 0){
        std::cout << "Two fraction are equals\n";
    }
    else if (check == 1){
        std::cout << "The first Fraction is greater than the second one\n";
    }
    else {
        std::cout << "The first Fraction is less than the second one\n";
    }

    Fraction sum = first.add(second);
    sum = sum.reduce();
    std::cout << "Sum of first and second Fraction: ";
    sum.output();


    std::cout << "Test inverse with first Fraction\n";
    try{
        Fraction inverse1 = first.inverse();
        std::cout << "Inverse of first Fraction is: ";
        inverse1.output();
    }catch(const std::invalid_argument &error){
        std::cout << error.what() << std::endl;
    }

    std::cout << "Test getNum, getDen, setNum, setDen\n";
    std::cout << "First fraction is: " << first.getNum() << "/" << first.getDenom() << "\n";
    try{
        std::cout << "Enter numerator you want to change in first fraction: ";
        int num;
        std::cin >> num;
        first.setNum(num);

        std::cout << "Enter denominator you want to change in first fraction: ";
        int den;
        std::cin >> den;
        first.setDenom(den);
        std::cout << "First fraction after changing: ";
        first.output();
    }catch(const std::invalid_argument &error){
        std::cout << error.what() << std::endl;
    }

    return 0;
}