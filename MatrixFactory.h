//
// Created by Luca Bindini on 25/07/18.
//

#ifndef MATRIXTEMPLATE_MATRIXFACTORY_H
#define MATRIXTEMPLATE_MATRIXFACTORY_H

#include <iostream>
#include "Matrix.h"

template<typename T>
class MatrixFactory {
private:
    MatrixFactory() = default;

public:
    static Matrix<T> *create(int nr = 2, int nc = 2) {
        return new Matrix<T>(nr, nc);
    }

};

#endif //MATRIXTEMPLATE_MATRIXFACTORY_H
