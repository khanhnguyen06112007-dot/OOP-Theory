#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <class T>
class SmartPointer {
private:
    T* m_ptr;
    int* m_count;

public:
    SmartPointer();
    SmartPointer(T* ptr);
    SmartPointer(const SmartPointer<T>& other);
    ~SmartPointer();

    SmartPointer<T>& operator=(const SmartPointer<T>& other);

    int count_ref() const;
    bool operator!() const;
    T* operator->() const;
    T& operator*() const;
};
#include "SmartPointer.cpp"
#endif
