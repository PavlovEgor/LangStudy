#include <integration.h>
#include <stdio.h>
#include <math.h>
#include <basic_type.h>


#define N 100

double f(double x){
	return x;
}

void uniform_mesh(double *mesh, double x_min, double x_max) {
	int i;
	for (i = 0; i < N; ++i){
		mesh[i] = x_min + i * (x_max - x_min) / (N-1);
	}
}

int main(){

	double mesh[N];
	uniform_mesh(mesh, 0, 1);

	printf ("Rectangle method %20.15f \n", rectangle_right_integral(N, f, mesh));
	printf ("Trapezoidal rule %20.15f \n", trapezoidal_integral(N, f, mesh));
	printf ("Simpson 1/3 rule %20.15f \n", Simpson_1_3_integral(N, f, mesh));
	printf ("Simpson 3/8 rule %20.15f \n", Simpson_3_8_integral(N, f, mesh));
	printf ("Boole rule       %20.15f \n", Boole_integral(N, f, mesh));
}