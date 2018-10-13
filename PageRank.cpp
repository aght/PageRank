//
// Created by Andy Tang on 10/11/2018.
//

#include "PageRank.hpp"

// Sumns all values in a matrix and returns the sum as a double
double PageRank::sum_matrix(const Matrix &m) {
    double sum = 0;
    for (int i = 0; i < m.get_rows(); i++) {
        for (int j = 0; j < m.get_cols(); j++) {
            sum += m[i][j];
        }
    }

    return sum;
}

// Divides each value in a matrix by a number and returns a new matrix containing the divided values
Matrix PageRank::divide_matrix_values(Matrix m, double n) {
    for (int i = 0; i < m.get_rows(); i++) {
        for (int j = 0; j < m.get_cols(); j++) {
            m[i][j] /= n;
        }
    }

    return m;
}

// Creates an importance matrix
Matrix PageRank::create_importance_matrix(Matrix m) {
    for (int i = 0; i < m.get_cols(); i++) {
        double sum = 0;
        for (int j = 0; j < m.get_rows(); j++) {
            sum += m[j][i];
        }
        if (sum != 0) {
            for (int k = 0; k < m.get_rows(); k++) {
                m[k][i] /= sum;
            }
        } else {
            for (int k = 0; k < m.get_rows(); k++) {
                m[k][i] = (double) 1 / m.get_rows();
            }
        }
    }

    return m;
}

// Runs the markov process
void PageRank::markov(const Matrix &m, Matrix &rank) {
    while (true) {
        Matrix temp = m * rank;
        rank = temp;
        if (temp == (m * rank)) break;
    }
}

// Runs the page rank algorithm and returns a N x 1 matrix containing the results
Matrix PageRank::page_rank(const Matrix &matrix, double p) {
    int n = matrix.get_rows();
    Matrix s = create_importance_matrix(matrix);
    Matrix q = Matrix(n, n, (double) 1 / n);
    Matrix m = p * s + (1 - p) * q;
    Matrix rank = Matrix(n, 1, 1);
    markov(m, rank);
    rank = divide_matrix_values(rank, sum_matrix(rank));

    return rank;
}