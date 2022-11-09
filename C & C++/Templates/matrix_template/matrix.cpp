//
// Created by diogo on 06/10/2022.
//

#include "matrix.h"

template<typename T>
matrix<T>::matrix(int n_rows, int n_columns) {
    this->n_rows = n_rows;
    this->n_columns = n_columns;
}

template<typename T>
void matrix<T>::add_row(const std::vector<T> &_v) {
    a.push_back(_v);
}

template<typename T>
std::vector<T> operator+(const std::vector<T> &v1, const std::vector<T> &v2) {
    std::vector<T> v3;
    std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(v3),
                   [](const auto &t1, const auto &t2) {
                       return t1 + t2;
                   });
    return v3;
}

template<typename T>
std::vector<T> &matrix<T>::operator[](size_t _n) {
    return a[_n];
}

template<typename T>
matrix<T> operator+(const matrix<T> &m1, const matrix<T> &m2) {
    matrix<T> m3;
    std::transform(m1.a.begin(), m1.a.end(),
                   m2.a.begin(), std::back_inserter(m3.a),
                   [](const auto &v1, const auto &v2) {
                       return v1 + v2;
                   });
    return m3;
}

template<typename T>
std::istream &operator>>(std::istream &is, matrix<T> &_m) {
    for (int i = 0; i < _m.n_rows; i++) {
        std::vector<int> row;
        int num;
        for (int j = 0; j < _m.n_columns; j++) {
            std::cin >> num;
            row.push_back(num);
        }
        _m.add_row(row);
    }
    return is;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &_m) {
    for (auto &row: _m) {
        for (auto &el: row) {
            os << el << ' ';
        }
        os << std::endl;
    }
    return os;
}