#ifndef MATRIXPLUS_LIB_S21_MATRIX_OOP_H
#define MATRIXPLUS_LIB_S21_MATRIX_OOP_H

#include <iostream>
#include <cstring>
#include <memory>
#include <cmath>

#define EPS 1e-7

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
    void resize();

    ~S21Matrix();
  private:
    int rows_, cols_;
    double *matrix_;
};

// Определяю вне класса, чтобы минимизировать число функций, непосредственно манипулирующих
// представлением объекта. Нужно стараться определять внутри класса только те методы, которые неизбежно
// модифицируют зачение первого аргумента

S21Matrix operator-(const S21Matrix& a);

S21Matrix& operator+=(S21Matrix& a, const S21Matrix& b);
S21Matrix& operator-=(S21Matrix& a, const S21Matrix& b);
S21Matrix& operator*=(S21Matrix& a, const S21Matrix& b);
S21Matrix& operator*=(S21Matrix& a, const double n) noexcept;

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right);
S21Matrix operator-(const S21Matrix& left, const S21Matrix& right);
S21Matrix operator*(const S21Matrix& left, const S21Matrix& right);
S21Matrix operator*(const S21Matrix& left, const double n);
bool operator==(const S21Matrix& a, const S21Matrix& b) noexcept;

// UNSAFE!!! HELP FUNCTIONS
// the question is how to protect them from user ??
double multiply(int i, int j, const S21Matrix& left, const S21Matrix& right);
S21Matrix SimpleMinor(const S21Matrix&);
double CalcMinor(const S21Matrix&, const int i, const int j);
S21Matrix CreateSmaller(const S21Matrix&, const int i, const int j);
double Det(const S21Matrix&);

// for cout and cin
std::ostream& operator<<(std::ostream& os, const S21Matrix& m);
std::istream& operator>>(std::istream& is, const S21Matrix& m);

#endif  // MATRIXPLUS_LIB_S21_MATRIX_OOP_H
