#include "matrix_oop.h"

// imho it would be better to be private function but task doesn't allow
void S21Matrix::resize() {
  S21Matrix tmp {rows_, cols_};
  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++)
      tmp.at(i, j) = this->at(i, j);

  this->~S21Matrix();
  matrix_ = new double[rows_ * cols_];

  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++)
      this->at(i, j) = tmp.at(i, j);
}

double multiply(int i, int j, const S21Matrix& left, const S21Matrix& right) {
  double ij{0.0};
  for (auto k = 0; k < left.getCols(); k++)
    ij += left.at(i, k) * right.at(k, j);
  return ij;
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
