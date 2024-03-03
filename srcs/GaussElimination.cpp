//
// Created by Rachel Sanford on 2/23/24.
//

#include "Matrix.h"

int find_non_zero_diagonal_element(int start, Matrix& matrix){
    int answer = start - 1;
    for (int i = start; i < matrix.GetRows() && answer == start - 1; ++i) {
        if (matrix[i][i] != 0.0)
            answer = i;
    }
    return answer;
}

void elimination_processor(double *ratio, Matrix& row_echelon, int i, int j, int dimension, bool for_inverse){
    dimension = for_inverse ? dimension * 2 : dimension;
    *ratio = row_echelon[j][i] / row_echelon[i][i];
    for (int k = 0; k < dimension; ++k)
        row_echelon[j][k] = row_echelon[j][k] - *ratio * row_echelon[i][k];
}

void Matrix::GaussElimination(bool inverse){
    double ratio = 0.0;
    int first_zero_occur;
    for (int i = 0; i < rows_; ++i) {
        if (matrix_[i][i] == 0.0) {
            first_zero_occur = i;
            int non_zero_diag_element = find_non_zero_diagonal_element(i + 1, *this);
            if (matrix_[non_zero_diag_element][non_zero_diag_element] != 0.0) {
                this->SwapRows(first_zero_occur, non_zero_diag_element);
                for (int index = 0; index < rows_; ++index) matrix_[i][index] *= -1;
            } else
                continue;
        } else
        {
            for (int j = 0; j < rows_; ++j) {
                if (inverse && i != j)
                    elimination_processor(&ratio, *this, i, j, rows_, true);
                else if (j > i)
                    elimination_processor(&ratio, *this, i, j, rows_, false);
            }
        }
    }
}
