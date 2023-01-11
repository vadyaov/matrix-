#include <iostream>
#include "matrix_oop.hpp"

int main() {
  S21Matrix a{2, 3};
  std::cout << a.getRows() << " " << a.getCols() << std::endl;
  return 0;
}
