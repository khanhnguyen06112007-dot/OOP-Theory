#include "Student.h"
#include <iostream>
#include <sstream>
#include <string>
void Student::input(){
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    char line[100];
    do{
        std::cout << "Enter Literature score: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> lit) || lit < 0 || lit > 10);
    do{
        std::cout << "Enter Mathematics score: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> math) || math < 0 || math > 10);
}


void Student::output() const{
    std::cout << "Name: " << name << "\n";
    std::cout << "Literature score: " << lit << "\n";
    std::cout << "Mathematics score: " << math << "\n";
}   

std::string Student::getName() const{
    return name;
}    
void Student::setName(std::string name){
    if (name.size() == 0){
        throw std::invalid_argument("Ten la 1 chuoi rong");
    }
    this -> name = name;
}

double Student::getLit() const{
    return lit;
}
void Student::setLit(double L){
    if (L < 0 || L > 10){
        throw std::out_of_range("Diem so nam ngoai pham vi tu 0 den 10");
    }
    lit = L;
}
double Student::getMath() const{
    return math;
}
void Student::setMath(double M){
    if (M < 0 || M > 10){
        throw std::out_of_range("Diem so nam ngoai pham vi tu 0 den 10");
    }
    math = M;
}
    
double Student::calculateGPA() const{
    double res = (math + lit) / 2.0;
    return res;
}
char Student::grade() const{
    double GPA = this -> calculateGPA();
    if (GPA >= 9.0){
        return 'A';
    }
    else if (GPA >= 7.0){
        return 'B';
    }
    else if (GPA >= 5.0){
        return 'C';
    }
    else{
        return 'D';
    }
}