//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

Matrix Matrix::CalcComplements() {
    if (this->rows_ != this->cols_) {
        throw std::invalid_argument("Non square");
    }

    double det = this->Determinant();
    if (det == 0.0) {
        throw std::invalid_argument("Determinant is zero. No complements");
    }

    Matrix inverse = this->InverseMatrix();
    inverse.MulNumber(det);
    inverse.Transpose();

    return inverse;
}
