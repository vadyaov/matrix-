#include "matrix_oop.h"

void f(S21Matrix&& a) {
  std::cout << "ffff\n";
  S21Matrix b (std::move(a));
}

int main() {
  try {
  S21Matrix a{2, 4};
  S21Matrix b{4, 2};

  std::cout << "a:" << std::endl;
  std::cin >> a;
  std::cout << "b:" << std::endl;
  std::cin >> b;

  std::cout << std::endl;
  std::cout << "a:" << std::endl;
  std::cout << a;
  std::cout << std::endl;
  std::cout << "b:" << std::endl;
  std::cout << b;

  if (a == b)
    std::cout << "a == b" << std::endl;
  else
    std::cout << "a != b" << std::endl;

  a *= b;
  std::cout << "after *=: " << std::endl;
  std::cout << a;

  S21Matrix c = a * -a;
  std::cout << c;

  f(S21Matrix(1, 2));
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
