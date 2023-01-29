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
    ~S21Matrix();
    /* explicit - конструктор используется лишь для инициализации и явных приведений типа */
    explicit S21Matrix(const int, const int); // + 

    /* compiler error when constexpr. why ? */
    /* constexpr */ int getRows() const noexcept;
    /* constexpr */ int getCols() const noexcept;
    constexpr int size() const noexcept;

    S21Matrix(const S21Matrix&); // +
    S21Matrix(S21Matrix&&) noexcept; // +

    S21Matrix& operator=(const S21Matrix&); // + 
    S21Matrix& operator=(S21Matrix&&) noexcept; // + 

    bool EqMatrix(const S21Matrix&) const noexcept; // +
    void SumMatrix(const S21Matrix&); // +
    void SubMatrix(const S21Matrix&); // +
    void MulNumber(const double) noexcept; // +
    void MulMatrix(const S21Matrix&); // +

    S21Matrix Transpose() const; // +
    S21Matrix CalcComplements() const; // +
    double Determinant() const; // +
    S21Matrix InverseMatrix() const; // +

    S21Matrix& operator+=(const S21Matrix&); // +
    S21Matrix& operator-=(const S21Matrix&); // +
    S21Matrix& operator*=(const S21Matrix&); // +

    S21Matrix operator-() const; // +
    S21Matrix& operator*=(const double) noexcept; // +
    /* to access/set [i][j] element */
    double& operator()(const int, const int) const; // +

    void resize();
    void setRows(const int); // RowMutator
    void setCols(const int); // ColMutator

  private:
    int rows_, cols_;
    double *matrix_;
};

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right); // +
S21Matrix operator-(const S21Matrix& left, const S21Matrix& right); // +
S21Matrix operator*(const S21Matrix& left, const S21Matrix& right); // +
S21Matrix operator*(const S21Matrix& left, const double n); // +
bool operator==(const S21Matrix& a, const S21Matrix& b); // +

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

#endif /* SRC_MATRIX_OOP_HPP */
