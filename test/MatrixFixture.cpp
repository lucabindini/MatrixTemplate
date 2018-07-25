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

    Matrix<int> m1 = Matrix<int>(2, 3);
    Matrix<int> m2 = Matrix<int>(2, 3);
};

TEST_F(MatrixSuite, TestAssignment) {
    Matrix<int> m3 = m1;
    ASSERT_EQ(1, m3.getElement(0, 0));
    ASSERT_EQ(2, m3.getElement(0, 1));
    ASSERT_EQ(3, m3.getElement(0, 2));
    ASSERT_EQ(4, m3.getElement(1, 0));
    ASSERT_EQ(5, m3.getElement(1, 1));
    ASSERT_EQ(6, m3.getElement(1, 2));
}

TEST_F(MatrixSuite, TestCopyConstructor) {
    Matrix<int> m3(m1);
    ASSERT_EQ(1, m3.getElement(0, 0));
    ASSERT_EQ(2, m3.getElement(0, 1));
    ASSERT_EQ(3, m3.getElement(0, 2));
    ASSERT_EQ(4, m3.getElement(1, 0));
    ASSERT_EQ(5, m3.getElement(1, 1));
    ASSERT_EQ(6, m3.getElement(1, 2));
}

TEST_F(MatrixSuite, TestGetRow) {
    int row[m1.getNumCols()];
    m1.getRow(row, 0);
    ASSERT_EQ(1, row[0]);
    ASSERT_EQ(2, row[1]);
    ASSERT_EQ(3, row[2]);
}

TEST_F(MatrixSuite, TestGetColumn) {
    int column[m1.getNumRows()];
    m1.getColumn(column, 0);
    ASSERT_EQ(1, column[0]);
    ASSERT_EQ(4, column[1]);
}

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

TEST_F(MatrixSuite, TestMatrixProduct) {
    Matrix<int> m3 = m1 * m1.transpose();
    ASSERT_EQ(14, m3.getElement(0, 0));
    ASSERT_EQ(32, m3.getElement(0, 1));
    ASSERT_EQ(32, m3.getElement(1, 0));
    ASSERT_EQ(77, m3.getElement(1, 1));
}

TEST_F(MatrixSuite, TestScalarProduct) {
    Matrix<int> m3 = m1 * 2;
    ASSERT_EQ(2, m3.getElement(0, 0));
    ASSERT_EQ(4, m3.getElement(0, 1));
    ASSERT_EQ(6, m3.getElement(0, 2));
    ASSERT_EQ(8, m3.getElement(1, 0));
    ASSERT_EQ(10, m3.getElement(1, 1));
    ASSERT_EQ(12, m3.getElement(1, 2));
}

TEST_F(MatrixSuite, TestExceptionSum) {
    Matrix<int> m3(2, 2);
    EXPECT_THROW((m1 + m3), MatrixDimensionException);
}

TEST_F(MatrixSuite, TestExceptionSub) {
    Matrix<int> m3(2, 2);
    EXPECT_THROW((m1 - m3), MatrixDimensionException);
}

TEST_F(MatrixSuite, TestExceptionMatrixProduct) {
    Matrix<int> m3(2, 2);
    EXPECT_THROW((m1 * m3), MatrixDimensionException);
}
