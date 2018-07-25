#include <iostream>
#include "Matrix.h"
#include <stdexcept>

int main() {
    Matrix<int> m(2, 3);
    m.setElement(0, 0, 1);
    m.setElement(0, 1, 2);
    m.setElement(0, 2, 3);
    m.setElement(1, 0, 4);
    m.setElement(1, 1, 5);
    m.setElement(1, 2, 6);
    Matrix<int> c = m.transpose();
    Matrix<int> d(m);
    try {
        Matrix<int> e = m - c;
    } catch (MatrixDimensionException &e) {
        std::cout << e.what() << std::endl;
    }
    int row[m.getNumCols()];
    try {
        m.getRow(row, 0);
        for (int i = 0; i < m.getNumCols(); i++)
            std::cout << row[i] << " ";
        std::cout << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
    m.print();
    c.print();
    d.print();
    (m * c).print();
    (m * 2).print();
    return 0;
}