#include <iostream>
#include <chrono>
#include "include/header.hpp"

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