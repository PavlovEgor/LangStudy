#include "basic_type.h"
#include <stdio.h>


int main(int argc, char const *argv[])
{
	struct matrix tmp_matrix;
	double diag[3] = {1, 2, 3};
	tmp_matrix = make_matrix(3, diag, NULL, NULL);

	printf("%f, %f, %f\n", tmp_matrix.diagonal[0], tmp_matrix.diagonal[2], tmp_matrix.diagonal[1]);
	printf("%d \n", tmp_matrix.type);

	return 0;
}