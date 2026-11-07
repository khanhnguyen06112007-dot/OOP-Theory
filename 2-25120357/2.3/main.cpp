#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int main(){
    Student a;
    std::cout << "Input information about Student a: \n";
    a.input();
    std::cout << "Information of Student a: \n";
    a.output();

    std::cout << "GPA of Student a is: " << std::fixed 
              << std::setprecision(2) << a.calculateGPA() << "\n";
    std::cout << "The grade of student a is: " << a.grade() << "\n";

    std::cout << "Test getName, getLit, getMath: \n";
    std::cout << "Information of Student a: \n";
    std::cout << a.getName() << "\n"
              << a.getLit() << "\n"
              << a.getMath() << "\n";

    try{
        std::string name;
        std::cout << "Enter name you want to change in Student a: ";
        std::getline(std::cin, name);
        a.setName(name);

        char line[100];
        double lit;
        do{
            std::cout << "Enter Literature score you want to change in Student a: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> lit));
        a.setLit(lit);

        double math;
        do{
            std::cout << "Enter Mathematics score you want to change in Student a: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> math));
        a.setMath(math);

        std::cout << "Information of Student a after changing is: \n";
        a.output();
    }catch(std::out_of_range &error){
        std::cout << "Error: " << error.what() << "\n";
    }

    return 0;
}