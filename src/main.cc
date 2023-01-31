#include "matrix_oop.h"

void f(S21Matrix&& a) {
  std::cout << "ffff\n";
  S21Matrix b (std::move(a));
}

int main() {
  try {
  S21Matrix a{4, -4};
  std::cout << a.getRows() << " " << a.getCols() << std::endl;

  std::cout << "a:" << std::endl;
  std::cin >> a;

  std::cout << std::endl;
  std::cout << "a:" << std::endl;
  std::cout << a;

  S21Matrix inv = a.InverseMatrix();

  std::cout << "inverse: " << std::endl;
  std::cout << inv;

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
