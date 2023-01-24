#include "matrix_oop.hpp"

S21Matrix::S21Matrix() : rows_{1},
                         cols_{1},
                         matrix_{new double()} {
  std::cout << "Default constructor is called" << std::endl;
}

S21Matrix::S21Matrix(int rows, int cols) {
  std::cout << "Param constructor is called for rows " << rows << " and cols " << cols << std::endl;
  if (rows < 0 || cols < 0)
    // mb i need my own exceptions ???
    throw std::runtime_error("bad size in S21Matrix::S21Matrix");
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows * cols]();
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows_{other.rows_},
                                               cols_{other.cols_},
                                               matrix_{new double[rows_ * cols_]()} {
  std::cout << "Copy constructor is called" << std::endl;
  std::uninitialized_copy(other.matrix_, other.matrix_ + other.size(), matrix_);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  std::cout << "Copy operator= is called" << std::endl;
  /* S21Matrix tmp {other}; */
  /* std::swap(tmp, *this); */
  
   /* need to check the dimensions
      (A = B)
              A < B --> increase A than copy
              A > B --> copy then decrease || decrease than copy
    */
  std::copy(other.matrix_, other.matrix_ + other.size(), matrix_);
  return *this;
}

/* ---------------------------USAGE---------------------------------*/
/* The move constructor is typically called when an object is initialized (by direct-initialization or copy-initialization)
 * from rvalue (xvalue or prvalue) (until C++17)xvalue (since C++17) of the same type, including: */ 

/* initialization: S21Matrix a = std::move(b); or S21Matrix a(std::move(b));, where b is of type S21Matrix; */
/* function argument passing: f(std::move(a));, where a is of type S21Matrix and f is void f(S21Matrix t); */
/* function return: return a; inside a function such as S21Matrix f(), where a is of type S21Matrix which has a move constructor. */ 
S21Matrix::S21Matrix(S21Matrix&& other) noexcept : rows_{other.rows_}, cols_{other.cols_},
                                                         matrix_{other.matrix_} {
  std::cout << "Move constructor is called" << std::endl;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
  return *this;
}

S21Matrix::~S21Matrix() {
 // will be null only if i make default constructor with 0,0, nullptr fields! so make this or delete line below
  if (matrix_)
    delete[] matrix_;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::runtime_error("Bad size in S21Matrix +=");

  double *p = matrix_;
  double *q = other.matrix_;
  double *end = p + this->size();
  while (p != end)
    *p++ += *q++;
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  return *this += -other;
}

S21Matrix S21Matrix::operator-() const {
  S21Matrix tmp {rows_, cols_};
  for (auto i = 0; i < tmp.size(); i++)
    tmp.matrix_[i] = -matrix_[i];
  return tmp;
}

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix res {left};
  return res += right; // доступ к представлению через +=
}

S21Matrix operator-(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix res {left};
  return res -= right; // доступ к представлению через +=
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
