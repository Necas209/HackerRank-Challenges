//
// Created by diogo on 06/10/2022.
//

#ifndef HACKERRANK_MATRIX_H
#define HACKERRANK_MATRIX_H

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
std::vector<T> operator+(const std::vector<T> &v1, const std::vector<T> &v2);

template<typename T>
class matrix;

template<typename T>
matrix<T> operator+(const matrix<T> &m1, const matrix<T> &m2);

template<typename T>
std::istream &operator>>(std::istream &is, matrix<T> &_m);

template<typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &_m);

template<typename T>
class matrix {
private:
    int n_rows{};
    int n_columns{};
    std::vector<std::vector<T>> a;

public:
    matrix(int _rows, int _columns);;

    void add_row(const std::vector<T> &_v);

    auto begin() { return a.begin(); }

    auto end() { return a.end(); }

    std::vector<T> &operator[](size_t _n);

    friend matrix<T> operator+<T>(const matrix<T> &m1, const matrix<T> &m2);

    friend std::istream &operator>>(std::istream &is, matrix<T> &_m);

    friend std::ostream &operator<<(std::ostream &os, const matrix<T> &_m);
};

#endif //HACKERRANK_MATRIX_H
