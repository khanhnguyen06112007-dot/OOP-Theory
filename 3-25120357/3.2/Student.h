#ifndef STUDENT_H
#define STUDENT_H
class Student{
private:
    char *name;
    double mathScore;
    double literatureScore;
public:
    Student(char *name, double math, double lit);
    Student(char *name);
    Student(const Student &other);
    ~Student();
    void printInforStudent() const;
};
#endif