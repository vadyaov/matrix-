#include "matrix_oop.hpp"

int main() {
  try {
  S21Matrix a{3, 2};
  std::cout << a;
  std::cin >> a;
  std::cout << a;
  S21Matrix b{a};
  std::cout << b;
  std::cout << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
