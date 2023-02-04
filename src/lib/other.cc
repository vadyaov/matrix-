#include "../inc/s21_matrix_oop.h"

int S21Matrix::getRows() const noexcept { return rows_; }

int S21Matrix::getCols() const noexcept { return cols_; }

int S21Matrix::size() const noexcept { return rows_ * cols_; }

void S21Matrix::setRows(int rows) {
  if (rows <= 0)
    throw std::logic_error("bad rows in setRows()");

  else if (rows != rows_) {
    resize(rows, cols_);
    rows_ = rows;
  }
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0)
    throw std::logic_error("bad cols in setCols()");

  else if (cols != cols_) {
    resize(rows_, cols);
    cols_ = cols;
  }
}

void S21Matrix::resize(int Row, int Col) {
  S21Matrix tmp {Row, Col};
  int row = Row < rows_ ? Row : rows_;
  int col = Col < cols_ ? Col : cols_;

  for (auto i = 0; i < row; ++i)
    for (auto j = 0; j < col; ++j)
      tmp(i, j) = operator()(i, j);

  std::swap(*this, tmp);
}
