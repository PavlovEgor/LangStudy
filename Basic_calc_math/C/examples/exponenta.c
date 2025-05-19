#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <gmp.h>


#ifndef MIN
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#endif

#ifndef MAX
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#endif

typedef struct BigInteger
{
    unsigned int len;
    unsigned int base;
    uint64_t* data; 
};

void zero(struct BigInteger* A, unsigned int len, unsigned int base){
    uint64_t* data = malloc(len * sizeof(uint64_t));

    for (int i = 0; i < len; i++)
    {
        data[i] = 0;
    }

    A -> len = len;
    A -> base = base;
    A -> data = data;
}

void print_BigInteger(struct BigInteger* A){
    for (int i = (A -> len) - 1; i >= 0; i--)
    {
        printf("%ld", A -> data[i]);
    }
    printf("\n");

}

void create_from_int(struct BigInteger* A, unsigned int n, unsigned int base){
    unsigned int len = 1 + log(n) / log(base);
    uint64_t* data = malloc(len * sizeof(uint64_t));
    unsigned int tmp = n;
    unsigned int base_pow;
    int j;

    for (int i = 0; i < len; i++)
    {           
        data[i] = tmp % base;
        tmp -= data[i];
        tmp /= base;
    }

    A -> len = len;
    A -> base = base;
    A -> data = data;

}

void copy_BigInteger(struct BigInteger* to, struct BigInteger* from){
    to -> len = from -> len;
    to -> base = from -> base;
    to -> data = from -> data;
}

void sum(struct BigInteger* c, struct BigInteger* a, struct BigInteger* b){

    zero(c, MAX(a -> len, b -> len) + 1, a -> base);

    uint64_t tmp;

    for (int i = 0; i < (c -> len)-1; i++)
    {
        if ((i < (a -> len)) && (i < (b -> len))){
            tmp = (a -> data[i]) + (b -> data[i]);
            if (tmp + (c -> data[i]) < (c -> base)){
                c -> data[i] += tmp;
            } else {
                c -> data[i] += tmp - (c -> base);
                c -> data[i + 1] += 1;
            }
        } else if ((i >= (a -> len)) && (i < (b -> len)))
        {
            tmp = (b -> data[i]);
            if (tmp + (c -> data[i]) < (c -> base)){
                c -> data[i] += tmp;
            } else {
                c -> data[i] += tmp - (c -> base);
                c -> data[i + 1] += 1;
            }
        } else if ((i < (a -> len)) && (i >= (b -> len)))
        {
            tmp = (a -> data[i]);
            if (tmp + (c -> data[i]) < (c -> base)){
                c -> data[i] += tmp;
            } else {
                c -> data[i] += tmp - (c -> base);
                c -> data[i + 1] += 1;
            }
        }

    }

    if (c -> data[(c -> len) - 1] == 0){
        c -> len -= 1;
    }
}

void prod(struct BigInteger* c, struct BigInteger* a, struct BigInteger* b){

    zero(c, (a -> len) + (b -> len), a -> base);

    uint64_t tmp;
    struct BigInteger tmp_BI, c_next;
    

    for (int i = 0; i < (a -> len); i++)
    {
        for (int j = 0; j < (b -> len); j++)
        {
            tmp = (a -> data[i]) * (b -> data[j]);

            create_from_int(&tmp_BI, tmp, c->base);

            uint64_t* data = malloc(((tmp_BI.len) + (i + j)) * sizeof(uint64_t));

            for (int k = 0; k < ((tmp_BI.len) + (i + j)); k++)
            {
                if (k < (i + j)){
                    data[k] = 0;
                } else {
                    data[k] = tmp_BI.data[k - (i + j)];
                }
            }
            tmp_BI.len += (i + j);

            // free(tmp_BI.data);
            tmp_BI.data = data;

            sum(&c_next, c, &tmp_BI);
            // free(c);
            copy_BigInteger(c, &c_next);
        }
    }
    
    int ind = c -> len;

    while (c -> data[ind--] != 0)
    {
        c -> len -= 1;
    }
    
}






mpz_t my_fact(int* pn){
    mpz_t result = 1;
    for (int i=1; i <= *pn; ++i){
        result *= i;
    }

    return result;
}

double my_pow(double* px, int*pn){
    double result = 1;
    int i = 0;
    while (++i <= *pn)
    {
        result *= *px;
    }
    return result;
}

double my_exp(double x, int n){
    double result = 0;

    for (int i = 0; i < n; i++)
    {
        result += my_pow(&x, &i) / my_fact(&i);
    }
    return result;
    
}
int main(){
    int n1 = 5;
    int n2 = 99999;

    double x = 2.0;

    printf("%d\n", my_fact(&n1));


    // struct BigInteger A, B, C;
    // create_from_int(&A, n1, 10);
    // create_from_int(&B, n2, 10);

    // prod(&C, &A, &B);

    // for (int i = 10; i < 30; i++)
    // {
    //     printf("%d %ld\n", i, my_fact(&i));
    // }

    // print_BigInteger(&C);   
    // printf("%d\n", n1 * n2);
    // printf("%3.8f\n", my_pow(&x, &n));

    // printf("%3.16f\n%3.16f\n", my_exp(x, 20), exp(x));


}