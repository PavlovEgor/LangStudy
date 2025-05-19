#include <stdio.h>
#include "mpi.h"

#define n 100
#define a 1.0
#define b 2.0

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

double f(double x){
	return x * x;
}

void uniform_mesh(double *mesh, double x_min, double x_max) {
	int i;
	for (i = 0; i < n; ++i){
		mesh[i] = x_min + i * (x_max - x_min) / (n-1);
	}
}

int main(int argc, char **argv){
    int me, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("me = %d, size = %d \n", me, size);

    // double a_comm = a + (me * (b - a)) / size;
    // double b_comm = a_comm + (b - a) / size;
    
    // double mesh[n];
	// uniform_mesh(mesh, a_comm, b_comm);


    // printf("Process %d size %d \n", me, size);
    // printf ("Trapezoidal rule %20.15f \n", trapezoidal_integral(n, f, mesh));
    // printf ("Boole rule       %20.15f \n", Boole_integral(n, f, mesh));

    // double local_integral = trapezoidal_integral(n, f, mesh);

    // if (me == 0){
    //     double Integral = local_integral;
    //     double tmp;
    //     int sourse = 0;
    //     MPI_Status status;

    //     for(sourse = 1; sourse < size; sourse++)
    //     {
    //         MPI_Recv(&tmp, 1, MPI_DOUBLE, sourse, 99, MPI_COMM_WORLD, &status);
    //         Integral += tmp;
    //     }
        
    //     printf ("Trapezoidal rule %20.15f \n", Integral);

    // }else{
    //     MPI_Send(&local_integral, 1, MPI_DOUBLE, 0, 99, MPI_COMM_WORLD);
    // }

    // double Integral = 0;
    // MPI_Reduce(&local_integral, &Integral, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    // if (me == 0)
    // {
    //     printf ("Trapezoidal rule %20.15f \n", Integral);
    // }
    

    MPI_Finalize();
}