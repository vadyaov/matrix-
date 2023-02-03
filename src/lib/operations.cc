#include "../inc/s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool sz = cols_ == other.cols_ && rows_ == other.rows_;
  if (sz) {
    double *m1 = matrix_;
    double *m2 = other.matrix_;
    double *end = matrix_ + size();

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
  double *end = p + size();
  while (p != end)
    *p++ += *q++;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  SumMatrix(-other);
}

void S21Matrix::MulNumber(const double n) noexcept {
  for (auto i = 0; i < size(); ++i)
    matrix_[i] *= n;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::runtime_error("Incorrect matrix dimensions for multiplication");

  S21Matrix res{rows_, other.cols_};
  for (auto i = 0; i < res.rows_; ++i)
    for (auto j = 0; j < res.cols_; ++j)
      res(i, j) = multiply(i, j, *this, other);

  *this = res;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix res{cols_, rows_};
  for (auto i = 0; i < res.rows_; ++i)
    for (auto j = 0; j < res.cols_; ++j)
      res(i, j) = operator()(j, i);
  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  // mb combine these 2 exceptions
  if (rows_ != cols_)
    throw std::runtime_error("not square matrix in S21Matrix::CalcComplements()");
  if (rows_ == 1)
    throw std::runtime_error("no complements for 1x1 matrix in S21Matrix::CalcComplements()");

  S21Matrix res{rows_, cols_};
  if (rows_ == 2)
    res = SimpleMinor(*this);
  else {
    for (auto i = 0; i < rows_; ++i)
      for (auto j = 0; j < cols_; ++j)
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
    throw std::runtime_error("this->Determinant() is 0 in S21Matrix::InverseMatrix()");

  S21Matrix res;
  if (rows_ == 1) {
    res(0, 0) = 1.0 / det;
  } else {
    S21Matrix transpose = Transpose();
    S21Matrix calc_comp = transpose.CalcComplements();
    calc_comp.MulNumber(1.0 / det);
    res = calc_comp;
  }
  return res;
}

