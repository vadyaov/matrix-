#include "../inc/s21_matrix_oop.h"

static double Multiply(const S21Matrix& left, const S21Matrix& right, const int i, const int j) noexcept {
  double ij{0.0};
  for (int k = 0; k < left.GetCols(); ++k)
    ij += left(i, k) * right(k, j);

  return ij;
}

static inline S21Matrix SimpleMinor(const S21Matrix& other) noexcept {
  S21Matrix tmp{2, 2};
  tmp(0, 0) = other(1, 1);
  tmp(0, 1) = -other(1, 0);
  tmp(1, 0) = -other(0, 1);
  tmp(1, 1) = other(0, 0);

  return tmp;
}

static S21Matrix CreateSmaller(const S21Matrix& other, const int i, const int j) noexcept {
  S21Matrix smaller {other.GetRows() - 1, other.GetCols() - 1};
  const int sz = other.GetRows();
  for (int k = 0, n = 0; k < sz; ++k) {
    if (i == k) continue;
    for (int l = 0, m = 0; l < sz; ++l) {
      if (l == j) continue;
      smaller(n, m) = other(k, l);
      ++m;
    }
    ++n;
  }

  return smaller;
}

static double Det(const S21Matrix& other) noexcept {
  double det = 0.0;
  if (other.GetRows() == 2) {
    det = other(0, 0) * other(1, 1) - other(0, 1) * other(1, 0);
  } else {
    for (int j = 0; j < other.GetCols(); ++j) {
      S21Matrix smaller = CreateSmaller(other, 0, j);
      det += std::pow(-1.0, j) * Det(smaller) * other(0, j);
    }
  }

  return det;
}

static double CalcMinor(const S21Matrix& other, const int i, const int j) noexcept {
  S21Matrix smaller = CreateSmaller(other, i, j);
  double minor = Det(smaller);
  return minor;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool sz = cols_ == other.cols_ && rows_ == other.rows_;

  if (true == sz) {
    double *m1 = matrix_;
    double *m2 = other.matrix_;
    double *end = matrix_ + Size();

    while (m1 != end && sz)
      sz = std::fabs(*m1++ - *m2++) < EPS;
  }

  return sz;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::runtime_error("Different matrix dimensions");

  double *p = matrix_;
  double *q = other.matrix_;
  double *end = p + Size();
  while (p != end)
    *p++ += *q++;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  SumMatrix(-other);
}

void S21Matrix::MulNumber(const double n) noexcept {
  for (int i = 0; i < Size(); ++i)
    matrix_[i] *= n;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::runtime_error("Incorrect matrix dimensions for multiplication");

  S21Matrix res{rows_, other.cols_};
  for (int i = 0; i < res.rows_; ++i)
    for (int j = 0; j < res.cols_; ++j)
      res(i, j) = Multiply(*this, other, i, j);

  *this = std::move(res);
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix res{cols_, rows_};
  for (int i = 0; i < res.rows_; ++i)
    for (int j = 0; j < res.cols_; ++j)
      res(i, j) = operator()(j, i);

  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_)
    throw std::runtime_error("not square matrix in S21Matrix::CalcComplements()");
  if (rows_ == 1)
    throw std::runtime_error("no complements for 1x1 matrix in S21Matrix::CalcComplements()");

  S21Matrix res{rows_, cols_};
  if (rows_ == 2)
    res = SimpleMinor(*this);
  else {
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j)
        res(i, j) = CalcMinor(*this, i, j) * std::pow(-1.0, i + j);
  }

  return res;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_)
    throw std::runtime_error("rows_ != cols_ in S21Matrix::Determinant()");

  double det = 0.0;
  if (rows_ == 1)
    det = operator()(0, 0);
  else
    det = Det(*this);

  return det;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double det = Determinant();
  if (std::fabs(det) < EPS)
    throw std::runtime_error("Determinant() is 0 in S21Matrix::InverseMatrix()");

  S21Matrix res;
  if (rows_ == 1) {
    res(0, 0) = 1.0 / det;
  } else {
    S21Matrix calc_comp = Transpose().CalcComplements();
    calc_comp.MulNumber(1.0 / det);
    res = std::move(calc_comp);
  }

  return res;
}
