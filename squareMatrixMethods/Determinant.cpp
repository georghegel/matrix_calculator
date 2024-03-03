//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

double Matrix::Determinant() {
    if (rows_ != cols_)
        throw std::invalid_argument("This is not square matrix!\n");
    Matrix row_echelon(*this);
    row_echelon.GaussElimination(false);
    double det = 1.0;
    for (int i = 0; i < cols_; ++i)
        det *= row_echelon[i][i];
    return det;
}