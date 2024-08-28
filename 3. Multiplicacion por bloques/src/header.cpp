#include "../include/header.hpp"

void init(double A[MAX][MAX], double val) {
  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j < MAX; ++j) {
      A[i][j] = val;
    }
  }
}

void blockMult(const double A[MAX][MAX], const double B[MAX][MAX], double C[MAX][MAX]) {
  int ii(0), jj(0), kk(0), i(0), j(0), k(0);
  for(int ii = 0; ii < MAX; ii += block) {
    for(int jj = 0; jj < MAX; jj += block) {
      for(int kk = 0; kk < MAX; kk += block) {
        for(int i = ii; i < ii + block; ++i) {
          for(int j = jj; j < jj + block; ++j) {
            for(int k = kk; k < kk + block; ++k) 
            C[i][j] += A[i][k]*B[k][j];
          }
        }               
      }
    }
  }
}