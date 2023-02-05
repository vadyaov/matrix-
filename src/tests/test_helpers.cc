#include "test_help.h"

void RandMatrix(S21Matrix& m) {
  for (auto i = 0; i < m.getRows(); ++i)
    for (auto j = 0; j < m.getCols(); ++j) {
      m(i, j) = GetRandomValue();
    }
}

double GetRandomValue() {
  double low = 0;
  double up = 100;
  static std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(low,up);
  return distribution(generator);
}

void swap(S21Matrix& a, S21Matrix& b) {
  S21Matrix tmp{std::move(a)};
  a = std::move(b);
  b = std::move(tmp);
}

S21Matrix CreateIdentity(const int row, const int col) {
  S21Matrix ident {row, col};
  for (auto i = 0; i < row; ++i)
    for (auto j = 0; j < row; ++j)
      if (i == j)
        ident(i, j) = 1.0;
  return ident;
}
