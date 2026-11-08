#include <vector>
#include "function.h"
int main() {
    std::vector<Student> students = {
        {"John", 7}, {"Eve", 9}, {"Ander", 7}, 
        {"Dora", 8}, {"Tom", 7}, {"Alex", 9}
    };

    std::vector<GPAcount> sortedCounts;

    countStudentsByGPA(students, sortedCounts);
    printStudentCounts(sortedCounts);

    return 0;
}