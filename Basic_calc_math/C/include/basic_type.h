#ifndef BASIC_TYPE_H_
#define BASIC_TYPE_H_

#include <string.h>

typedef struct basic_data
{
	int N;
	double *table_function;
	double *mesh;
};

typedef struct matrix
{
	int N;
	int type; // if type == 0 - full matrix, == 1 - symmectic, == 2 - diagonal
	double *diagonal;
	double *upper_triangle;
	double *lower_triangle;
};

typedef struct matrix_nondiagonal_addreses
{
	struct address{
		int add[3];  // 0 - i, 1 - j, 2 - k; i,j - indexes in ordinary matrix, k index in oneline matrix
	};

	int Num_of_nonzero_pairs;
	struct address *addresses;
};

struct matrix make_matrix(int N, double *diagonal, double *upper_triangle, double *lower_triangle);


#endif