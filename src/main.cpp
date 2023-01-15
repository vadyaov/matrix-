#include "matrix_oop.hpp"

int main() {
  S21Matrix a;
  std::cout << a;
  std::cin >> a;
  std::cout << a;
  S21Matrix b{a};
  b.printMatrix();
  return 0;
}
