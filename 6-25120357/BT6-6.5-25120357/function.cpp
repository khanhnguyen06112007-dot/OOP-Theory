#include "function.h"
#include <iostream>
#include <map>
#include <algorithm>
void countStudentsByGPA(const std::vector<Student>& students, std::vector<GPAcount>& result) {
    std::map<double, int> frequencyMap;
    for (const auto& student : students) {
        frequencyMap[student.gpa]++;
    }

    for (const auto& pair : frequencyMap) {
        result.push_back({pair.first, pair.second});
    }

    std::sort(result.begin(), result.end(), [](const GPAcount& a, const GPAcount& b) {
        return a.count > b.count;
    });
}

void printStudentCounts(const std::vector<GPAcount>& sortedCounts) {
    for (const auto& item : sortedCounts) {
        std::cout << "GPA " << item.gpa << ": " << item.count << " students.\n";
    }
}