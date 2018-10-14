//
// Created by Andy on 9/25/2018.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

class Matrix {
private:

    // Number of rows in the matrix
    int rows;

    //Number of columns in the matrix
    int cols;

    // 2D vector for storing matrix values
    std::vector<std::vector<double>> m;

public:

    // Constructs a 1 by 1 matrix object
    Matrix();

    // Constructs a N x M matrix object filled with 0
    Matrix(int r, int c);

    // Constructs a N x M matrix object filled with a number
    Matrix(int r, int c, double fill);

    // Constructs a N x N matrix filled with 0
    explicit Matrix(int n);

    // Converts a double array into a N x N matrix, where size must have an integer square root
    Matrix(double arr[], int size);

    // Default copy constructor
    Matrix(const Matrix &m) = default;

    // Default destructor
    ~Matrix() = default;

    // Gets the number of rows
    int get_rows() const;

    // Gets the number of columns
    int get_cols() const;

    // Sets all values inside the matrix to 0
    Matrix &clear();

    // Gets value of matrix at a row and column
    double get_value(int row, int col) const;

    // Sets the value of matrix at a row and column
    void set_value(int row, int col, double n);

    // Returns a row of the matrix, which by the user can index again to get a value of the matrix
    // Similar to indexing a 2D array
    std::vector<double> &operator[](int index);

    // Returns a row of the matrix, which by the user can index again to get a value of the matrix
    // Similar to indexing a 2D array
    const std::vector<double> &operator[](int index) const;

    // Assignment operator
    Matrix &operator=(Matrix rhs);

    // Multiplies a matrix by a value
    Matrix &operator*=(double rhs);

    // Multiplies a matrix by a matrix
    Matrix &operator*=(const Matrix &rhs);

    // Adds this matrix to another matrix
    Matrix &operator+=(const Matrix &rhs);

    // (Postfix) Increments all values inside matrix by 1
    Matrix &operator++();

    // (Postfix) Decrements all values inside matrix by 1
    Matrix &operator--();

    // (Prefix) Increments all values inside matrix by 1
    Matrix operator++(int);

    // (Prefix) Decrements all values inside matrix by 1
    Matrix operator--(int);

    // Prints matrix to ostream
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    // Checks if two matrix are the same by comparing values and matrix size
    friend bool operator==(const Matrix &lhs, const Matrix &rhs);

    // Opposite of equality operator
    friend bool operator!=(const Matrix &lhs, const Matrix &rhs);

    // Adds two matrices
    friend Matrix operator+(Matrix lhs, const Matrix &rhs);

    // Multiplies matrix by a value
    friend Matrix operator*(Matrix lhs, const double rhs);

    // Multiplies matrix by a value
    friend Matrix operator*(double lhs, Matrix rhs);

    // Multiplies two matrices
    friend Matrix operator*(Matrix lhs, const Matrix &rhs);
};

// Prints matrix to ostream
inline std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix[i][j] << "\t";
        }
        os << std::endl;
    }

    return os;
}

// Checks if two matrix are the same by comparing values and matrix size
inline bool operator==(const Matrix &lhs, const Matrix &rhs) {
    const double TOLERANCE = 0.00001;

    if (lhs.rows == rhs.rows && lhs.cols == rhs.cols) {
        for (int i = 0; i < lhs.rows; i++) {
            for (int j = 0; j < lhs.cols; j++) {
                return (std::abs(rhs[i][j] - lhs[i][j])) < TOLERANCE;
            }
        }

        return true;
    }

    return false;
}

// Opposite of equality operator
inline bool operator!=(const Matrix &lhs, const Matrix &rhs) {
    return !operator==(lhs, rhs);
}

// Adds two matrices
inline Matrix operator+(Matrix lhs, const Matrix &rhs) {
    lhs += rhs;
    return lhs;
}

// Multiplies matrix by a value
inline Matrix operator*(Matrix lhs, const double rhs) {
    lhs *= rhs;
    return lhs;
}

// Multiplies matrix by a value
inline Matrix operator*(double lhs, Matrix rhs) {
    rhs *= lhs;
    return rhs;
}

// Multiplies two matrices
inline Matrix operator*(Matrix lhs, const Matrix &rhs) {
    lhs *= rhs;
    return lhs;
}

#endif //PAGERANK_MATRIX_HPP
