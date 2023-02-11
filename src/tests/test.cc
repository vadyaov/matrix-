#include <gtest/gtest.h>
#include "../inc/s21_matrix_oop.h"
#include "test_help.h"

/* --------------------CONSTRUCTORS------------------------ */

TEST(DefaultConstructorTest, Default0) {
  S21Matrix DefaultMatrix;
  EXPECT_EQ(DefaultMatrix.GetRows(), 1);
  EXPECT_EQ(DefaultMatrix.GetCols(), 1);
  EXPECT_EQ(DefaultMatrix(0, 0), 0.0);
}

TEST(DefaultConstructorTest, Default1) {
  S21Matrix DefaultMatrix {};
  EXPECT_EQ(DefaultMatrix.GetRows(), 1);
  EXPECT_EQ(DefaultMatrix.GetCols(), 1);
  EXPECT_EQ(DefaultMatrix(0, 0), 0.0);
}

TEST(DefaultConstructorTest, Default2) {
  S21Matrix DefaultMatrix = {};
  EXPECT_EQ(DefaultMatrix.GetRows(), 1);
  EXPECT_EQ(DefaultMatrix.GetCols(), 1);
  EXPECT_EQ(DefaultMatrix(0, 0), 0.0);
}

TEST(ParamConstructorTest, NormalParams1) {
  S21Matrix m(2, 2);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

  EXPECT_EQ(rows, 2);
  EXPECT_EQ(cols, 2);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, NormalParams2) {
  S21Matrix m(3, 9);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

  EXPECT_EQ(rows, 3);
  EXPECT_EQ(cols, 9);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, NormalParams3) {
  S21Matrix m(1, 1);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

  EXPECT_EQ(rows, 1);
  EXPECT_EQ(cols, 1);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, BigMatrix) {
  S21Matrix m(10, 10);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

  EXPECT_EQ(rows, 10);
  EXPECT_EQ(cols, 10);
  EXPECT_EQ(sz, rows * cols);
  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j)
      EXPECT_EQ(m(i, j), 0.0);
}

TEST(ParamConstructorTest, HugeMatrix) {
  S21Matrix m(100, 100);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

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
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

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
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

  EXPECT_EQ(rows, 0);
  EXPECT_EQ(cols, 3);
  EXPECT_EQ(sz, 0);
}

TEST(ParamConstructorTest, Corner2) {
  S21Matrix m(3, 0);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

  EXPECT_EQ(rows, 3);
  EXPECT_EQ(cols, 0);
  EXPECT_EQ(sz, 0);
}

TEST(ParamConstructorTest, Corner3) {
  S21Matrix m(0, 0);
  const auto rows = m.GetRows();
  const auto cols = m.GetCols();
  const auto sz = m.Size();

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
  const auto a_rows = a.GetRows();
  const auto a_cols = a.GetCols();
  const auto a_sz = a.Size();
  
  RandMatrix(a);

  S21Matrix b {a};
  const auto b_rows = b.GetRows();
  const auto b_cols = b.GetCols();
  const auto b_sz = b.Size();

  EXPECT_EQ(a_rows, b_rows);
  EXPECT_EQ(a_cols, b_cols);
  EXPECT_EQ(a_sz, b_sz);

  for (auto i = 0; i < a_rows; ++i)
    for (auto j = 0; j < a_cols; ++j)
      EXPECT_EQ(a(i, j), b(i, j));
}

TEST(CopyConstructor, Test2) {
  S21Matrix a {2, 2};
  const auto a_rows = a.GetRows();
  const auto a_cols = a.GetCols();
  const auto a_sz = a.Size();
  
  RandMatrix(a);

  S21Matrix b {a};
  const auto b_rows = b.GetRows();
  const auto b_cols = b.GetCols();
  const auto b_sz = b.Size();

  EXPECT_EQ(a_rows, b_rows);
  EXPECT_EQ(a_cols, b_cols);
  EXPECT_EQ(a_sz, b_sz);

  for (auto i = 0; i < a_rows; ++i)
    for (auto j = 0; j < a_cols; ++j)
      EXPECT_EQ(a(i, j), b(i, j));
}

TEST(CopyConstructor, Test3) {
  S21Matrix a {5, 5};
  const auto a_rows = a.GetRows();
  const auto a_cols = a.GetCols();
  const auto a_sz = a.Size();
  
  RandMatrix(a);

  S21Matrix b {a};
  const auto b_rows = b.GetRows();
  const auto b_cols = b.GetCols();
  const auto b_sz = b.Size();

  EXPECT_EQ(a_rows, b_rows);
  EXPECT_EQ(a_cols, b_cols);
  EXPECT_EQ(a_sz, b_sz);

  for (auto i = 0; i < a_rows; ++i)
    for (auto j = 0; j < a_cols; ++j)
      EXPECT_EQ(a(i, j), b(i, j));
}

TEST(MoveConstructorOperator, Test1) {
  S21Matrix a {3, 3};
  RandMatrix(a);
  S21Matrix b {3, 3};
  RandMatrix(b);

  const auto rows = a.GetRows();
  const auto cols = a.GetCols();

  S21Matrix c {a};
  S21Matrix d {b};

  swap(a, b);

  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j) {
      EXPECT_EQ(b(i,j), c(i, j));
      EXPECT_EQ(a(i,j), d(i, j));
    }
}

TEST(MoveConstructorOperator, Test2) {
  S21Matrix a {5, 5};
  RandMatrix(a);
  S21Matrix b {5, 5};
  RandMatrix(b);

  const auto rows = a.GetRows();
  const auto cols = a.GetCols();

  S21Matrix c {a};
  S21Matrix d {b};

  swap(a, b);

  for (auto i = 0; i < rows; ++i)
    for (auto j = 0; j < cols; ++j) {
      EXPECT_EQ(b(i,j), c(i, j));
      EXPECT_EQ(a(i,j), d(i, j));
    }
}

TEST(MoveConstructorOperator, Test3) {
  S21Matrix a {1, 3};
  S21Matrix b {std::move(a)};
  EXPECT_EQ(a.GetRows(), 0);
  EXPECT_EQ(a.GetCols(), 0);
  EXPECT_EQ(b.GetRows(), 1);
  EXPECT_EQ(b.GetCols(), 3);
  EXPECT_EQ(b.Size(), 3);
}

/* -------------------------------------------------------- */

/* -----------------------OPERATIONS----------------------- */

TEST(EqMatrix, Test1) {
  S21Matrix a {3, 3};
  RandMatrix(a);
  S21Matrix b {a};

  EXPECT_EQ(a.EqMatrix(b), true);
}

TEST(EqMatrix, Test2) {
  S21Matrix a{3, 3};
  RandMatrix(a);

  S21Matrix b {a};
  RandMatrix(b);

  EXPECT_EQ(a.EqMatrix(b), false);
}

TEST(EqMatrix, Test3) {
  S21Matrix a {3, 3};
  RandMatrix(a);

  S21Matrix b {2, 3};
  RandMatrix(b);

  EXPECT_EQ(a.EqMatrix(b), false);
}

TEST(EqMatrix, Test4) {
  S21Matrix a {3, 3};
  RandMatrix(a);
  S21Matrix b {a};

  b(2, 1) = 0;

  EXPECT_EQ(a.EqMatrix(b), false);
}

TEST(SumMatrix, Test1) {
  S21Matrix a {4, 4};
  S21Matrix b {4, 4};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a;

  a.SumMatrix(b);

  for (auto i = 0; i != c.GetRows(); ++i)
    for (auto j = 0; j != c.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) + b(i, j));
}

TEST(SumMatrix, Test2) {
  S21Matrix a {10, 10};
  S21Matrix b {10, 10};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a;

  a.SumMatrix(b);

  for (auto i = 0; i != c.GetRows(); ++i)
    for (auto j = 0; j != c.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) + b(i, j));
}

TEST(SumMatrix, Test3) {
  S21Matrix a {2, 2};
  S21Matrix b {2, 2};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a;

  a.SumMatrix(b);

  for (auto i = 0; i != c.GetRows(); ++i)
    for (auto j = 0; j != c.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) + b(i, j));
}

TEST(SumMatrix, Exception1) {
  S21Matrix a {1, 3};
  S21Matrix b {2, 3};

  RandMatrix(a);
  RandMatrix(b);

  try {
    a.SumMatrix(b);
    FAIL() << "Expected std::runtime_error()";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Different matrix dimensions"));
  }
}

TEST(SumMatrix, Exception2) {
  S21Matrix a {3, 1};
  S21Matrix b {3, 2};

  RandMatrix(a);
  RandMatrix(b);

  try {
    a.SumMatrix(b);
    FAIL() << "Expected std::runtime_error()";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Different matrix dimensions"));
  }
}

TEST(SubMatrix, Test1) {
  S21Matrix a {4, 4};
  S21Matrix b {4, 4};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a;

  a.SubMatrix(b);

  for (auto i = 0; i != c.GetRows(); ++i)
    for (auto j = 0; j != c.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) - b(i, j));
}

TEST(SubMatrix, Test2) {
  S21Matrix a {10, 10};
  S21Matrix b {10, 10};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a;

  a.SubMatrix(b);

  for (auto i = 0; i != c.GetRows(); ++i)
    for (auto j = 0; j != c.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) - b(i, j));
}

TEST(SubMatrix, Test3) {
  S21Matrix a {2, 2};
  S21Matrix b {2, 2};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a;

  a.SubMatrix(b);

  for (auto i = 0; i != c.GetRows(); ++i)
    for (auto j = 0; j != c.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) - b(i, j));
}

TEST(SubMatrix, Exception1) {
  S21Matrix a {1, 3};
  S21Matrix b {2, 3};

  RandMatrix(a);
  RandMatrix(b);

  try {
    a.SubMatrix(b);
    FAIL() << "Expected std::runtime_error()";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Different matrix dimensions"));
  }
}

TEST(SubMatrix, Exception2) {
  S21Matrix a {3, 1};
  S21Matrix b {3, 2};

  RandMatrix(a);
  RandMatrix(b);

  try {
    a.SubMatrix(b);
    FAIL() << "Expected std::runtime_error()";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Different matrix dimensions"));
  }
}

TEST(MulNumber, Test1) {
  S21Matrix a {3, 3};
  const double num = 3.3;
  const auto row = a.GetRows();
  const auto col = a.GetCols();

  RandMatrix(a);
  S21Matrix c{a};

  a.MulNumber(num);

  for (auto i = 0; i < row; ++i)
    for (auto j = 0; j < col; ++j)
      EXPECT_EQ(a(i, j), c(i, j) * num);
}

TEST(MulNumber, Test2) {
  S21Matrix a {30, 30};
  const double num = -1.28;
  const auto row = a.GetRows();
  const auto col = a.GetCols();

  RandMatrix(a);
  S21Matrix c{a};

  a.MulNumber(num);

  for (auto i = 0; i < row; ++i)
    for (auto j = 0; j < col; ++j)
      EXPECT_EQ(a(i, j), c(i, j) * num);
}

TEST(MulNumber, Test3) {
  S21Matrix a {5, 5};
  const double num = 3.5;
  const auto row = a.GetRows();
  const auto col = a.GetCols();

  RandMatrix(a);
  S21Matrix c{a};

  a.MulNumber(num);

  for (auto i = 0; i < row; ++i)
    for (auto j = 0; j < col; ++j)
      EXPECT_EQ(a(i, j), c(i, j) * num);
}

TEST(MulMatrix, Test1) {
  S21Matrix a{2, 3};
  S21Matrix b{3, 3};
  a(0, 0) = 1.25;
  a(0, 1) = 1.35;
  a(0, 2) = -5.05;
  a(1, 0) = 9;
  a(1, 1) = 7;
  a(1, 2) = 2;

  b(0, 0) = 1;
  b(0, 1) = 2;
  b(0, 2) = 3;
  b(1, 0) = 3;
  b(1, 1) = 2;
  b(1, 2) = 1;
  b(2, 0) = 10;
  b(2, 1) = 11.5;
  b(2, 2) = 12;

  a.MulMatrix(b);
  S21Matrix res {2, 3};

  res(0, 0) = -45.2;
  res(0, 1) = -52.875;
  res(0, 2) = -55.5;
  res(1, 0) = 50;
  res(1, 1) = 55;
  res(1, 2) = 58;

  for (auto i = 0; i < a.GetRows(); ++i)
    for (auto j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(std::fabs(a(i,j) - res(i,j)) < EPS, true);
}

TEST(MulMatrix, Test2) {
  S21Matrix a{3, 2};
  S21Matrix b{2, 3};

  a(0, 0) = 11.1;
  a(0, 1) = 1.11;
  a(1, 0) = -11.1;
  a(1, 1) = -1.11;
  a(2, 0) = 0.023;
  a(2, 1) = -0.023;

  b(0, 0) = 1;
  b(0, 1) = 2;
  b(0, 2) = 3;
  b(1, 0) = 3;
  b(1, 1) = 2;
  b(1, 2) = 1;

  a.MulMatrix(b);
  S21Matrix res {3, 3};

  res(0, 0) = 14.43;
  res(0, 1) = 24.42;
  res(0, 2) = 34.41;
  res(1, 0) = -14.43;
  res(1, 1) = -24.42;
  res(1, 2) = -34.41;
  res(2, 0) = -0.046;
  res(2, 1) = 0;
  res(2, 2) = 0.046;

  for (auto i = 0; i < a.GetRows(); ++i)
    for (auto j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(std::fabs(a(i,j) - res(i,j)) < EPS, true);
}

TEST(MulNumber, Exception1) {
  S21Matrix a {2, 3};
  S21Matrix b {2, 3};

  try {
    a.MulMatrix(b);
    FAIL() << "Expect std::runtime_error";
  } catch (const std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Incorrect matrix dimensions for multiplication"));
  }
}

TEST(MulNumber, Exception2) {
  S21Matrix a {3, 2};
  S21Matrix b {3, 2};

  try {
    a.MulMatrix(b);
    FAIL() << "Expect std::runtime_error";
  } catch (const std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Incorrect matrix dimensions for multiplication"));
  }
}

TEST(Transpose, Test1) {
  S21Matrix a {2, 3};
  a(0, 0) = 1.25;
  a(0, 1) = 1.35;
  a(0, 2) = -5.05;
  a(1, 0) = 9;
  a(1, 1) = 7;
  a(1, 2) = 2;

  S21Matrix transp = a.Transpose();

  S21Matrix exp {3, 2};
  exp(0, 0) = 1.25;
  exp(0, 1) = 9;
  exp(1, 0) = 1.35;
  exp(1, 1) = 7;
  exp(2, 0) = -5.05;
  exp(2, 1) = 2;

  EXPECT_EQ(transp.GetRows(), exp.GetRows());
  EXPECT_EQ(transp.GetCols(), exp.GetCols());

  for (auto i = 0; i < exp.GetRows(); ++i)
    for (auto j = 0; j < exp.GetCols(); ++j)
      EXPECT_EQ(transp(i, j), exp(i, j));
}

TEST(Transpose, Test2) {
  S21Matrix a {3, 2};
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  a(2, 0) = 5;
  a(2, 1) = 6;

  S21Matrix transp = a.Transpose();

  S21Matrix exp {2, 3};
  exp(0, 0) = 1;
  exp(0, 1) = 3;
  exp(0, 2) = 5;
  exp(1, 0) = 2;
  exp(1, 1) = 4;
  exp(1, 2) = 6;

  EXPECT_EQ(transp.GetRows(), exp.GetRows());
  EXPECT_EQ(transp.GetCols(), exp.GetCols());

  for (auto i = 0; i < exp.GetRows(); ++i)
    for (auto j = 0; j < exp.GetCols(); ++j)
      EXPECT_EQ(transp(i, j), exp(i, j));
}

TEST(CalcComplements, Test1) {
  S21Matrix a {3, 3};
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;

  S21Matrix res = a.CalcComplements();

  S21Matrix exp {3, 3};
  exp(0, 0) = 0;
  exp(0, 1) = 10;
  exp(0, 2) = -20;
  exp(1, 0) = 4;
  exp(1, 1) = -14;
  exp(1, 2) = 8;
  exp(2, 0) = -8;
  exp(2, 1) = -2;
  exp(2, 2) = 4;

  EXPECT_EQ(res.GetRows(), exp.GetRows());
  EXPECT_EQ(res.GetCols(), exp.GetCols());

  for (auto i = 0; i < exp.GetRows(); ++i)
    for (auto j = 0; j < exp.GetCols(); ++j)
      EXPECT_EQ(res(i, j), exp(i, j));
}

TEST(CalcComplements, Test2) {
  S21Matrix a {3, 3};
  a(0, 0) = 1.34;
  a(0, 1) = 5.23;
  a(0, 2) = 0.33;
  a(1, 0) = -3.67;
  a(1, 1) = 5.44;
  a(1, 2) = 11;
  a(2, 0) = 6.15;
  a(2, 1) = 4.3;
  a(2, 2) = 8;

  S21Matrix res = a.CalcComplements();

  S21Matrix exp {3, 3};
  exp(0, 0) = -3.78;
  exp(0, 1) = 97.01;
  exp(0, 2) = -49.237;
  exp(1, 0) = -40.421;
  exp(1, 1) = 8.6905;
  exp(1, 2) = 26.4025;
  exp(2, 0) = 55.7348;
  exp(2, 1) = -15.9511;
  exp(2, 2) = 26.4837;

  EXPECT_EQ(res.GetRows(), exp.GetRows());
  EXPECT_EQ(res.GetCols(), exp.GetCols());

  for (auto i = 0; i < exp.GetRows(); ++i)
    for (auto j = 0; j < exp.GetCols(); ++j)
      EXPECT_EQ(std::fabs(res(i, j) - exp(i, j)) < EPS, true);
}

TEST(CalcComplements, Test3) {
  S21Matrix a {2, 2};
  a(0, 0) = 1.25;
  a(0, 1) = 2.1;
  a(1, 0) = 3.76;
  a(1, 1) = 4.2;

  S21Matrix res = a.CalcComplements();

  S21Matrix exp {2, 2};
  exp(0, 0) = 4.2;
  exp(0, 1) = -3.76;
  exp(1, 0) = -2.1;
  exp(1, 1) = 1.25;

  EXPECT_EQ(res.GetRows(), exp.GetRows());
  EXPECT_EQ(res.GetCols(), exp.GetCols());

  for (auto i = 0; i < exp.GetRows(); ++i)
    for (auto j = 0; j < exp.GetCols(); ++j)
      EXPECT_EQ(std::fabs(res(i, j) - exp(i, j)) < EPS, true);
}

TEST(CalcComplements, Exception1) {
  S21Matrix a{1, 3};

  try {
    S21Matrix res = a.CalcComplements();
    FAIL() << "Expected std::runtime_error";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("not square matrix in S21Matrix::CalcComplements()"));
  }
}

TEST(CalcComplements, Exception2) {
  S21Matrix a{1, 1};

  try {
    S21Matrix res = a.CalcComplements();
    FAIL() << "Expected std::runtime_error";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("no complements for 1x1 matrix in S21Matrix::CalcComplements()"));
  }
}

TEST(Determinant, Test1) {
  S21Matrix a {3, 3};
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;
  EXPECT_EQ(a.Determinant(), -40.0);
}

TEST(Determinant, Test2) {
  S21Matrix a {3, 3};
  a(0, 0) = 1.3;
  a(0, 1) = 5.2;
  a(0, 2) = 0.3;
  a(1, 0) = -3;
  a(1, 1) = 5.4;
  a(1, 2) = 11;
  a(2, 0) = 6.1;
  a(2, 1) = 4;
  a(2, 2) = 8;
  EXPECT_EQ(std::fabs(a.Determinant() - 459.198) < EPS, true);
}

TEST(Determinant, Test3) {
  S21Matrix a {2, 2};
  a(0, 0) = 1;
  a(0, 1) = 5;
  a(1, 0) = -3;
  a(1, 1) = 5;
  EXPECT_EQ(std::fabs(a.Determinant() - 20) < EPS, true);
}

TEST(Determinant, Test4) {
  S21Matrix a {1, 1};
  a(0, 0) = 1;
  EXPECT_EQ(std::fabs(a.Determinant() - 1) < EPS, true);
}

TEST(Determinant, Exception1) {
  S21Matrix a {3, 2};
  
  try {
    a.Determinant();
    FAIL() << "Expected std::runtime_error";
  } catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("rows_ != cols_ in S21Matrix::Determinant()"));
  }
}

TEST(InverseMatrix, Test1) {
  S21Matrix a {3, 3};
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;

  S21Matrix res = a.InverseMatrix();
  S21Matrix ident = CreateIdentity(3, 3);

  res.MulMatrix(a);

  EXPECT_EQ(res.EqMatrix(ident), true);
}

TEST(InverseMatrix, Test2) {
  S21Matrix a {3, 3};
  a(0, 0) = 1;
  a(0, 1) = 5;
  a(0, 2) = 0;
  a(1, 0) = -3;
  a(1, 1) = 5;
  a(1, 2) = 11;
  a(2, 0) = 6;
  a(2, 1) = 4;
  a(2, 2) = 8;

  S21Matrix res = a.InverseMatrix();
  S21Matrix ident = CreateIdentity(3, 3);

  res.MulMatrix(a);

  EXPECT_EQ(res.EqMatrix(ident), true);
}

TEST(InverseMatrix, Test3) {
  S21Matrix a {2, 2};
  a(0, 0) = 1;
  a(0, 1) = -1;
  a(1, 0) = 2;
  a(1, 1) = 4;

  S21Matrix res = a.InverseMatrix();
  S21Matrix ident = CreateIdentity(2, 2);

  res.MulMatrix(a);

  EXPECT_EQ(res.EqMatrix(ident), true);
}

TEST(InverseMatrix, Test4) {
  S21Matrix a {3, 3};
  a(0, 0) = 1;
  a(0, 1) = -2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = -1;
  a(2, 0) = 5;
  a(2, 1) = 0;
  a(2, 2) = 0;

  S21Matrix res = a.InverseMatrix();
  S21Matrix ident = CreateIdentity(3, 3);

  res.MulMatrix(a);

  EXPECT_EQ(res.EqMatrix(ident), true);
}

TEST(InverseMatrix, Test5) {
  S21Matrix a {1, 1};
  a(0, 0) = 2;

  S21Matrix res = a.InverseMatrix();

  EXPECT_EQ(res(0,0), 0.5);
}

TEST(InverseMatrix, Exception) {
  S21Matrix a {2, 2};
  a(0, 0) = 2;
  a(0, 1) = 3;
  a(1, 0) = -5;
  a(1, 1) = -7.5;

  try {
    S21Matrix res = a.InverseMatrix();
    FAIL() << "Expected std::runtime_error";
  } catch (const std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Determinant() is 0 in S21Matrix::InverseMatrix()"));
  }
}

/* -------------------------------------------------------- */

/* -----------------------OPERATORS------------------------ */

TEST(OperatorPlus, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a + b;

  EXPECT_EQ(c.GetRows(), 3);
  EXPECT_EQ(c.GetCols(), 3);

  for (auto i = 0; i < c.GetRows(); ++i)
    for (auto j = 0; j < c.GetCols(); ++j)
      EXPECT_EQ(c(i, j), a(i, j) + b(i, j));
}

TEST(OperatorMinus, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  RandMatrix(a);
  RandMatrix(b);

  S21Matrix c = a - b;

  EXPECT_EQ(c.GetRows(), 3);
  EXPECT_EQ(c.GetCols(), 3);

  for (auto i = 0; i < c.GetRows(); ++i)
    for (auto j = 0; j < c.GetCols(); ++j)
      EXPECT_EQ(c(i, j), a(i, j) - b(i, j));
}

TEST(OperatorMulNum, Test) {
  S21Matrix a {3, 3};

  RandMatrix(a);
  S21Matrix acpy {a};

  a *= 2.0;
  EXPECT_EQ(a.GetRows(), 3);
  EXPECT_EQ(a.GetCols(), 3);

  for (auto i = 0; i < a.GetRows(); ++i)
    for (auto j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(a(i, j), acpy(i, j) * 2.0);
}

TEST(OperatorMulMat, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  a(0, 0) = 1.1;
  a(0, 1) = 1.2;
  a(0, 2) = 1.3;

  a(1, 0) = 1.4;
  a(1, 1) = 1.5;
  a(1, 2) = 1.6;

  a(2, 0) = 1.7;
  a(2, 1) = 1.8;
  a(2, 2) = 1.9;


  b(0, 0) = 1.1;
  b(0, 1) = 1.2;
  b(0, 2) = 1.3;

  b(1, 0) = 1.4;
  b(1, 1) = 1.5;
  b(1, 2) = 1.6;

  b(2, 0) = 1.7;
  b(2, 1) = 1.8;
  b(2, 2) = 1.9;

  S21Matrix c = a * b;

  EXPECT_EQ(c.Size(), 9);

  EXPECT_EQ(std::fabs(c(0,0) - 5.1) < EPS, true);
  EXPECT_EQ(std::fabs(c(0,1) - 5.46) < EPS, true);
  EXPECT_EQ(std::fabs(c(0,2) - 5.82) < EPS, true);
  EXPECT_EQ(std::fabs(c(1,0) - 6.36) < EPS, true);
  EXPECT_EQ(std::fabs(c(1,1) - 6.81) < EPS, true);
  EXPECT_EQ(std::fabs(c(1,2) - 7.26) < EPS, true);
  EXPECT_EQ(std::fabs(c(2,0) - 7.62) < EPS, true);
  EXPECT_EQ(std::fabs(c(2,1) - 8.16) < EPS, true);
  EXPECT_EQ(std::fabs(c(2,2) - 8.7) < EPS, true);;
}

TEST(OperatorMulNum1, Test) {
  S21Matrix a {3, 3};

  a(0, 0) = 1.1;
  a(0, 1) = 1.2;
  a(0, 2) = 1.3;

  a(1, 0) = 1.4;
  a(1, 1) = 1.5;
  a(1, 2) = 1.6;

  a(2, 0) = 1.7;
  a(2, 1) = 1.8;
  a(2, 2) = 1.9;

  S21Matrix c = a * 4.5;

  EXPECT_EQ(c.Size(), 9);

  EXPECT_EQ(std::fabs(c(0,0) - 4.95) < EPS, true);
  EXPECT_EQ(std::fabs(c(0,1) - 5.4) < EPS, true);
  EXPECT_EQ(std::fabs(c(0,2) - 5.85) < EPS, true);
  EXPECT_EQ(std::fabs(c(1,0) - 6.3) < EPS, true);
  EXPECT_EQ(std::fabs(c(1,1) - 6.75) < EPS, true);
  EXPECT_EQ(std::fabs(c(1,2) - 7.2) < EPS, true);
  EXPECT_EQ(std::fabs(c(2,0) - 7.65) < EPS, true);
  EXPECT_EQ(std::fabs(c(2,1) - 8.1) < EPS, true);
  EXPECT_EQ(std::fabs(c(2,2) - 8.55) < EPS, true);
}

TEST(OperatorEq, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  a(0, 0) = 1.1;
  a(0, 1) = 1.2;
  a(0, 2) = 1.3;

  a(1, 0) = 1.4;
  a(1, 1) = 1.5;
  a(1, 2) = 1.6;

  a(2, 0) = 1.7;
  a(2, 1) = 1.8;
  a(2, 2) = 1.9;

  b(0, 0) = 1.1;
  b(0, 1) = 1.2;
  b(0, 2) = 1.3;

  b(1, 0) = 1.4;
  b(1, 1) = 1.5;
  b(1, 2) = 1.6;

  b(2, 0) = 1.7;
  b(2, 1) = 1.8;
  b(2, 2) = 1.9;

  EXPECT_EQ(a == b, true);
}

TEST(OperatorEq, Test1) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  a(0, 0) = 1.1;
  a(0, 1) = 1.2;
  a(0, 2) = 1.3;

  a(1, 0) = 1.4;
  a(1, 1) = 1.5;
  a(1, 2) = 1.6;

  a(2, 0) = 1.7;
  a(2, 1) = 1.8;
  a(2, 2) = 1.9;

  b(0, 0) = 1.1;
  b(0, 1) = 1.21;
  b(0, 2) = 1.3;

  b(1, 0) = 1.4;
  b(1, 1) = 1.5;
  b(1, 2) = 1.6;

  b(2, 0) = 1.7;
  b(2, 1) = 1.8;
  b(2, 2) = 1.9;

  EXPECT_EQ(a == b, false);
}

TEST(OerCopy, Test1) {
  S21Matrix a {2, 2};
  RandMatrix(a);

  S21Matrix b {3, 3};
  RandMatrix(b);

  a = b;

  EXPECT_EQ(a.EqMatrix(b), true);
}

TEST(OerCopy, Test2) {
  S21Matrix a {2, 2};
  RandMatrix(a);

  S21Matrix b {3, 3};
  RandMatrix(b);

  b = a;

  EXPECT_EQ(a.EqMatrix(b), true);
}

TEST(OperPlusEq, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  RandMatrix(a);
  RandMatrix(b);
  S21Matrix c = a;

  a += b;
  EXPECT_EQ(a.Size(), 9);

  for (int i = 0; i < a.GetRows(); ++i)
    for (int j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(a(i, j), b(i, j) + c(i, j));
}

TEST(OperMinusEq, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  RandMatrix(a);
  RandMatrix(b);
  S21Matrix c = a;

  a -= b;
  EXPECT_EQ(a.Size(), 9);

  for (int i = 0; i < a.GetRows(); ++i)
    for (int j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j) - b(i, j));
}

TEST(OperMulEqMat, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  RandMatrix(a);
  RandMatrix(b);
  S21Matrix c = a;
  c.MulMatrix(b);

  a *= b;
  EXPECT_EQ(a.Size(), 9);

  for (int i = 0; i < a.GetRows(); ++i)
    for (int j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j));
}

TEST(OperMulEqNum, Test) {
  S21Matrix a {3, 3};
  S21Matrix b {3, 3};

  RandMatrix(a);
  RandMatrix(b);
  S21Matrix c = a * 2.5;

  a *= 2.5;
  EXPECT_EQ(a.Size(), 9);

  for (int i = 0; i < a.GetRows(); ++i)
    for (int j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(a(i, j), c(i, j));
}

TEST(UnaryMinus, Test) {
  S21Matrix a {3, 3};
  
  RandMatrix(a);

  S21Matrix b = -a;

  for (int i = 0; i < a.GetRows(); ++i)
    for (int j = 0; j < a.GetCols(); ++j)
      EXPECT_EQ(a(i, j), -b(i, j));
}

/* -------------------------------------------------------- */

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
