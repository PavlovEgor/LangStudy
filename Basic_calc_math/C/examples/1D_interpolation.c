#include <interpolation.h>
#include <stdio.h>
#include <math.h>
#include <basic_type.h>


#define Num_of_cells 100

double f(double x){
	return x;
}



void uniform_mesh(double *mesh, double x_min, double x_max) {
	int i;
	for (i = 0; i < Num_of_cells; ++i){
		mesh[i] = x_min + i * (x_max - x_min) / (Num_of_cells-1);
	}
}

int main(){

	double mesh[Num_of_cells];
	uniform_mesh(mesh, 0, 1);

	double table_function[Num_of_cells];
	for(int i = 0;i < Num_of_cells; ++i){
		table_function[i] = f(mesh[i]);
	};


	struct basic_data data = {.N=Num_of_cells, 
									  .table_function=table_function, 
									  .mesh=mesh};


    printf ("Linear interpolation %20.15f \n", linear_interpolation(0.501, data));

}