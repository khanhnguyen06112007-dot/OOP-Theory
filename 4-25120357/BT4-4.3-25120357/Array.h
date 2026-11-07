#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept>
//======================================//
template <class T>
class Array{
private:
    T* m_data;
    int m_size;
public:
    Array(int length);
    Array(const Array<T> &other);
    ~Array();

    Array<T> operator = (const Array<T> &other);
    T& operator [] (int index);
    operator T*();

    template <class X>
    friend std::istream& operator >> (std::istream &in, Array<X> &a);
    
    template <class X>
    friend std::ostream& operator << (std::ostream &out, const Array<X> &a);
};
//======================================//
template <class T>
Array<T>::Array(int length){
    if (length < 0){
        throw std::invalid_argument("Mang kich thuoc bi am");
    }
    m_size = length;
    if (m_size == 0){
        m_data = nullptr;
    }
    else{
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++){
            m_data[i] = 0;
        }
    }
}

template <class T>
Array<T>::Array(const Array<T> &other){
    this -> m_size = other.m_size;
    if (this -> m_size == 0){
        this -> m_data = nullptr;
    }
    else{
        this -> m_data = new T[m_size];
        for (int i = 0; i < m_size; i++){
            this -> m_data[i] = other.m_data[i];
        }
    }
}

template<class T>
Array<T>::~Array(){
    delete []m_data;
}

template <class T>
Array<T> Array<T>::operator = (const Array<T> &other){
    if (this != &other){
        delete []m_data;
        this -> m_size = other.m_size;
        if (this -> m_size == 0){
            this -> m_data = nullptr;
        }
        else{
            this -> m_data = new T[this -> m_size];
            for (int i = 0; i < this -> m_size; i++){
                this -> m_data[i] = other.m_data[i];
            }
        }
    }
    return *this;
}

template <class T>
T& Array<T>::operator [] (int index){
    if (index < 0 || index >= this -> m_size){
        throw std::out_of_range("Index nam ngoai pham vi mang");
    }
    return m_data[index];
}

template <class T>
Array<T>::operator T*(){
    return m_data;
}

template <class X>
std::istream& operator >> (std::istream &in, Array<X> &a){
    for (int i = 0; i < a.m_size; i++) {
        in >> a.m_data[i];
    }
    return in;
}
    
template <class X>
std::ostream& operator << (std::ostream &out, const Array<X> &a){
    for (int i = 0; i < a.m_size; i++) {
        out << a.m_data[i] << " ";
    }
    return out;
}
#endif