#include "../inc/s21_matrix_oop.h"

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

int S21Matrix::Size() const noexcept { return rows_ * cols_; }

void S21Matrix::SetRows(const int rows) {
  if (rows <= 0)
    throw std::logic_error("bad rows in setRows()");

  else if (rows != rows_) {
    Resize(rows, cols_);
    rows_ = rows;
  }
}

void S21Matrix::SetCols(const int cols) {
  if (cols <= 0)
    throw std::logic_error("bad cols in setCols()");

  else if (cols != cols_) {
    Resize(rows_, cols);
    cols_ = cols;
  }
}

void S21Matrix::Resize(const int Row, const int Col) {
  S21Matrix tmp {Row, Col};
  int row = Row < rows_ ? Row : rows_;
  int col = Col < cols_ ? Col : cols_;

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      tmp(i, j) = operator()(i, j);

  std::swap(*this, tmp);
}
