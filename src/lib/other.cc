#include "../inc/s21_matrix_oop.h"

static void Resize(S21Matrix& m, const int r, const int c) {
  S21Matrix tmp{r, c};
  const int row = r < m.get_rows() ? r : m.get_rows();
  const int col = c < m.get_cols() ? c : m.get_cols();

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) tmp(i, j) = m(i, j);

  std::swap(m, tmp);
}

int S21Matrix::get_rows() const noexcept { return rows_; }

int S21Matrix::get_cols() const noexcept { return cols_; }

int S21Matrix::size() const noexcept { return rows_ * cols_; }

void S21Matrix::set_rows(const int rows) {
  if (rows <= 0) throw std::logic_error("bad rows in setRows()");

  if (rows != rows_) {
    Resize(*this, rows, cols_);
    rows_ = rows;
  }
}

void S21Matrix::set_cols(const int cols) {
  if (cols <= 0) throw std::logic_error("bad cols in setCols()");

  if (cols != cols_) {
    Resize(*this, rows_, cols);
    cols_ = cols;
  }
}
