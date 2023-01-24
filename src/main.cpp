#include "matrix_oop.hpp"

void f(S21Matrix&& a) {
  std::cout << "ffff\n";
  S21Matrix b (std::move(a));
}

int main() {
  try {
  S21Matrix a{2, 2};
  S21Matrix b{2, 2};

  std::cout << "a:" << std::endl;
  std::cin >> a;

  std::cout << "b:" << std::endl;
  std::cin >> b;

  a += b;
  std::cout << std::endl;
  std::cout << "a:" << std::endl;
  std::cout << a;

  b -= a;
  std::cout << std::endl;
  std::cout << "b:" << std::endl;
  std::cout << b;

  f(S21Matrix(1, 2));
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
