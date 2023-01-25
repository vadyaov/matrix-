#include "matrix_oop.h"

void f(S21Matrix&& a) {
  std::cout << "ffff\n";
  S21Matrix b (std::move(a));
}

int main() {
  try {
  S21Matrix a{3, 3};
  S21Matrix b{2, 2};

  std::cout << "a:" << std::endl;
  std::cin >> a;

  a.setRows(2);
  std::cout << "after setrows(2)\n" << a;
  a.setCols(1);
  std::cout << "after setCols(2)\n" << a;
  /* std::cout << "b:" << std::endl; */
  /* std::cin >> b; */

  /* a += b; */
  /* std::cout << std::endl; */
  /* std::cout << "a:" << std::endl; */
  /* std::cout << a; */

  /* b -= a; */
  /* std::cout << std::endl; */
  /* std::cout << "b:" << std::endl; */
  /* std::cout << b; */

  f(S21Matrix(1, 2));
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
