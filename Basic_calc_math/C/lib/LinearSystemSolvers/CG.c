void matrix_vector_prod(int N, double *A, double *b, double *x){ // x = Ab
	for (int i=0; i<N; ++i){
		for (int j=0; j<N; ++j){
			x[i] = A[i * N + j] * b[i];
		}
	}
}

void vector_vector_diff(int N, double *a, double *b, double *x){  // x = a - b
	for (int i=0; i<N; ++i){
		x[i] = a[i] - b[i]
	}
}


void vector_vector_sum(int N, double *a, double *b, double *x){  // x = a + b
	for (int i=0; i<N; ++i){
		x[i] = a[i] + b[i]
	}
}

void conjugate_gradient_solver(int N, double *A, double *x, double *b){

	int L = 1000;
	double *tmp = malloc(N * sizeof(double));

	for (int i=0; i<N; ++i){
		x[i] = b[i] / A[i*N + i];
	}

	double *p = malloc(L*N * sizeof(double));
	double *pA = malloc(L*N * sizeof(double));
	double *pAp = malloc(L * sizeof(double));

	double *r = malloc(N * sizeof(double));

	for (i=0; i<N; ++i){
		p[i] = b[i]
		for (j=0; j<N; ++j){
			p[i] += A[i * N + j] * b[j];
		}
	}

	matrix_vector_prod(N, A, b, tmp)
	vector_vector_diff(N, b, tmp, p)

	for (int l=0; l<N; ++l){

	}
}