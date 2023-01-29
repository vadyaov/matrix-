#include "matrix_oop.h"

S21Matrix::S21Matrix() : rows_{1},
                         cols_{1},
                         matrix_{new double()} {
  std::cout << "Default constructor is called" << std::endl;
}

S21Matrix::S21Matrix(int rows, int cols) {
  std::cout << "Param constructor is called for rows " << rows << " and cols " << cols << std::endl;
  if (rows < 0 || cols < 0)
    // mb i need my own exceptions ???
    throw std::invalid_argument("bad size in S21Matrix::S21Matrix(int, int)");
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
  if (rows_ != other.rows_)
    setRows(other.rows_);
  if (cols_ != other.cols_)
    setCols(other.cols_);

  std::copy(other.matrix_, other.matrix_ + other.size(), matrix_);
  return *this;
}

/* ---------------------------USAGE---------------------------------*/
/* The move constructor is typically called when an object is initialized
 * (by direct-initialization or copy-initialization) from rvalue (xvalue or prvalue)
 * (until C++17)xvalue (since C++17) of the same type, including: */ 

/* initialization: S21Matrix a = std::move(b); or S21Matrix a(std::move(b));,
 * where b is of type S21Matrix; */
/* function argument passing: f(std::move(a));, where a is of type S21Matrix
 * and f is void f(S21Matrix t); */
/* function return: return a; inside a function such as S21Matrix f(),
 * where a is of type S21Matrix which has a move constructor. */ 
S21Matrix::S21Matrix(S21Matrix&& other) noexcept : rows_{other.rows_}, cols_{other.cols_},
                                                         matrix_{other.matrix_} {
  std::cout << "Move constructor is called" << std::endl;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
  return *this;
}

S21Matrix::~S21Matrix() {
  /* if (matrix_) */
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

// not sure about using 'at' function at all, but it seems like the only one way
// to set and get (i, j) element
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::runtime_error("this->cols_ != other.rows in S21Matrix *=");
  S21Matrix res{rows_, other.cols_};
  for (auto i = 0; i < res.rows_; i++)
    for (auto j = 0; j < res.cols_; j++)
      res.at(i, j) = multiply(i, j, *this, other);
  *this = res;
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double n) noexcept {
  for (auto i = 0; i < this->size(); i++)
    matrix_[i]  *= n;
  return *this;
}

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix res {left};
  return res += right; // доступ к представлению через +=
}

S21Matrix operator-(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix res {left};
  return res -= right; // доступ к представлению через +=
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool size = cols_ == other.cols_ && rows_ == other.rows_;
  if (size) {
    double *m1 = matrix_;
    double *m2 = other.matrix_;
    double *end = matrix_ + this->size();

    while (m1 != end && size)
      size = std::fabs(*m1++ - *m2++) < EPS;
  }
  return size;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  *this += other;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  *this -= other;
}

bool operator==(const S21Matrix& a, const S21Matrix& b) {
  return a.EqMatrix(b);
}

S21Matrix operator*(const S21Matrix& left, const S21Matrix& right) {
  std::cout << "non member operator* is called" << std::endl;
  S21Matrix res{left};
  return res *= right;
}

S21Matrix operator*(const S21Matrix& left, const double n) {
  std::cout << "S21Matrix operator* is called" << std::endl;
  S21Matrix tmp{left};
  return tmp *= n;
}

void S21Matrix::MulNumber(const double num) noexcept {
  *this *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  *this *= other;
}

// mb this is not the best idea of implementation mutators but it works
// think how to do it better if possible because
// doesn't enjoy calling destructor int resize()
void S21Matrix::setRows(int rows) {
  if (rows <= 0)
    throw std::logic_error("bad rows in setRows()");
  else if (rows != rows_) {
    rows_ = rows;
    resize();
  }
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0)
    throw std::logic_error("bad cols in setCols()");
  else if (cols != cols_) {
    cols_ = cols;
    resize();
  }
}
