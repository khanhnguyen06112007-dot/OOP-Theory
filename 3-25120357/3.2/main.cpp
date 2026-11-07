#include "Student.h"
#include <cstring>
#include <iostream>

const int MAX_LENGTH = 50;

int main(){
    std::cout << "\n========================\n";
    char name1[] = "Nguyen Van Khanh";
    Student s1(name1, 9.5, 8.0);
    std::cout << "Information about s1 student is: \n";
    s1.printInforStudent();
    std::cout << "===========================\n";
    
    std::cout << "\n==========================\n";
    char name2[] = "Nguyen Van A";
    Student s2(name2);
    std::cout << "Information about s2 student is: \n";
    s2.printInforStudent();
    std::cout << "============================\n";

    std::cout << "\n==========================\n";
    Student s3(s1);
    std::cout << "A copy information of s1: \n";
    s3.printInforStudent();
    std::cout << "=============================\n";
    return 0;
}


