#ifndef SRC_MATRIX_OOP_HPP
#define SRC_MATRIX_OOP_HPP

#include <iostream>

class S21Matrix {
  public:
    S21Matrix() : rows_{1}, cols_{1}, matrix_{new double()} {}
    explicit S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other) : rows_{other.getRows()}, cols_{other.getCols()},
                                        matrix_{new double[rows_ * cols_]}
    {
      for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
          matrix_[index(i, j)] = other.at(i, j);
    }
    S21Matrix(const S21Matrix&& other) noexcept;
    ~S21Matrix() {
      if (matrix_)
        delete[] matrix_;
    }

    bool EqMatrix(const S21Matrix& other) const;
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose() const;
    S21Matrix CalcComplements() const;
    double Determinant() const;
    S21Matrix InverseMatrix() const;

    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);

    int getRows() const noexcept { return rows_; }
    int getCols() const noexcept { return cols_; }
    void setRows(int rows);
    void setCols(int cols);

    /* to access/set [i][j] element */
    double& at(int i, int j) const {
      // throw exception for incorrect i or j
      return matrix_[index(i, j)];
    }
    // this is better than macro because of inlining
    int index(int row, int col) const {return row + rows_ * col;}

    //debug help

  private:
    int rows_, cols_;
    double *matrix_;
};

/* S21Matrix operator+(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator-(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator*(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator*(const S21Matrix& left, const double n); */
bool operator==(const S21Matrix& a, const S21Matrix& b);

std::ostream& operator<<(std::ostream& os, const S21Matrix& m);
std::istream& operator>>(std::istream& is, const S21Matrix& m);

#endif /* SRC_MATRIX_OOP_HPP */
