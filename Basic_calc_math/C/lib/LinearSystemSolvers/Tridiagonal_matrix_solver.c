#include "Diagonal_matrix_solver.h"
#include "basic_type.h"
#include <stdlib.h>

/* 
Solve equation: Tx = B
T - tridiagonal matrix; x, B - vectores
*/ 


double tridiagonal_solve(struct matrix T, double *x, double *B){
	int N = T.N;

	double *x = malloc(N * sizeof(double));

	// toward

	x[0] = 1;
	x[1] = (B[0] - T.diagonal[0]) / T.upper_triangle[find_nondiagonal_index(addresses, 0, 1)];

	for (int i=1; i < N; ++i){
		x[i] = (B[i-1] - T.diagonal[i-1] * x[i-1] - T.lower_triangle[find_nondiagonal_index(addresses, i, i-1)] * x[i-2]) / 
		T.upper_triangle[find_nondiagonal_index(addresses, i, i+1)];
	}

	double x1 = B[N-1] / (T.diagonal[N-1] * x[T.N-1] + T.lower_triangle[find_nondiagonal_index(addresses, N-1, T.N-2)] * x[N-2]);

	// backward

	for (i = 0; i < N; ++i){
		x[i] *= x1;
	}

	return *x;
};