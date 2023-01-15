#include "matrix_oop.hpp"

S21Matrix::S21Matrix(int rows, int cols) {
  /* don't forget to throw exception for bad params */
  if (rows < 0 || cols < 0)
    throw std::bad_alloc();
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows * cols]();
}

std::ostream& operator<<(std::ostream& os, const S21Matrix& m) {
  for (int i = 0; i < m.getRows(); i++) {
    for (int j = 0; j < m.getCols(); j++) {
      os << m.at(i, j) << " ";
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, const S21Matrix& m) {
  for (int i = 0; i < m.getRows(); i++)
    for (int j = 0; j < m.getCols(); j++)
      is >> m.at(i, j);
  return is;
}
