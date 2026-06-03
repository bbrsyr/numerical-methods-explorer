#pragma once


#include <vector>


class Vec {
private:
    std::vector<double> data;

public:
    Vec();
    Vec(std::vector<double>& d);

    Vec operator+(const Vec& v) const;
    Vec operator-(const Vec& v) const;
    Vec operator*(double scalar) const;
    friend Vec operator*(double scalar, const Vec& v);

    double& operator[](size_t i);
    const double& operator[](size_t i) const;

    double dot(const Vec& v) const;
    double norm() const;

    size_t size() const;
};