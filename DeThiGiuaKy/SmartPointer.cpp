#ifndef SMARTPOINTER_CPP
#define SMARTPOINTER_CPP

#include "SmartPointer.h"

template <class T>
SmartPointer<T>::SmartPointer() : m_ptr(nullptr), m_count(nullptr) {}

template <class T>
SmartPointer<T>::SmartPointer(T* ptr) : m_ptr(ptr) {
    if (m_ptr != nullptr) {
        m_count = new int(1);
    } else {
        m_count = nullptr;
    }
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& other)
    : m_ptr(other.m_ptr), m_count(other.m_count) {
    if (m_count != nullptr) {
        (*m_count)++;
    }
}

template <class T>
SmartPointer<T>::~SmartPointer() {
    if (m_count != nullptr) {
        (*m_count)--;
        if (*m_count == 0) {
            delete m_ptr;
            delete m_count;
            m_ptr = nullptr;
            m_count = nullptr;
        }
    }
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& other) {
    if (this == &other) {
        return *this;
    }

    if (m_count != nullptr) {
        (*m_count)--;
        if (*m_count == 0) {
            delete m_ptr;
            delete m_count;
        }
    }

    m_ptr = other.m_ptr;
    m_count = other.m_count;
    if (m_count != nullptr) {
        (*m_count)++;
    }

    return *this;
}

template <class T>
int SmartPointer<T>::count_ref() const {
    return (m_count != nullptr) ? *m_count : 0;
}

template <class T>
bool SmartPointer<T>::operator!() const {
    return (m_ptr == nullptr);
}

template <class T>
T* SmartPointer<T>::operator->() const {
    return m_ptr;
}

template <class T>
T& SmartPointer<T>::operator*() const {
    return *m_ptr;
}

#endif 
