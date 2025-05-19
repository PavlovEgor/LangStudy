#include <iostream>


class Pentadiagonal_matrix_solver
{
private:
    int N; // size of matrix
    int k; // offset from the main diagonal


    double *first_up_diag;
    double *second_up_diag;
    double *first_down_diag;
    double *second_down_diag;


public:
    Pentadiagonal_matrix_solver(
        int _N, 
        int _k, 
        double *_first_up_diag, 
        double *_second_up_diag, 
        double *_first_down_diag, 
        double *_second_down_diag);
    ~Pentadiagonal_matrix_solver();

    void pentadiagonal_solve(double *x, double *B);
};

Pentadiagonal_matrix_solver::Pentadiagonal_matrix_solver(
    int _N, 
    int _k, 
    double *_first_up_diag, 
    double *_second_up_diag, 
    double *_first_down_diag, 
    double *_second_down_diag)
{
    N = _N;
    k = _k;

    first_up_diag = _first_up_diag;
    second_up_diag = _second_up_diag;
    first_down_diag = _first_down_diag;
    second_down_diag = _second_down_diag;
}

Pentadiagonal_matrix_solver::~Pentadiagonal_matrix_solver()
{

}

void Pentadiagonal_matrix_solver::pentadiagonal_solve(double *x, double *B){

    int i, j, l, p;
    double frac;
    double bi, ci, di, ei, tmp;

    double P[N][k];
    double R[N];

    double P2[k+1][k];
    double R2[k+1];

    R[0] = B[0];
    P[0][0] = -first_up_diag[0];
    P[0][k-1] = -second_up_diag[0];

    for (i = 1; i < k; i++)
    {
        di = first_down_diag[i];

        frac = 1 / (1 + P[i-1][0] * di);

        P[i][k-1] = - second_up_diag[i] * frac;
        for (j = 0; j < k-1; j++)
        {
            P[i][j] = - di * P[i-1][j+1] * frac;
        }
        P[i][0] += -first_up_diag[i] * frac;

        R[i] = (B[i] - di* R[i-1]) * frac;
        
    }

    for (i=k; i < N-1; i++)
    {
        
        for (j=0; j<k; j++)
        {
            P2[0][j] = 0;
            P2[1][j] = P[i-1][j];
        }

        P2[0][0] = 1;
        R2[0] = 0;
        R2[1] = R[i-1];

        for (j=2; j < k+1; j++)
        {
            for (l = 0; l < k - j + 1; l++)
            {
                P2[j][l] = P[i - j][j-1 + l];
            }
            for (l = k-j+1; l < k; l++)
            {
                P2[j][l] = 0;
            }
            
            R2[j] = R[i-j];

            for (l=1; l < j; l++)
            {
                tmp = P[i - j][j - l - 1];
                for (p=0; p < k; p++)
                {
                    P2[j][p] += tmp * P2[l][p];
                }
                R2[j] += tmp * R2[l];
            }
        }

        

        di = first_down_diag[i];
        ei = second_down_diag[i];

        frac = 1.0 / (1 + P[i-1][0] * di + P2[k][0] * ei);
        

        P[i][k-1] = - second_up_diag[i] * frac;

        
        for (j = 0; j < k-1; j++)
        {
            P[i][j] = - (di * P[i-1][j+1] + ei * P2[k][j+1]) * frac;
        }
        P[i][0] += -first_up_diag[i] * frac;

        R[i] = (B[i] - di* R[i-1] - ei * R2[k]) * frac;

    }

    for (j=0; j<k; j++)
    {
        P2[0][j] = 0;
        P2[1][j] = P[N-2][j];
    }

    P2[0][0] = 1;
    R2[0] = 0;
    R2[1] = R[N-2];

    for (j=2; j < k+1; j++)
    {
        for (l = 0; l < k - j + 1; l++)
        {
            P2[j][l] = P[N - 1 - j][j-1 + l];
        }
        for (l = k-j+1; l < k; l++)
        {
            P2[j][l] = 0;
        }
        
        R2[j] = R[N - 1 - j];

        for (l=1; l < j; l++)
        {
            tmp = P[N - 1 - j][j - l - 1];
            for (p=0; p < k; p++)
            {
                P2[j][p] += tmp * P2[l][p];
            }
            R2[j] += tmp * R2[l];
        }
    }


    di = first_down_diag[N-1];
    ei = second_down_diag[N-1];
    
    x[N-1] = (B[N-1] - di * R[N-2] - ei * R2[k]) / (1 + di * P[N-2][0] + ei * P2[k][0]);

    for (i = N-2; i > N - k - 1; i--)
    {
        x[i] = R[i];
        for (j=0; j<N - i - 1; j++)
        {
            x[i] += P[i][j] * x[i + 1 + j];
        }
    }

    for (i = N - k - 1; i >= 0; i--)
    {
        x[i] = R[i];
        for (j=0; j<k; j++)
        {
            x[i] += P[i][j] * x[i+ 1 + j];
        }
    }

}


int main(){
    int N = 10;
    int k = 3;

    double sud[10] = { 0.56838519, 0.59106732, 
                    0.60376811, 0.06784427, 
                    0.97604943, 0.68617165, 
                    0.03754737, 0., 
                    0.,         0.};

    double fud[10] = { 0.21496537, 0.23166263, 
                    0.55616111, 0.22583128, 
                    0.10656655, 0.54675014,
                    0.37189687, 0.38990937, 
                    0.98233873, 0.        };

    double fdd[10] = { 0.,         0.68343727, 
                    0.89475701, 0.5148094, 
                    0.03900925, 0.68854438,
                    0.89352028, 0.2643208,
                    0.26646279, 0.9347437 };

    double sdd[10] = { 0.,         0.,         
                    0.,         0.88109126,
                    0.62575212, 0.13503155,
                    0.30101654, 0.21706122, 
                    0.4206771,  0.10920916};

    double x[10];
    double B[10] = {0.94122422, 0.86527486, 0.66331387, 0.51497868,
                    0.69172562, 0.99599477, 0.05788199, 0.26399862,
                    0.39642472, 0.60151007};

    Pentadiagonal_matrix_solver test_matrix = Pentadiagonal_matrix_solver(N, k, fud, sud, fdd, sdd);

    test_matrix.pentadiagonal_solve(x, B);

    for (int i = 0; i < 10; i++)
    {
        printf("%3.8f ", x[i]);
    }
    printf("\n");

    printf("-1.06064525 2.14129119 -2.47122364 2.71218541 0.03613519 -0.48000190 0.02015260 -0.75710842 2.58505392 -1.81705365 \n");


    
    return 0;
}