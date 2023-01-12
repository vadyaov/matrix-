#ifndef SRC_MATRIX_OOP_HPP
#define SRC_MATRIX_OOP_HPP

#include <iostream>

class S21Matrix {
  public:
    /* what size ??? */ 
    /* random value ? mb 1x1 ? */ 
    S21Matrix();
    /* think about 'explicit' key word */
    /* mb it is useful for these constructors */
    explicit S21Matrix(int rows, int cols) : rows_{rows}, cols_{cols},
                                             matrix_{new double[rows * cols]()}
    {
    }
    S21Matrix(const S21Matrix& other) : rows_{other.getRows()}, cols_{other.getCols()},
                                        matrix_{new double[rows_ * cols_]} {
      for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
          matrix_[index(i, j)] = other.at(i, j);
    }
    S21Matrix(const S21Matrix&& other);
    ~S21Matrix() { delete[] matrix_; }

    bool EqMatrix(const S21Matrix& other) const;
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose() const;
    S21Matrix CalcComplements() const;
    double Determinant() const;
    S21Matrix InverseMatrix() const;

    /* S21Matrix& operator=(const S21Matrix& other); */
    /* S21Matrix& operator+=(const S21Matrix& other); */
    /* S21Matrix& operator-=(const S21Matrix& other); */
    /* S21Matrix& operator*=(const S21Matrix& other); */

    /* -------------------------------------------------------- */
    /* also need accessors and mutators for private fields */
    /* something like getRows, gelCols, setRows, setCols; */
    /* -------------------------------------------------------- */
    int getRows() const { return rows_; }
    int getCols() const { return cols_; }
    double at(int i, int j) const { return matrix_[index(i, j)]; }
    // this is better than macro because of inlining
    int index(int row, int col) const {return row + rows_ * col;}

    //debug help
    void setMatrix() {
      for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
          std::cin >> matrix_[index(i, j)];
    }

    void printMatrix() {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          std::cout << matrix_[index(i, j)] << " ";
        }
        std::cout << std::endl;
      }
    }

  private:
    int rows_, cols_;
    double *matrix_;
};

/* S21Matrix operator+(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator-(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator*(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator*(const S21Matrix& left, const double n); */
/* bool operator==(const S21Matrix& A, const S21Matrix& B); */

#endif /* SRC_MATRIX_OOP_HPP */
