#include <gtest/gtest.h>
#include "../inc/s21_matrix_oop.h"
#include "test_help.h"

/* --------------------CONSTRUCTORS------------------------ */

TEST(DefaultConstructorTest, Default0) {
  S21Matrix DefaultMatrix;
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  EXPECT_EQ(DefaultMatrix.getCols(), 1);
  EXPECT_EQ(DefaultMatrix(0, 0), 0.0);
}

TEST(DefaultConstructorTest, Default1) {
  S21Matrix DefaultMatrix {};
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  EXPECT_EQ(DefaultMatrix.getCols(), 1);
  EXPECT_EQ(DefaultMatrix(0, 0), 0.0);
}

TEST(DefaultConstructorTest, Default2) {
  S21Matrix DefaultMatrix = {};
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  EXPECT_EQ(DefaultMatrix.getCols(), 1);
  EXPECT_EQ(DefaultMatrix(0, 0), 0.0);
}

TEST(ParamConstructorTest, NormalParams1) {
  S21Matrix m(2, 2);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 2);
  EXPECT_EQ(cols, 2);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, NormalParams2) {
  S21Matrix m(3, 9);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 3);
  EXPECT_EQ(cols, 9);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, NormalParams3) {
  S21Matrix m(1, 1);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 1);
  EXPECT_EQ(cols, 1);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, BigMatrix) {
  S21Matrix m(10, 10);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 10);
  EXPECT_EQ(cols, 10);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, HugeMatrix) {
  S21Matrix m(100, 100);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 100);
  EXPECT_EQ(cols, 100);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, GiantMatrix) {
  try {
  S21Matrix m(1000000, 1000000);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 1000000);
  EXPECT_EQ(cols, 1000000);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
  } catch (std::bad_alloc& e) {
  }
}

TEST(ParamConstructorTest, Corner1) {
  S21Matrix m(0, 3);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 0);
  EXPECT_EQ(cols, 3);
  EXPECT_EQ(sz, 0);
}

TEST(ParamConstructorTest, Corner2) {
  S21Matrix m(3, 0);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 3);
  EXPECT_EQ(cols, 0);
  EXPECT_EQ(sz, 0);
}

TEST(ParamConstructorTest, Corner3) {
  S21Matrix m(0, 0);
  const auto rows = m.getRows();
  const auto cols = m.getCols();
  const auto sz = m.size();

  EXPECT_EQ(rows, 0);
  EXPECT_EQ(cols, 0);
  EXPECT_EQ(sz, 0);
}

TEST(ParamConstructorTest, Exception1) {
  try {
    S21Matrix {-1, 2};
    FAIL() << "Expected std::length_error";
  } catch (std::length_error const& e) {
    EXPECT_EQ(e.what(), std::string("bad size in S21Matrix::S21Matrix(int, int)"));
  }
}

TEST(ParamConstructorTest, Exception2) {
  try {
    S21Matrix {2, -1};
    FAIL() << "Expected std::length_error";
  } catch (std::length_error const& e) {
    EXPECT_EQ(e.what(), std::string("bad size in S21Matrix::S21Matrix(int, int)"));
  }
}

TEST(ParamConstructorTest, Exception3) {
  try {
    S21Matrix {-5, -5};
    FAIL() << "Expected std::length_error";
  } catch (std::length_error const& e) {
    EXPECT_EQ(e.what(), std::string("bad size in S21Matrix::S21Matrix(int, int)"));
  }
}

TEST(CopyConstructor, Test1) {
  S21Matrix a;
  const auto a_rows = a.getRows();
  const auto a_cols = a.getCols();
  const auto a_sz = a.size();
  
  RandMatrix(a);

  S21Matrix b {a};
  const auto b_rows = b.getRows();
  const auto b_cols = b.getCols();
  const auto b_sz = b.size();

  EXPECT_EQ(a_rows, b_rows);
  EXPECT_EQ(a_cols, b_cols);
  EXPECT_EQ(a_sz, b_sz);

  for (auto i = 0; i < a_rows; ++i)
    for (auto j = 0; j < a_cols; ++j)
      EXPECT_EQ(a(i, j), b(i, j));
}

TEST(CopyConstructor, Test2) {
  S21Matrix a {2, 2};
  const auto a_rows = a.getRows();
  const auto a_cols = a.getCols();
  const auto a_sz = a.size();
  
  RandMatrix(a);

  S21Matrix b {a};
  const auto b_rows = b.getRows();
  const auto b_cols = b.getCols();
  const auto b_sz = b.size();

  EXPECT_EQ(a_rows, b_rows);
  EXPECT_EQ(a_cols, b_cols);
  EXPECT_EQ(a_sz, b_sz);

  for (auto i = 0; i < a_rows; ++i)
    for (auto j = 0; j < a_cols; ++j)
      EXPECT_EQ(a(i, j), b(i, j));
}

TEST(CopyConstructor, Test3) {
  S21Matrix a {5, 5};
  const auto a_rows = a.getRows();
  const auto a_cols = a.getCols();
  const auto a_sz = a.size();
  
  RandMatrix(a);

  S21Matrix b {a};
  const auto b_rows = b.getRows();
  const auto b_cols = b.getCols();
  const auto b_sz = b.size();

  EXPECT_EQ(a_rows, b_rows);
  EXPECT_EQ(a_cols, b_cols);
  EXPECT_EQ(a_sz, b_sz);

  for (auto i = 0; i < a_rows; ++i)
    for (auto j = 0; j < a_cols; ++j)
      EXPECT_EQ(a(i, j), b(i, j));
}

/* -------------------------------------------------------- */

/* -----------------------OPERATIONS----------------------- */

/* -------------------------------------------------------- */

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
