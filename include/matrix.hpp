/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {
 public:
  Matrix(long long, long long);
  Matrix(long long**, long long, long long);
  Matrix();
  ~Matrix();
  Matrix(const Matrix&);
  Matrix& operator=(const Matrix&);

  inline long long& operator()(long long x, long long y) { return p[x][y]; }

  Matrix& operator+=(const Matrix&);
  Matrix& operator-=(const Matrix&);
  Matrix& operator*=(const Matrix&);
  Matrix& operator*=(long long);
  Matrix& operator/=(long long);
  Matrix operator^(long long);

  friend std::ostream& operator<<(std::ostream&, const Matrix&);
  friend std::istream& operator>>(std::istream&, Matrix&);

  void swapRows(long long, long long);
  Matrix transpose();

  static Matrix createIdentity(long long);
  static Matrix solve(Matrix, Matrix);
  static Matrix bandSolve(Matrix, Matrix, long long);

  // functions on vectors
  static long long dotProduct(Matrix, Matrix);

  // functions on augmented matrices
  static Matrix augment(Matrix, Matrix);
  Matrix gaussianEliminate();
  Matrix rowReduceFromGaussian();
  void readSolutionsFromRREF(std::ostream& os);
  Matrix inverse();

 private:
  long long rows_, cols_;
  long long** p;

  void allocSpace();
  Matrix expHelper(const Matrix&, long long);
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, long long);
Matrix operator*(long long, const Matrix&);
Matrix operator/(const Matrix&, long long);

#endif
