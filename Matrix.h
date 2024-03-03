//
// Created by Rachel Sanford on 2/18/24.
//

#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <vector>
#include <iostream>
#include <random>

class Matrix {
private:
    int rows_, cols_;
    double** matrix_;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
//    Matrix(Matrix&& other) noexcept ;
    ~Matrix();

    bool EqMatrix(const Matrix& other);
//    bool IsOrthogonal(const Matrix& other);
//    bool IsSymmetric(const Matrix& other);

    void SumMatrix(const Matrix& other);
    void SubMatrix(const Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const Matrix& other);

    Matrix Transpose();
//    Matrix Diagonal(const int num);
//    Matrix Identity();
//    double Trace();

    Matrix CalcComplements();
    double Determinant();
    Matrix InverseMatrix();

    void GaussElimination(bool inverse);
    void SwapRows(int row_1, int row_2);
    void CreateAugmentMatrix(const Matrix& augment_matrix);
    void InverseAugmented(const Matrix& augment_matrix);
    void CopyResult(Matrix& result);

//    std::vector<Matrix> SVD();
//    int Kernel();
//    int Rank();
//    double EigenValue();

    void Print();
    int GetCols() const;
    int GetRows() const;

    std::vector<double>& operator [](int i) {
        return matrix_[i];
    }

    double& operator ()(int i, int j){
        if ((i < 1 || i > rows_) || (j < 1 || j > cols_))
            throw std::invalid_argument("No valid");
        return matrix_[i][j];
    }

    Matrix& operator = (const Matrix& other){
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Invalid size");

        for (int i = 0; i < other.GetRows(); ++i) {
            for (int j = 0; j < other.GetCols(); ++j) {
                matrix_[i][j] = other.matrix_[i][j];
            }
        }
        return *this;
    }

    bool operator == (const Matrix& other) {
        return this->EqMatrix(other);
    }

    Matrix& operator += (const Matrix& other) {
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Rows (cols) didn't match\n");
        this->SumMatrix(other);
        return *this;
    }

    Matrix& operator -= (const Matrix& other) {
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Rows (cols) didn't match\n");
        this->SubMatrix(other);
        return *this;
    }

    Matrix& operator *= (const Matrix& other) {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("Rows (cols) didn't match\n");      // Change exception
        }
        this->MulMatrix(other);
        return *this;
    }

    Matrix& operator *= (const double num) {
        this->MulNumber(num);
        return *this;
    }

};


#endif //C_MATRIX_H
