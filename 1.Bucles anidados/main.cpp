#include <iostream>
#include "include/header.hpp"

#define MAX (int)10

int main() {
  double A[MAX][MAX], x[MAX], y[MAX];

  for (int i = 0; i < MAX; i++)
  for (int j = 0; j < MAX; j++)
  A[i][j] = static_cast<double>(i + j + 1) * 0.1;

  for (int i = 0; i < MAX; i++)
  x[i] = static_cast<double>(i + 1) * 0.1;

  for (int i = 0; i < MAX; i++) 
  y[i] = 0.0;

  for (int i = 0; i < MAX; i++)
  for (int j = 0; j < MAX; j++)
  y[i] += A[i][j] * x[j];

  for (int j = 0; j < MAX; j++)
  for (int i = 0; i < MAX; i++)
  y[i] += A[i][j] * x[j];

  return 0;
}