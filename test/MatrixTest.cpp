//
// Created by Luca Bindini on 22/07/18.
//

#include "gtest/gtest.h"

#include "../Matrix.h"

TEST(Matrix, IntConstructor) {
    Matrix<int> m(2,3);
    ASSERT_EQ(2, m.getNumRows());
    ASSERT_EQ(3, m.getNumCols());
}

TEST(Matrix, FloatConstructor) {
    Matrix<float> m(2,3);
    ASSERT_EQ(2, m.getNumRows());
    ASSERT_EQ(3, m.getNumCols());
}




