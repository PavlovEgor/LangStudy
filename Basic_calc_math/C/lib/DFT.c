#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define n 10
#define PI 3.14159265358979323846


void dft(int N, double complex* func, double complex* F_func, int invert){
    if (invert == 1)
    {
        /* code */
    }
    
    for (int i = 0; i < N; i++)
    {
        F_func[i] = 0;
        for (int j = 0; j < N; j++)
        {
            F_func[i] += func[j] * (cos((2 * PI * j * i) / N) - I * sin((2 * PI * j * i) / N));
        }
        // F_func[i] = F_func[i] / N;
    }

    if (invert == -1){
        for (int i = 0; i < N; i++)
        {
            F_func[i] = F_func[i] / N;
        }
        
    }
}


int main(){

    double complex* input = malloc(n * sizeof(double complex));
    // double complex input[] = {0, 0.3, 0.6, 0.8, 1, 1, 0.9, 0.7, 0.5, 0.2, 0.2, 0.5, 0.7, 0.9, 1, 1, 0.8, 0.6, 0.3, 0};

    double complex* output = malloc(n * sizeof(double complex));

    for (int i = 0; i < n; i++)
    {
        input[i] = sin((2 * PI * i) / n);
    }
    
    dft(n, input, output, 1);

    for (int i = 0; i < n; i++)
    {
        printf("%.2f + %.2fi\n", creal(output[i]), cimag(output[i]));
    }
    
    return 0;
}