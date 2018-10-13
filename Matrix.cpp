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
}