#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student{
private:   
    std::string name;
    double lit;
    double math;
public:
    void input();
    void output() const;

    std::string getName() const;    
    void setName(std::string name);

    double getLit() const;
    void setLit(double L);

    double getMath() const;
    void setMath(double M);
    
    double calculateGPA() const;
    char grade() const;
}; 
#endif