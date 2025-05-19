#include <basic_type.h>


double Boole_integral(int N, double (*function)(double), double *mesh);


double trapezoidal_integral(int N, double (*function)(double), double *mesh);


double Simpson_1_3_integral(int N, double (*function)(double), double *mesh);


double Simpson_3_8_integral(int N, double (*function)(double), double *mesh);


double rectangle_right_integral(int N, double (*function)(double), double *mesh); 


double rectangle_left_integral(int N, double (*function)(double), double *mesh);

