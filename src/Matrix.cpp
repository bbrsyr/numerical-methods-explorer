#include "../include/Matrix.h"
#include "../include/Vec.h"

#include <vector>
#include <cerrno>

Mat::Mat() = default;

Mat::Mat(const size_t rows, const size_t cols) : data(rows, std::vector<double>(cols, 0)) {
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i].size() != data[0].size()) {
            throw std::invalid_argument("Jagged matrix.");
        }
    }
}

size_t Mat::rows() const {
    return data.size();
}

size_t Mat::cols() const {
    if (data.empty()) return 0;
    else return data[0].size();
}

Mat Mat::operator+(const Mat& m) const{
    if (rows() != m.rows() || cols() != m.cols()) {
        throw std::invalid_argument("Dimensions must match.");
    }

    Mat result(rows(), cols());
    for (size_t i = 0; i < rows(); i++) {
        for (size_t j = 0; j < cols(); j++) {
            result[i][j] = data[i][j] + m[i][j];
        }
    }
    return result;
}

Mat Mat::operator-(const Mat& m) const{
    if (rows() != m.rows() || cols() != m.cols()) {
        throw std::invalid_argument("Dimensions must match.");
    }

    Mat result(rows(), cols());
    for (size_t i = 0; i < rows(); i++) {
        for (size_t j = 0; j < cols(); j++) {
            result[i][j] = data[i][j] - m[i][j];
        }
    }
    return result;
}

Mat Mat::operator*(const double scalar) const {

    Mat result(rows(), cols());
    for (size_t i = 0; i < rows(); i++) {
        for (size_t j = 0; j < cols(); j++) {
            result[i][j] = data[i][j] * scalar;
        }
    }

    return result;
}

Mat operator*(double scalar, const Mat& m) {
    return m * scalar;
}

Vec Mat::operator*(const Vec& v) const{
    if (cols() != v.size()) {
        throw std::invalid_argument("Multiplication is not possible (incompatible dimensions).");
    }

    std::vector<double> result(rows());

    for (size_t i = 0; i < rows(); i++) {
        double sum = 0;

        for (size_t j = 0; j < v.size(); j++) {
            sum += data[i][j] * v[j];
        }
        result[i] = sum;
    }

    return Vec(result);
}

Mat Mat::operator*(const Mat& m) const{
    if (cols() != m.rows()) {
        throw std::invalid_argument("Multiplication is not possible (incompatible dimensions).");
    }

    Mat result(rows(), m.cols());

    for (size_t i = 0; i < rows(); i++) {
        for (size_t j = 0; j < m.cols(); j++) {
            double sum = 0;
            for (size_t k = 0; k < cols(); k++) {
                sum += data[i][k] * m[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

std::vector<double>& Mat::operator[](size_t index) {
    return data.at(index);
}

const std::vector<double>& Mat::operator[](size_t index) const{
    return data.at(index);
}


Mat Mat::transpose() const {
    Mat result(cols(), rows());

    for (size_t i = 0; i < cols(); i++) {
        for (size_t j = 0; j < rows(); j++) {
            result[i][j] = data[j][i];
        }
    }
    return result;
}

Mat Mat::identity(size_t n) {
    Mat result(n, n);

    for (size_t i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    return result;
}

Vec Mat::solve(const Vec& v) {
    Mat A = *this;
    Vec rhs = v;
    size_t n = rows();

    for (size_t k = 0; k < n; k++) {
        for (size_t i = k + 1; i < n; i++) {

            double factor = A[i][k] / A[k][k];

            for (size_t j = k; j < n; j++) {
                A[i][j] -= factor * rhs[k];
            }

            rhs[i] -= factor * rhs[k];
        }
    }

    std::vector<double> x(n);

    for (size_t i = n - 1; i >= 0; i--) {
        double sum = 0;

        for (size_t j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }

        x[i] = (rhs[i] - sum) / A[i][i];
    }
    return Vec(x);
}































