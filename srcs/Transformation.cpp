//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

Matrix Matrix::Transpose() {
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result[j][i] = matrix_[i][j];
        }
    }
    this->matrix_ = result.matrix_;
    return *this;
}
