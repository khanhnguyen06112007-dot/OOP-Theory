#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#include <iostream>

template <class T>
class Array{
private:
    int m_size;
    T *m_data;
public:
    Array();
    Array(int length);
    Array(const T*data, int length);
    Array(const Array<T> &other);
    ~Array();
    void outputArray() const;
};

//==================================================================//
template<class T>
Array<T>::Array(){
    m_size = 0;
    m_data = nullptr;
}

template<class T>
Array<T>::Array(int length){
    if (length < 0){
        throw std::invalid_argument("Kich thuoc mang khong the am");
    }
    if (length == 0){
        m_size = 0;
        m_data = nullptr;
    }
    else{
        m_size = length;
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++){
            m_data[i] = 0;
        }
    }
}

template <class T>
Array<T>::Array(const T*data, int length){
    if (length < 0){
        throw std::invalid_argument("Kich thuoc mang khong the am");
    }
    if (length == 0){
        m_size = 0;
        m_data = nullptr;
    }
    else{
        m_size = length;
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++){
            this -> m_data[i] = data[i];
        }
    }
}

template <class T>
Array<T>::Array(const Array<T> &other){
    if (other.m_size == 0){
        this -> m_size = 0;
        this -> m_data = nullptr;
    }
    else{
        m_size = other.m_size;
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++){
            this -> m_data[i] = other.m_data[i];
        }
    }
}

template <class T>
Array<T>::~Array(){
    delete []m_data;
}

template <class T>
void Array<T>::outputArray() const{
    if (m_size == 0){
        std::cout << "Size: " << 0 << "\n";
        std::cout << "Array is Empty\n";
    }
    else{
        std::cout << "Size: " << m_size << "\n";
        std::cout << "Element in array: " << "\n";
        for (int i = 0; i < m_size; i++){
            std::cout << m_data[i] << " ";
        }
        std::cout << "\n";
    }
}
//==================================================================//


#endif

