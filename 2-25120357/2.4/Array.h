#ifndef ARRAY_H
#define ARRAY_H
class Array{
private:
    int *arr;
    int size;
public:
    void input();
    void output() const;

    int getSize() const;
    void setSize(int size);

    int getElement(int index) const;
    void setElement(int index, int num);

    int find(int num) const;

    void sort(bool Compare(int, int));
    void Destroy();
};
#endif