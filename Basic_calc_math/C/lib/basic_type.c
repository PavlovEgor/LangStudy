#include "basic_type.h"


int find_nondiagonal_index(int i, int j){
	
};


struct matrix make_matrix(int N, double *diagonal, double *upper_triangle, double *lower_triangle)
{
	struct matrix tmp_matrix;

	tmp_matrix.N = N;

	if (lower_triangle == NULL && upper_triangle == NULL){
		tmp_matrix.type = 2;
		tmp_matrix.diagonal = diagonal;
	} else if (lower_triangle == NULL) {
		tmp_matrix.type = 1;
		*tmp_matrix.diagonal = *diagonal;
		*tmp_matrix.upper_triangle = *upper_triangle;
	} else {
		tmp_matrix.type = 0;
		*tmp_matrix.diagonal = *diagonal;
		*tmp_matrix.upper_triangle = *upper_triangle;
		*tmp_matrix.lower_triangle = *lower_triangle;
	}

	return tmp_matrix;
};