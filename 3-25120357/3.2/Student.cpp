#include "Student.h"
#include <cstring>
#include <iostream>

Student::Student(char *name, double math, double lit){
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    mathScore = math;
    literatureScore = lit;
}

Student::Student(char *name){
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    mathScore = 0;
    literatureScore = 0;
}
Student::Student(const Student &other){
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, other.name);
    mathScore = other.mathScore;
    literatureScore = other.literatureScore;
}
Student::~Student(){
    delete []name;
}

void Student::printInforStudent() const{
    std::cout << "Name: " << name << "\n";
    std::cout << "Math score: " << mathScore << "\n";
    std::cout << "Literature score: " << literatureScore << "\n";
}