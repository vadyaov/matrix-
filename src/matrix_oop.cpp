#include <iostream>
#include "matrix_oop.hpp"

int main() {
  S21Matrix a{2, 3};
  a.printMatrix();
  a.setMatrix();
  a.printMatrix();
  S21Matrix b{a};
  b.printMatrix();
  return 0;
}
