#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>


void mat_print(int N, double *matrix){
    printf("_________\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3.2f ", matrix[i * N + j]);
        }
        printf("\n");
    }
    printf("_________\n");

}


void matmul_n3(int N, double *result, double *A, double *B){

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[N*i + j] = 0;
            for (int k = 0; k < N; k++)
            {
                result[N * i + j] += A[N * i + k] * B[N * k + j];
            }
            
        }
    }
}

void matmul_nlog7(int N, double *result, double *A, double *B){


}



int main(){
    const int N = 16;
    int k = (int) (log(N) / log(2)) - 4;
    int m = 1 + (int) (N * pow(2, -k));
    int new_N = m * pow(2, k);
    printf("New_N = %d %d %d\n", new_N, k, m);

    double *A = malloc(new_N * new_N * sizeof(double));
    double *B = malloc(new_N * new_N * sizeof(double));

    double *result = malloc((N * N) * sizeof(double));

    // matmul_n3(N, result, A_old, B_old);


    const gsl_rng_type *T;
    gsl_rng *r;
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc(T);
    gsl_rng_set(r, time(NULL)); // Seed with current time


    for (int i = 0; i < new_N; i++)
    {
        for (int j = 0; j < new_N; j++)
        {
            if ((i < N) && (j < N))
            {
                A[i*new_N + j] = gsl_rng_uniform(r) * 10.0 - 5.0;
                B[i*new_N + j] = gsl_rng_uniform(r) * 10.0 - 5.0;
                
            }else {
                A[i*new_N + j] = 0;
                B[i*new_N + j] = 0;
            }
        }
    }
    
    mat_print(new_N, A);

    // Free allocated memory
    gsl_rng_free(r);

}