#include "../inc/s21_matrix_oop.h"

int S21Matrix::getRows() const noexcept { return rows_; }

int S21Matrix::getCols() const noexcept { return cols_; }

int S21Matrix::size() const noexcept { return rows_ * cols_; }

// mb this is not the best idea of implementation mutators but it works
// think how to do it better if possible because
// doesn't enjoy calling destructor int resize()
void S21Matrix::setRows(int rows) {
  if (rows <= 0)
    throw std::logic_error("bad rows in setRows()");
  else if (rows != rows_) {
    rows_ = rows;
    resize();
  }
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0)
    throw std::logic_error("bad cols in setCols()");
  else if (cols != cols_) {
    cols_ = cols;
    resize();
  }
}

void S21Matrix::resize() {
  S21Matrix tmp {rows_, cols_};
  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++)
      tmp(i, j) = operator()(i, j);

  this->~S21Matrix();
  matrix_ = new double[rows_ * cols_];

  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++)
      operator()(i, j) = tmp(i, j);
}
