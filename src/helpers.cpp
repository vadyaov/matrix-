#include "matrix_oop.h"

int S21Matrix::getRows() const noexcept { return rows_; }

int S21Matrix::getCols() const noexcept { return cols_; }

int S21Matrix::size() const noexcept { return rows_ * cols_; }

double& S21Matrix::at(const int i, const int j) const {
  if (i >= rows_ || j >= cols_)
    throw std::out_of_range("Incorrect index in S21Matrix at(i, j)");
  return this->operator()(i, j);
}

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

S21Matrix SimpleMinor(const S21Matrix& other) {
  S21Matrix tmp{2, 2};
  tmp.at(0, 0) = other.at(1, 1);
  tmp.at(0, 1) = -other.at(1, 0);
  tmp.at(1, 0) = -other.at(0, 1);
  tmp.at(1, 1) = other.at(0, 0);
  return tmp;
}

double CalcMinor(const S21Matrix& other, const int i, const int j) {
  S21Matrix smaller = CreateSmaller(other, i, j);
  double minor = Det(smaller);
  return minor;
}

S21Matrix CreateSmaller(const S21Matrix& other, const int i, const int j) {
  S21Matrix smaller {other.getRows() - 1, other.getCols() - 1};
  auto sz = other.getRows();
  for (auto k = 0, n = 0; k < sz; k++) {
    if (i == k) continue;
    for (auto l = 0, m = 0; l < sz; l++) {
      if (l == j) continue;
      smaller.at(n, m) = other.at(k, l);
      m++;
    }
    n++;
  }
  return smaller;
}

double Det(const S21Matrix& other) {
  double det = 0.0;
  if (other.getRows() == 2) {
    det = other.at(0, 0) * other.at(1, 1) - other.at(0, 1) * other.at(1, 0);
    return det;
  }
  for (auto j = 0; j < other.getCols(); j++) {
    S21Matrix smaller = CreateSmaller(other, 0, j);
    det += std::pow(-1.0, j) * Det(smaller) * other.at(0, j);
  }
  return det;
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
