//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

void row_copy(std::vector<double>& term1, const std::vector<double>& term2, int columns) {
    for (int i = 0; i < columns; ++i)
        term1[i] = term2[i];
}

void Matrix::SwapRows(int row_1, int row_2) {
    std::vector<double> tmp(cols_);

    row_copy(tmp, matrix_[row_1], cols_);
    row_copy(matrix_[row_1], matrix_[row_2], cols_);
    row_copy(matrix_[row_2], tmp, cols_);
}