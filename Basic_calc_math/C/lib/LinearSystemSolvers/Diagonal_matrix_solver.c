#include "Diagonal_matrix_solver.h"
#include "basic_type.h"
#include <stdlib.h>

/* 
Solve equation: Dx = B
D - diagonal matrix; x, B - vectores
*/ 


double diagonal_solve(struct matrix D, double *x, double *B){
	
	for (int i=0; i<D.N; ++i){
		x[i] = B[i] / (D.diagonal[i]);
	}

	return *x;
};
