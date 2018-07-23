//
// Created by Luca Bindini on 23/07/18.
//

#include "gtest/gtest.h"

#include "../Matrix.h"


class MatrixSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        m1.setElement(0, 0, 1);
        m1.setElement(0, 1, 2);
        m1.setElement(0, 2, 3);
        m1.setElement(1, 0, 4);
        m1.setElement(1, 1, 5);
        m1.setElement(1, 2, 6);
        m2.setElement(0, 0, 1);
        m2.setElement(0, 1, 2);
        m2.setElement(0, 2, 3);
        m2.setElement(1, 0, 4);
        m2.setElement(1, 1, 5);
        m2.setElement(1, 2, 6);
    }

    Matrix<int> m1 = Matrix<int>(2,3);
    Matrix<int> m2 = Matrix<int>(2,3);
};


TEST_F(MatrixSuite, TestAdd) {
    Matrix<int> m3 = m1 + m2;
    ASSERT_EQ(2, m3.getElement(0, 0));
    ASSERT_EQ(4, m3.getElement(0, 1));
    ASSERT_EQ(6, m3.getElement(0, 2));
    ASSERT_EQ(8, m3.getElement(1, 0));
    ASSERT_EQ(10, m3.getElement(1, 1));
    ASSERT_EQ(12, m3.getElement(1, 2));
}

TEST_F(MatrixSuite, TestSub) {
    Matrix<int> m3 = m1 - m2;
    ASSERT_EQ(0, m3.getElement(0, 0));
    ASSERT_EQ(0, m3.getElement(0, 1));
    ASSERT_EQ(0, m3.getElement(0, 2));
    ASSERT_EQ(0, m3.getElement(1, 0));
    ASSERT_EQ(0, m3.getElement(1, 1));
    ASSERT_EQ(0, m3.getElement(1, 2));
}

TEST_F(MatrixSuite, TestTranspose) {
    Matrix<int> m3 = m1.transpose();
    ASSERT_EQ(1, m3.getElement(0, 0));
    ASSERT_EQ(4, m3.getElement(0, 1));
    ASSERT_EQ(2, m3.getElement(1, 0));
    ASSERT_EQ(5, m3.getElement(1, 1));
    ASSERT_EQ(3, m3.getElement(2, 0));
    ASSERT_EQ(6, m3.getElement(2, 1));
}

