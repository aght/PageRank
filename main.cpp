
#include <iostream>
#include "Matrix.hpp"
#include "TextFileReader.hpp"
#include "PageRank.hpp"
#include <iomanip>

double* to_double_array(const std::vector<std::string>& words) {
    double *arr = new double[words.size()];
    for (unsigned i = 0; i < words.size(); i++) {
        arr[i] = std::stod(words[i]);
    }

    return arr;
}

void print_results(const Matrix& m) {
    const double factor = 100;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Page A: " << m[0][0] * factor << "%" << '\n';
    std::cout << "Page B: " << m[1][0] * factor << "%" << '\n';
    std::cout << "Page C: " << m[2][0] * factor << "%" << '\n';
    std::cout << "Page D: " << m[3][0] * factor << "%" << '\n';
}

int main() {
    const double factor = 0.85;

    std::vector<std::string> string_matrix = TextFileReader::read_file("../connectivity.txt");

    double *connectivity_matrix = to_double_array(string_matrix);
    Matrix g(connectivity_matrix, string_matrix.size());

    Matrix rank = PageRank::page_rank(g, factor);

    print_results(rank);

    delete[] connectivity_matrix;

    return 0;
}
