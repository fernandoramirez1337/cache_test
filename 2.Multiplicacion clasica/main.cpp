#include <iostream>
#include <chrono>

#define MAX 512

void init(double[MAX][MAX], double);
void mult(const double A[MAX][MAX], const double b[MAX][MAX], double C[MAX][MAX]);

int main() {
  double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  init(A, 1.0);
  init(B, 1.0);
  init(C, 0.0);

  auto start = std::chrono::high_resolution_clock::now();
  mult(A, B, C);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;
  std::cout << "Tiempo de ejecución: " << duration.count() << " segundos" << std::endl;

  return 0;
}

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
