#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <class T>
class Matrix {
private:
    int m_rows;
    int m_cols;
    T **m_data;

public:
    Matrix() : m_rows(0), m_cols(0), m_data(nullptr) {}

    // 2. Constructor có tham số
    Matrix(int r, int c) {
        if (r <= 0 || c <= 0) {
            throw std::invalid_argument("r, c phai la so nguyen duong");
        }
        m_rows = r;
        m_cols = c;
        m_data = new T*[m_rows];
        for (int i = 0; i < m_rows; i++) {
            m_data[i] = new T[m_cols](); 
        }
    }

    Matrix(const Matrix<T> &other) {
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        if (m_rows == 0 || m_cols == 0) {
            m_data = nullptr;
            return;
        }
        m_data = new T*[m_rows];
        for (int i = 0; i < m_rows; i++) {
            m_data[i] = new T[m_cols];
            for (int j = 0; j < m_cols; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }

    Matrix<T>& operator=(const Matrix<T> &other) {
        if (this == &other) return *this;
        if (m_data != nullptr) {
            for (int i = 0; i < m_rows; i++) {
                delete [] m_data[i];
            }
            delete [] m_data;
        }

        m_rows = other.m_rows;
        m_cols = other.m_cols;
        if (m_rows == 0 || m_cols == 0) {
            m_data = nullptr;
            return *this;
        }

        m_data = new T*[m_rows];
        for (int i = 0; i < m_rows; i++) {
            m_data[i] = new T[m_cols];
            for (int j = 0; j < m_cols; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
        return *this;
    }

    ~Matrix() {
        if (m_data != nullptr) {
            for (int i = 0; i < m_rows; i++) {
                delete [] m_data[i]; 
            }
            delete [] m_data;
        }
    }

    T findMax() const {
        if (m_rows <= 0 || m_cols <= 0 || m_data == nullptr) {
            throw std::runtime_error("Ma tran rong");
        }
        T res = m_data[0][0];
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                res = std::max(res, m_data[i][j]);
            }
        }
        return res;
    }

    T* operator[](int index) {
        if (index < 0 || index >= m_rows) {
            throw std::out_of_range("index nam ngoai pham vi truy cap");
        }
        return m_data[index];
    }

    const T* operator[](int index) const {
        if (index < 0 || index >= m_rows) {
            throw std::out_of_range("index nam ngoai pham vi truy cap");
        }
        return m_data[index];
    }

    template <class U>
    friend std::istream& operator>>(std::istream &in, Matrix<U> &m) {
        for (int i = 0; i < m.m_rows; i++) {
            for (int j = 0; j < m.m_cols; j++) {
                in >> m.m_data[i][j];
            }
        }
        return in;
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream &out, const Matrix<U> &m) {
        out << "Rows: " << m.m_rows << "\n";
        out << "Cols: " << m.m_cols << "\n";
        for (int i = 0; i < m.m_rows; i++) {
            for (int j = 0; j < m.m_cols; j++) {
                out << m.m_data[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }
};

#endif 