#pragma once


#include <vector>
#include "../include/Vec.h"

class Mat {

private:
    std::vector<std::vector<double>> data;

public:
    Mat();
    Mat( std::vector<std::vector<double>>& d);

    unsigned rows() const;
    unsigned cols() const;

    Mat operator+(const Mat& m) const;
    Mat operator-(const Mat& m) const;
    Mat operator*(const double scalar) const;
    friend Mat operator*(const double scalar, const Mat& m);

    Vec operator*(const Vec& v) const;

    std::vector<double> operator[](size_t index);
    const std::vector<double> operator[](size_t index) const;

};