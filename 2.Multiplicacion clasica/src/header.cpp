#include "../include/header.hpp"

void init(double A[MAX][MAX], double val) {
  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j < MAX; ++j) {
      A[i][j] = val;
    }
  }
}

void mult(const double A[MAX][MAX], const double B[MAX][MAX], double C[MAX][MAX]) {
  int i(0), j(0), k(0);
  for (i = 0; i < MAX; i++) {
    for (j = 0; j < MAX; j++) {
      C[i][j] = 0;
      for (k = 0; k < MAX; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
