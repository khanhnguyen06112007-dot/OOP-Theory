#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
#include <vector>
struct Student{
    std::string name;
    double gpa;
};

struct GPAcount{
    double gpa;
    int count;
};

void countStudentsByGPA(const std::vector<Student>& students, std::vector<GPAcount>& result);
void printStudentCounts(const std::vector<GPAcount>& sortedCounts);

#endif