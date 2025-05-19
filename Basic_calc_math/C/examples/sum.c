#include <stdio.h>

#define M_PI 3.14159265358979323846

int main(){
    const long int N = 1000000;
    const long double one = 1.0;
    long double S1 = 0, S2 = 0;

    for (long int i = 1; i <= N; i++)
    {
        S1 += one / (i * i);
        S2 += one / ((N + 1 - i) * (N + 1 - i));
    }
    
    printf("%3.20Lf\n%3.20Lf\n%3.20f\n", S1, S2, M_PI * M_PI / 6);

}