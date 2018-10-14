//
// Created by Andy Tang on 10/11/2018.
//

#ifndef PAGERANK_PAGERANK_HPP
#define PAGERANK_PAGERANK_HPP

#include "Matrix.hpp"

class PageRank {
private:

    // Returns the sum of all values in a matrix
    static double sum_matrix(const Matrix &m);

    // Divides all values inside a matrix by a number
    static Matrix divide_matrix_values(Matrix m, double n);

    // Creates an importance matrix
    static Matrix create_importance_matrix(Matrix m);

    // Performs the markov process
    static void markov(const Matrix &m, Matrix &rank);


public:

    //Runs the page rank algorithm
    static Matrix page_rank(const Matrix& matrix, double p = 0.85);
};


#endif //PAGERANK_PAGERANK_HPP
