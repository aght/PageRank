//
// Created by Andy on 9/25/2018.
//

#include "Matrix.hpp"

// Constructs a 1 x 1matrix  filled with 0
Matrix::Matrix() :
        rows(1),
        cols(1),
        m(1, std::vector<double>(1, 0.0)) {}

// Constructs a N X M matrix filled with 0
Matrix::Matrix(int r, int c) :
        rows(r),
        cols(c),
        m(r, std::vector<double>(c)) {}

// Constructs a N X M matrix filled with a number
Matrix::Matrix(int r, int c, double fill) :
        rows(r),
        cols(c),
        m(r, std::vector<double>(c, fill)) {}

// Constructs a N X N matrix filled with 0
Matrix::Matrix(int n) {
    if (n < 1) throw std::invalid_argument("dimensions of the matrix must be greater than 0");
    rows = n;
    cols = n;
    m = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));
}

// Constructs a N x N matrix from an array, where the size must have an integer square root
Matrix::Matrix(double arr[], int size) {
    double s = sqrt(size);
    if ((s * s) != size) {
        throw std::invalid_argument("size of array must have an integer square root");
    }

    rows = s;
    cols = s;

    m = std::vector<std::vector<double>>(s, std::vector<double>(s));

    int k = 0;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            m[i][j] = arr[k];
            ++k;
        }
    }
}

// Gets the number of rows in the matrix
int Matrix::get_rows() const { return rows; }

// Gets the number of columns in the matrix
int Matrix::get_cols() const { return cols; }

// Sets all values in matrix to 0
Matrix &Matrix::clear() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = 0;
        }
    }

    return *this;
}

// Gets a value from the matrix by index
double Matrix::get_value(int row, int col) const {
    if (row <= 0 || row >= rows || col <= 0 || col >= cols) {
        throw std::out_of_range("invalid index");
    }
    return m[row][col];
}

// Sets a value from the matrix by index
void Matrix::set_value(int row, int col, double n) {
    if (row <= 0 || row >= rows || col <= 0 || col >= cols) {
        throw std::out_of_range("invalid index");
    }
    m[row][col] = n;
}

// Returns a row of the matrix, which by the user can index again to get a value of the matrix
// Similar to indexing a 2D array
std::vector<double> &Matrix::operator[](int index) {
    return m[index];
}

// Returns a row of the matrix, which by the user can index again to get a value of the matrix
// Similar to indexing a 2D array
const std::vector<double> &Matrix::operator[](int index) const {
    return m[index];
}

// Assignment operator
Matrix &Matrix::operator=(Matrix rhs) {
    std::swap(this->m, rhs.m);
    std::swap(this->cols, rhs.cols);
    std::swap(this->rows, rhs.rows);

    return *this;
}

// Multiplies a matrix by a value
Matrix &Matrix::operator*=(const double rhs) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] *= rhs;
        }
    }

    return *this;
}

// Multiplies a matrix by a matrix
Matrix &Matrix::operator*=(const Matrix &rhs) {
    if (cols != rhs.rows) {
        throw std::invalid_argument("number of columns in matrix A and number of rows in matrix B must match");
    }

    std::vector<std::vector<double>> p(rows, std::vector<double>(rhs.cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rhs.cols; j++) {
            for (int k = 0; k < cols; k++) {
                p[i][j] += m[i][k] * rhs.m[k][j];
            }
        }
    }

    cols = rhs.cols;
    m = p;

    return *this;
}

// Adds this matrix to another matrix
Matrix &Matrix::Matrix::operator+=(const Matrix &rhs) {
    if (rows != rhs.rows && cols != rhs.cols) {
        throw std::invalid_argument("matrices must be of the same dimensions");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] += rhs[i][j];
        }
    }

    return *this;
}

// (Postfix) Increments all values inside matrix by 1
Matrix &Matrix::operator++() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j]++;
        }
    }

    return *this;
}

// (Postfix) Decrements all values inside matrix by 1
Matrix &Matrix::operator--() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j]--;
        }
    }

    return *this;
}

// (Prefix) Increments all values inside matrix by 1
Matrix Matrix::Matrix::operator++(int) {
    Matrix tmp(*this);
    operator++();
    return tmp;
}

// (Prefix) Decrements all values inside matrix by 1
Matrix Matrix::Matrix::operator--(int) {
    Matrix tmp(*this);
    operator--();
    return tmp;
}