//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

void Matrix::CopyResult(Matrix& result) {
    int k = 0;
    int rows = this->rows_;
    int cols = this->cols_;
    for (int i = 0; i < rows; ++i) {
        for (int j = rows; j < cols; ++j) {
            result.matrix_[i][k] = this->matrix_[i][j];
            ++k;
        }
        k = 0;
    }
}

void Matrix::InverseAugmented(const Matrix& initial_matrix){
    for (int i = 0; i < initial_matrix.rows_; ++i) {
        for (int j = initial_matrix.rows_; j < initial_matrix.cols_ * 2; ++j) {
            this->matrix_[i][j] = this->matrix_[i][j] / this->matrix_[i][i];
        }
    }
}

void Matrix::CreateAugmentMatrix(const Matrix& initial_matrix) {
    int rows = initial_matrix.rows_;
    int cols = initial_matrix.cols_;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols * 2; ++j) {
            if (j < cols)
                this->matrix_[i][j] = initial_matrix.matrix_[i][j];
            else {
                if (i == (j - cols))
                    this->matrix_[i][j] = 1;
                else
                    this->matrix_[i][j] = 0;
            }
        }
    }
}

Matrix Matrix::InverseMatrix() {
    Matrix res(rows_, cols_);
    if (this->rows_ != this->cols_) {
        throw std::invalid_argument("It's not a square matrix");
    }
    double det = this->Determinant();
    if (det == 0.0) {
        throw std::invalid_argument("Determinant is zero. There's no inverse.\n");
    }

    Matrix adj_matrix(rows_, 2 * cols_);
    adj_matrix.CreateAugmentMatrix(*this);
    adj_matrix.GaussElimination(true);
    adj_matrix.InverseAugmented(*this);
    adj_matrix.CopyResult(res);

    return res;
}