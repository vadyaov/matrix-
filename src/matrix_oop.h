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
    S21Matrix& operator=(S21Matrix&& other) noexcept; // + 

    ~S21Matrix(); // +

    bool EqMatrix(const S21Matrix& other) const noexcept; // +
    void SumMatrix(const S21Matrix& other); // +
    void SubMatrix(const S21Matrix& other); // +
    void MulNumber(const double num) noexcept; // +
    void MulMatrix(const S21Matrix& other); // +

    S21Matrix Transpose() const;
    S21Matrix CalcComplements() const;
    double Determinant() const;
    S21Matrix InverseMatrix() const;


    S21Matrix& operator+=(const S21Matrix& other); // +
    S21Matrix& operator-=(const S21Matrix& other); // +
    S21Matrix& operator*=(const S21Matrix& other); // +

    S21Matrix operator-() const; // +
    S21Matrix& operator*=(const double) noexcept; // +

    void resize();
    void setRows(int rows); // RowMutator
    void setCols(int cols); // ColMutator

    /* to access/set [i][j] element */
    double& at(int i, int j) const {
      if (i >= rows_ || j >= cols_)
        throw std::out_of_range("Incorrect index in S21Matrix at(i, j)");
      return this->operator()(i, j);
    }
    // this is better than macro because of inlining
    // UPD: OK mb it will be done by operator (i, j) from task --> same thing as line below
    /* constexpr size_t index(int row, int col) const {return col + cols_ * row;} */
    double& operator()(int row, int col) const {return matrix_[col + cols_ * row];};

  private:
    int rows_, cols_;
    double *matrix_;
};

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right); // +
S21Matrix operator-(const S21Matrix& left, const S21Matrix& right); // +

S21Matrix operator*(const S21Matrix& left, const S21Matrix& right);
S21Matrix operator*(const S21Matrix& left, const double n);
bool operator==(const S21Matrix& a, const S21Matrix& b); // +

// for matrix multiplication
double multiply(int i, int j, const S21Matrix& left, const S21Matrix& right);

// for cout and cin
std::ostream& operator<<(std::ostream& os, const S21Matrix& m);
std::istream& operator>>(std::istream& is, const S21Matrix& m);

#endif /* SRC_MATRIX_OOP_HPP */
