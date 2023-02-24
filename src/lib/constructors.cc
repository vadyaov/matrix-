#include "../inc/s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_{0}, cols_{0}, matrix_{nullptr} {}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_{rows}, cols_{cols} {
  if (rows_ < 0 || cols_ < 0)
    throw std::length_error("bad size in S21Matrix::S21Matrix(int, int)");
  matrix_ = new double[rows * cols]();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_{other.rows_},
      cols_{other.cols_},
      matrix_{new double[rows_ * cols_]} {
  std::uninitialized_copy(other.matrix_, other.matrix_ + other.size(), matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_{other.matrix_} {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { delete[] matrix_; }
