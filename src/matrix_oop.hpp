#ifndef SRC_MATRIX_OOP_HPP
#define SRC_MATRIX_OOP_HPP

class S21Matrix {
  public:
    S21Matrix();
    /* think about 'explicit' key word */
    /* mb it is useful for these constructors */
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(const S21Matrix&& other);
    ~S21Matrix();

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
    /* double operator[][](int i, int j); */

  private:
    int rows_, cols_;
    double **matrix_;
};

/* S21Matrix operator+(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator-(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator*(const S21Matrix& left, const S21Matrix& right); */
/* S21Matrix operator*(const S21Matrix& left, const double n); */
/* bool operator==(const S21Matrix& A, const S21Matrix& B); */

#endif /* SRC_MATRIX_OOP_HPP */
