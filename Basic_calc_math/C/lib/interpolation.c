#include <basic_type.h>


double linear_interpolation(double x, struct basic_data data){

	int left_index;

	for(int i = 0; i < data.N - 1; ++i){
		if (x >= data.mesh[i] && x < data.mesh[i+1]){
			left_index = i;
		};
	};

	return data.table_function[left_index] + 
		   ((data.table_function[left_index + 1] - data.table_function[left_index]) / (data.mesh[left_index + 1] - data.mesh[left_index])) * 
		   (x - data.mesh[left_index]);
}

