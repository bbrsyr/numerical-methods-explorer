#include "../include/Matrix.h"
#include "../include/Vec.h"

#include <vector>
#include <cerrno>

Mat::Mat() {
    data = {{0}};
}

Mat::Mat(std::vector<std::vector<double>>& d) {
    data = d;
}

unsigned Mat::rows() const {
    return data.size();
}

unsigned Mat::cols() const {
    return data[0].size();
}

Mat Mat::operator+(const Mat& m) const{
    if (rows() != m.rows() || cols() != m.cols()) {
        throw std::invalid_argument("Dimensions must match.");
    }

    Mat result;
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            result[i][j] = data[i][j] + m[i][j];
        }
    }
    return result;
}

Mat Mat::operator-(const Mat& m) const{
    if (rows() != m.rows() || cols() != m.cols()) {
        throw std::invalid_argument("Dimensions must match.");
    }

    Mat result;
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            result[i][j] = data[i][j] - m[i][j];
        }
    }
    return result;
}

Mat Mat::operator*(const double scalar) const {

    Mat result;
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            result[i][j] = data[i][j] * scalar;
        }
    }

    return result;
}

Vec Mat::operator*(const Vec& v) const{
    if (cols() != v.size()) {
        throw std::invalid_argument("Multiplication is not possible (incompatible dimensions)");
    }

    std::vector<double> result(rows());

    for (int i = 0; i < rows(); i++) {
        double sum = 0;

        for (int j = 0; j < v.size(); j++) {
            sum = data[i][j] * v[j];
        }
        result[i] = sum;
    }

    return Vec(result);
}