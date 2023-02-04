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
