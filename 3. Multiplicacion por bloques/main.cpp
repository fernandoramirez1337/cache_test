#include <iostream>
#include <chrono>

#define MAX 512
#define block 4

void init(double[MAX][MAX], double);
void blockMult(const double A[MAX][MAX], const double b[MAX][MAX], double C[MAX][MAX]);

int main() {
  double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  init(A, 1.0);
  init(B, 1.0);
  init(C, 0.0);

  auto start = std::chrono::high_resolution_clock::now();
  blockMult(A, B, C);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;
  std::cout << "Tiempo de ejecución (bloques): " << duration.count() << " segundos" << std::endl;

  return 0;
}

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