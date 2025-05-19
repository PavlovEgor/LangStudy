#include <stdio.h>
#include <math.h>

#define GAMMA 0.577215664901532860606512090082
#define M_PI 3.14159265358979323846

/* Find \gamma: \lim_{n \to \infty} \sum_{k=1}^n - \ln n = \gamma*/

double stupid_method(const long int* pn){
    double gamma; long double S=0;
    long double one = 1.0;

    for (int i = *pn; i > 0; i--)
    {
        S += one / i;
    }
    
    return S - log(*pn);
}


int main(){
    const long int n = 1000000000;
    printf("%3.13f\n", stupid_method(&n));
    printf("%3.13f\n", GAMMA);
    printf("%3.13f\n", (M_PI * M_PI) / 12);



}