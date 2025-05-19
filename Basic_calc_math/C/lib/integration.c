#include <basic_type.h>


double Boole_integral(int N, double (*function)(double), double *mesh){
	int i;
	double discrete_sum = 0;
	double x_0, h;
	for (i = 0; i < N-1; ++i){
		h = (mesh[i+1] - mesh[i]) / 4;
		x_0 = mesh[i];
		discrete_sum += 2 * h * (7 * function(x_0) + 
								32 * function(x_0 + h) + 
								12 * function(x_0 + 2 * h) + 
								32 * function(x_0 + 3 * h) +
								7  * function(x_0 + 4 * h)) / 45 ;
	}

	return discrete_sum;
}


double trapezoidal_integral(int N, double (*function)(double), double *mesh){
	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * (function(mesh[i+1]) + function(mesh[i])) / 2.0 ;
	}

	return discrete_sum;
}


double Simpson_1_3_integral(int N, double (*function)(double), double *mesh){
	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * (function(mesh[i+1]) + 
												function(mesh[i]) + 
												4 * function((mesh[i+1] + mesh[i]) / 2)) / 6.0 ;
	}

	return discrete_sum;
}


double Simpson_3_8_integral(int N, double (*function)(double), double *mesh){
	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * (function(mesh[i+1]) + 
												function(mesh[i]) + 
												3 * function((2 * mesh[i+1] + mesh[i]) / 3) + 
												3 * function((mesh[i+1] + 2 * mesh[i]) / 3) ) / 8.0  ;
	}

	return discrete_sum;
}


double rectangle_right_integral(int N, double (*function)(double), double *mesh){

	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * function(mesh[i+1]);
	}

	return discrete_sum;
}


double rectangle_left_integral(int N, double (*function)(double), double *mesh){

	int i;
	double discrete_sum;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * function(mesh[i]);
	}

	return discrete_sum;
}