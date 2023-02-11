#ifndef MATRIXPLUS_INC_S21_MATRIX_OOP_H_
#define MATRIXPLUS_INC_S21_MATRIX_OOP_H_

#include <algorithm>
#include <cstring>
#include <memory>
#include <cmath>

constexpr double EPS = 1e-7;

class S21Matrix {
  public:
    S21Matrix();
    explicit S21Matrix(const int, const int);

    S21Matrix(const S21Matrix&);
    S21Matrix& operator=(const S21Matrix&);

    S21Matrix(S21Matrix&&) noexcept;
    S21Matrix& operator=(S21Matrix&&) noexcept;

    ~S21Matrix();

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

    int GetRows() const noexcept;
    int GetCols() const noexcept;

    void SetRows(const int);
    void SetCols(const int);

    int Size() const noexcept;
    void Resize(const int, const int);
  private:
    int rows_, cols_;
    double *matrix_;
};

S21Matrix operator-(const S21Matrix&);
bool operator==(const S21Matrix&, const S21Matrix&) noexcept;

S21Matrix& operator+=(S21Matrix&, const S21Matrix&);
S21Matrix& operator-=(S21Matrix&, const S21Matrix&);
S21Matrix& operator*=(S21Matrix&, const S21Matrix&);
S21Matrix& operator*=(S21Matrix&, const double) noexcept;

S21Matrix operator+(const S21Matrix&, const S21Matrix&);
S21Matrix operator-(const S21Matrix&, const S21Matrix&);
S21Matrix operator*(const S21Matrix&, const S21Matrix&);
S21Matrix operator*(const S21Matrix&, const double);

#endif  // MATRIXPLUS_INC_S21_MATRIX_OOP_H_
