#include <stdio.h>
#include <stdlib.h>
#include "DirectGauss.h"


void mat_print(int N, double *matrix, double *b){
    printf("_________\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3.2f ", matrix[i * N + j]);
        }
        printf("| %3.2f \n", b[i]);
    }
    printf("_________\n");

}


void direct_gauss_solve(int N, double *matrix, double *x, double *b){

    double tmp;

    for (int i = 0; i < N; i++)
    {   
        tmp = 1 / matrix[N * i + i];
        b[i] = b[i] * tmp;
        for (int k = i; k < N; k++)
        {
            matrix[N * i + k] = matrix[N * i + k] * tmp;
        }
        
        for (int j = i+1; j < N; j++)
        {
            b[j] -= b[i] * matrix[j * N + i];

            for (int k = i+1; k < N; k++)
            {
                matrix[j * N + k] -= matrix[i * N + k] * matrix[j * N + i];
            }
        }
    }
    
    x[N-1] = b[N-1];

    for (int i = N-2; i >=0; i--)
    {
        x[i] = b[i];
        for (int j = i+1; j < N; j++)
        {
            x[i] -= matrix[N * i + j] * x[j];
        }
    }
}




int main(){
    const int N = 3;
    // double *matrix = malloc((N * N) * sizeof(double));
    // double *result = malloc(N * sizeof(double));
    // double *left_part = malloc(N * sizeof(double));

    double matrix[] = {2, 3, -1, 1, -2, 1, 1, 0, 2};
    double *result = malloc(N * sizeof(double));
    double left_part[] = {9, 3, 2};
    
    mat_print(N, matrix, left_part);

    direct_gauss_solve(N, matrix, result, left_part);

    for (int i = 0; i < N; i++)
    {
        printf("%3.2f ", result[i]);
    }
    printf("\n");


}