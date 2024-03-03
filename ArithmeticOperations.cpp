//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

void Matrix::SumMatrix(const Matrix &other) {

    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Matrices have different size\n");
    for (int i = 0; i < other.rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void Matrix::SubMatrix(const Matrix &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Matrices have different size\n");
    for (int i = 0; i < other.rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

void Matrix::MulNumber(const double num) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] *= num;
        }
    }
}

bool Matrix::EqMatrix(const Matrix& other) {
    bool answer = true;
    if (rows_ != other.rows_ || cols_ != other.cols_)
        answer = false;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            if (matrix_[i][j] != other.matrix_[i][j])
                answer = false;
        }
    }
    return answer;
}

// FIX

void Matrix::MulMatrix(const Matrix &other) {

    Matrix buff(other.rows_, other.cols_);

    if (cols_ != other.rows_)
        throw std::invalid_argument("Matrix 1 COLS should be equal to Matrix 2 ROWS\n");
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                buff[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    this->matrix_ = buff.matrix_;
}