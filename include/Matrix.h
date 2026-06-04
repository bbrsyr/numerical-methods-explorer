#pragma once


#include <vector>
#include "../include/Vec.h"

class Mat {

private:
    std::vector<std::vector<double>> data;

public:
    Mat();
    Mat(const size_t rows, const size_t cols);

    size_t rows() const;
    size_t cols() const;

    Mat operator+(const Mat& m) const;
    Mat operator-(const Mat& m) const;
    Mat operator*(const double scalar) const;
    friend Mat operator*(const double scalar, const Mat& m);
    Mat operator*(const Mat& m) const;

    Vec operator*(const Vec& v) const;

    std::vector<double>& operator [](size_t index);
    const std::vector<double>& operator[](size_t index) const;

    Mat transpose() const;
    static Mat identity(size_t n);
    double determinant() const;
    Mat inverse() const;

};