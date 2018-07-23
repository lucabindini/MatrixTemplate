//
// Created by Luca Bindini on 23/07/18.
//

#ifndef MATRIXTEMPLATE_MATRIX_H
#define MATRIXTEMPLATE_MATRIX_H

#include <iostream>
#include "MatrixDimensionException.h"

template<typename T>
class Matrix {
public:
    Matrix(int nr, int nc) : numRows(nr), numCols(nc) {
        buffer = new T[numRows * numCols];
    }

    Matrix(const Matrix<T> &rh) : numRows(rh.getNumRows()), numCols(rh.getNumCols()) {
        buffer = new T[numRows * numCols];
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < numCols; j++)
                buffer[j + i * numCols] = rh.getElement(i, j);
    }

    ~Matrix() {
        delete[] buffer;
    }

    int getNumRows() const {
        return numRows;
    }

    int getNumCols() const {
        return numCols;
    }

    T getElement(int i, int j) const {
        return buffer[j + i * numCols];
    }

    bool setElement(int i, int j, const T &element) {
        if (i < numRows && i >= 0 && j < numCols && j >= 0) {
            buffer[j + i * numCols] = element;
            return true;
        } else
            return false;
    }

    void getRow(T row[], const int i) const {
        if (i < numRows && i >= 0) {
            for (int j = 0; j < numCols; j++)
                row[j] = getElement(i, j);
        } else
            throw std::out_of_range("index out of range");
    }

    void getColumn(T column[], const int j) const {
        if (j < numCols && j >= 0) {
            for (int i = 0; i < numRows; i++)
                column[i] = getElement(i, j);
        } else
            throw std::out_of_range("index out of range");
    }

    bool operator==(const Matrix<T> &rh) const {
        if (numRows == rh.getNumRows() && numCols == rh.getNumCols()) {
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < numCols; j++)
                    if (buffer[j + i * numCols] != rh.getElement(i, j))
                        return false;
            return true;
        } else
            return false;
    }

    Matrix<T> &operator=(const Matrix<T> &rh) {
        if (this != &rh) {
            if (buffer != nullptr)
                delete[] buffer;
            buffer = new T[rh.getNumRows() * rh.getNumCols()];
            numRows = rh.getNumRows();
            numCols = rh.getNumCols();
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < numCols; j++)
                    buffer[j + i * numCols] = rh.getElement(i, j);
        }
        return *this;
    }

    Matrix<T> operator+(const Matrix<T> &rh) const {
        if (numRows == rh.getNumRows() && numCols == rh.getNumCols()) {
            Matrix<T> sum(numRows, numCols);
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < numCols; j++)
                    sum.setElement(i, j, (*this).getElement(i, j) + rh.getElement(i, j));
            return sum;
        } else
            throw MatrixDimensionException("incompatible dimension for sum");
    }

    Matrix<T> operator-(const Matrix<T> &rh) const {
        if (numRows == rh.getNumRows() && numCols == rh.getNumCols()) {
            Matrix<T> sum(numRows, numCols);
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < numCols; j++)
                    sum.setElement(i, j, (*this).getElement(i, j) - rh.getElement(i, j));
            return sum;
        } else
            throw MatrixDimensionException("incompatible dimension for sub");
    }

    Matrix<T> operator*(const Matrix<T> &rh) const {
        if (numCols == rh.getNumRows()) {
            Matrix<T> prod(numRows, rh.getNumCols());
            T row[numCols];
            T column[rh.getNumRows()];
            int sum;
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < rh.getNumCols(); j++) {
                    getRow(row, i);
                    rh.getColumn(column, j);
                    sum = 0;
                    for (int k = 0; k < numCols; k++)
                        sum += (row[k] * column[k]);
                    prod.setElement(i, j, sum);
                }
            return prod;
        } else
            throw MatrixDimensionException("incompatible dimension for matrix product");
    }

    Matrix<T> transpose() const {
        Matrix<T> transp(numCols, numRows);
        for (int i = 0; i < transp.getNumRows(); i++)
            for (int j = 0; j < transp.getNumCols(); j++)
                transp.setElement(i, j, (*this).getElement(j, i));
        return transp;
    }

    Matrix<T> scalar_product(const int s){
        Matrix<T> prod(numRows, numCols);
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < numCols; j++)
                prod.setElement(i, j, (*this).getElement(i, j) * s);
        return prod;
    }

    void print() const {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++)
                std::cout << buffer[j + i * numCols] << " ";
            std::cout << std::endl;

        }

    }

private:
    int numRows, numCols;
    T *buffer;
};

#endif //MATRIXTEMPLATE_MATRIX_H
