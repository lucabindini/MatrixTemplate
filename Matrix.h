//
// Created by Luca Bindini on 23/07/18.
//

#ifndef MATRIXTEMPLATE_MATRIX_H
#define MATRIXTEMPLATE_MATRIX_H

#include <iostream>

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

    bool operator==(const Matrix<T> &rh) {
        if (numRows == rh.getNumRows() && numCols == rh.getNumCols()) {
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < numCols; j++)
                    if (buffer[j + i * numCols] != rh.getElement(i, j))
                        return false;
            return true;
        } else
            return false;
    }

    Matrix &operator=(const Matrix<T> &rh) {
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

    void print() {
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
