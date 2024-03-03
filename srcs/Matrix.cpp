//
// Created by Rachel Sanford on 2/18/24.
//

#include "Matrix.h"

Matrix::Matrix() {
    rows_ = 1;
    cols_ = 1;
    matrix_.resize(rows_, std::vector<double>(cols_, 0.0));
}

Matrix::Matrix(int rows, int cols) {
    if (rows < 1 || cols < 1)
        throw std::invalid_argument("Rows and Cols should be positive integers\n");
    rows_ = rows;
    cols_ = cols;

    matrix_.resize(rows_, std::vector<double>(cols_, 0.0));
}

Matrix::Matrix(const Matrix& other) : rows_(), cols_() {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_.resize(rows_, std::vector<double>(cols_, 0.0));
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j)
            matrix_[i][j] = other.matrix_[i][j];
    }
}

//Matrix::Matrix(Matrix&& other) {
//
//}

Matrix::~Matrix() {
    for (int i = 0; i < rows_; ++i) {
        matrix_[i].clear();
    }
    matrix_.clear();
}

int main(){
    int r = 10;
    int c = 10;
    Matrix m(r, c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            m[i][j] = rand() % 10;
        }
    }
//    Matrix m2(3, 3);
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j)
//            m2[i][j] = rand() % 10;
//    }

    m.Print();
    m.InverseMatrix();
    Matrix comp = m.CalcComplements();
//    std::cout << m.Determinant() << '\n';
//    m.Print();

    return 0;
}




