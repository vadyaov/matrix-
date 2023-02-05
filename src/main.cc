#include "inc/s21_matrix_oop.h"

void f(S21Matrix&& a) {
  std::cout << "ffff\n";
  S21Matrix b (std::move(a));
}

int main() {
  try {
  S21Matrix a {2, 2};
  S21Matrix b {2, 2};

  std::cin >> a >> b;
  
  S21Matrix c = a;

  a.SubMatrix(b);
  std::cout << "a = \n" << a << std::endl;

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
