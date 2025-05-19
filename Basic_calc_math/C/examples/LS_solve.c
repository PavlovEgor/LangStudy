#include "basic_type.h"
#include "Diagonal_matrix_solver.h"
#include <stdio.h>


int main(int argc, char const *argv[])
{
	struct matrix diag_matrix;
	double diag[3] = {1, 2, 3};
	double sourse[3] = {1, 2, 3};
	diag_matrix = make_matrix(3, diag, NULL, NULL);

	double x[3];

	diagonal_solve(diag_matrix, x, sourse); 

	printf("%f, %f, %f \n", x[0], x[1], x[2]);

	//------------------------------------------
	const int N = 3;
	double non_diag[] = {2, 3, -1, 1, -2, 1, 1, 0, 2};
    double *result = malloc(N * sizeof(double));
    double left_part[] = {9, 3, 2};
    
    direct_gauss_solve(N, non_diag, result, left_part);

	printf("%f, %f, %f \n", result[0], result[1], result[2]);

	return 0;
}