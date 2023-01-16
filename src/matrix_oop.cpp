#include "matrix_oop.hpp"

S21Matrix::S21Matrix() : rows_{1},
                         cols_{1},
                         matrix_{new double()} {
  std::cout << "Default constructor is called" << std::endl;
}

S21Matrix::S21Matrix(int rows, int cols) {
  std::cout << "Param constructor is called for rows:" << rows << "and cols:" << cols << std::endl;
  if (rows < 0 || cols < 0)
    // mb i need my own exceptions ???
    throw std::bad_alloc();
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows * cols]();
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows_{other./*getRows()*/rows_}, cols_{other./*getCols()*/cols_},
                                    matrix_{new double[rows_ * cols_]} {
  std::cout << "Copy constructor is called" << std::endl;
  /* for (int i = 0; i < rows_; i++) */
  /*   for (int j = 0; j < cols_; j++) */
  /*     matrix_[index(i, j)] = other.at(i, j); */

  // private fields can be reached in the interface functions don't forget it!
  std::memcpy(matrix_, other.matrix_, rows_ * cols_ * sizeof(double));
}

S21Matrix::S21Matrix(const S21Matrix&& other) noexcept {
  std::cout << "Move constructor is called" << std::endl;
}

S21Matrix::~S21Matrix() {
 // will be null only if i make default constructor with 0,0, nullptr fields! so make this or delete line below
  if (matrix_)
    delete[] matrix_;
}

// ----------------------- DEBUG -------------------------- //

std::ostream& operator<<(std::ostream& os, const S21Matrix& m) {
  for (int i = 0; i < m.getRows(); i++) {
    for (int j = 0; j < m.getCols(); j++) {
      os << m.at(i, j) << " ";
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, const S21Matrix& m) {
  for (int i = 0; i < m.getRows(); i++)
    for (int j = 0; j < m.getCols(); j++)
      is >> m.at(i, j);
  return is;
}

// ------------------------------------------------------- //
