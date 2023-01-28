#ifndef SRC_MATRIX_OOP_HPP
#define SRC_MATRIX_OOP_HPP

#include <iostream>
#include <cstring>
#include <memory>
#include <cmath>

#define EPS 1e-7

class S21Matrix {
  public:
    S21Matrix();

    explicit S21Matrix(int, int); // +

    constexpr int getRows() const /*noexcept*/ { return rows_; }
    constexpr int getCols() const /*noexcept*/ { return cols_; }
    constexpr int size() const /*noexcept*/ { return rows_ * cols_; }

    S21Matrix(const S21Matrix&); // +
    S21Matrix(S21Matrix&&) noexcept; // +

    S21Matrix& operator=(const S21Matrix& other); // + 
    S21Matrix& operator=(S21Matrix&& other); // + 

    ~S21Matrix(); // +

    bool EqMatrix(const S21Matrix& other) const; // +
    void SumMatrix(const S21Matrix& other); // +
    void SubMatrix(const S21Matrix& other); // +
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose() const;
    S21Matrix CalcComplements() const;
    double Determinant() const;
    S21Matrix InverseMatrix() const;


    S21Matrix& operator+=(const S21Matrix& other); // +
    S21Matrix& operator-=(const S21Matrix& other); // +
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix operator-() const;

    void resize() noexcept;
    void setRows(int rows); // RowMutator
    void setCols(int cols); // ColMutator

    /* to access/set [i][j] element DEBUG STUFF ONLY */
    double& at(int i, int j) const {
      // throw exception for incorrect i or j
      return matrix_[index(i, j)];
    }
    // this is better than macro because of inlining
    size_t index(int row, int col) const {return col + cols_ * row;}

  private:
    int rows_, cols_;
    double *matrix_;
};

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right); // +
S21Matrix operator-(const S21Matrix& left, const S21Matrix& right); // +

/* S21Matrix operator*(const S21Matrix& left, const S21Matrix& right); */
S21Matrix operator*(const S21Matrix& left, const double n);
bool operator==(const S21Matrix& a, const S21Matrix& b); // +

std::ostream& operator<<(std::ostream& os, const S21Matrix& m);
std::istream& operator>>(std::istream& is, const S21Matrix& m);

#endif /* SRC_MATRIX_OOP_HPP */
