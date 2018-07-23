//
// Created by Luca Bindini on 23/07/18.
//

#ifndef MATRIXTEMPLATE_MATRIXDIMENSIONEXCEPTION_H
#define MATRIXTEMPLATE_MATRIXDIMENSIONEXCEPTION_H

#include <stdexcept>
#include <string>

class MatrixDimensionException : public std::length_error {
public:
    explicit MatrixDimensionException(const std::string &s) : std::length_error(s) {}
};

#endif //MATRIXTEMPLATE_MATRIXDIMENSIONEXCEPTION_H
