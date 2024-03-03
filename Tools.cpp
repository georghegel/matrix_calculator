//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

void Matrix::Print() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << matrix_[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

int Matrix::GetCols() const {
    return this->cols_;
}

int Matrix::GetRows() const {
    return this->rows_;
}
