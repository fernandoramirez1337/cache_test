#ifndef HEADER_HPP
#define HEADER_HPP

#define MAX 512
#define block 4

void init(double[MAX][MAX], double);
void blockMult(const double A[MAX][MAX], const double b[MAX][MAX], double C[MAX][MAX]);

#endif