#ifndef MATRIXPLUS_LIB_S21_MATRIX_OOP_H
#define MATRIXPLUS_LIB_S21_MATRIX_OOP_H

#include <iostream>
#include <cstring>
#include <memory>
#include <cmath>

#define EPS 1e-7

/* namespace Matrix { */

  class S21Matrix {
    public:
      S21Matrix();
      explicit S21Matrix(const int, const int);

      int getRows() const noexcept;
      int getCols() const noexcept;
      int size() const noexcept;

      S21Matrix(const S21Matrix&);
      S21Matrix& operator=(const S21Matrix&);

      S21Matrix(S21Matrix&&) noexcept;
      S21Matrix& operator=(S21Matrix&&) noexcept;

      bool EqMatrix(const S21Matrix&) const noexcept;
      void SumMatrix(const S21Matrix&);
      void SubMatrix(const S21Matrix&);
      void MulNumber(const double) noexcept;
      void MulMatrix(const S21Matrix&);
      S21Matrix Transpose() const;
      S21Matrix CalcComplements() const;
      double Determinant() const;
      S21Matrix InverseMatrix() const;

      double& operator()(const int, const int) const;

      void setRows(const int);
      void setCols(const int);
      void resize(int, int);

      ~S21Matrix();
    private:
      int rows_, cols_;
      double *matrix_;
  };

  // Определяю вне класса, чтобы минимизировать число функций, непосредственно манипулирующих
  // представлением объекта. Нужно стараться определять внутри класса только те методы, которые неизбежно
  // модифицируют зачение первого аргумента

  S21Matrix operator-(const S21Matrix&);
  S21Matrix& operator+=(S21Matrix&, const S21Matrix&);
  S21Matrix& operator-=(S21Matrix&, const S21Matrix&);
  S21Matrix& operator*=(S21Matrix&, const S21Matrix&);
  S21Matrix& operator*=(S21Matrix&, const double) noexcept;

  S21Matrix operator+(const S21Matrix&, const S21Matrix&);
  S21Matrix operator-(const S21Matrix&, const S21Matrix&);
  S21Matrix operator*(const S21Matrix&, const S21Matrix&);
  S21Matrix operator*(const S21Matrix&, const double);
  bool operator==(const S21Matrix&, const S21Matrix&) noexcept;

  // UNSAFE!!! HELP FUNCTIONS
  // the question is how to protect them from user ??
  double multiply(const S21Matrix&, const S21Matrix&, const int, const int) noexcept;
  S21Matrix SimpleMinor(const S21Matrix&) noexcept;
  double CalcMinor(const S21Matrix&, const int, const int) noexcept;
  S21Matrix CreateSmaller(const S21Matrix&, const int, const int) noexcept;
  double Det(const S21Matrix&) noexcept;

  std::ostream& operator<<(std::ostream&, const S21Matrix&) noexcept;
  std::istream& operator>>(std::istream&, const S21Matrix&) noexcept;

/* }; */

#endif  // MATRIXPLUS_LIB_S21_MATRIX_OOP_H
