#include <iostream>
#include <complex>
#include <cmath>

const double PI = 3.14159265358979323846;


class Fourier_transform
{
private:
    bool invert;
    std::complex<double>* X;
    int N;

public:
    Fourier_transform(int _N, std::complex<double>* input, bool _invert=false){
        X = input;
        N = _N;
        invert = _invert;
    }

    ~Fourier_transform(){}

    void dft(std::complex<double>*output);
};

void Fourier_transform::dft(std::complex<double>*output){
    if (invert == false){
        for (int i = 0; i < N; i++)
        {
            output[i] = 0;
            for (int j = 0; j < N; j++)
            {
                output[i] += X[j] * (cos((2 * PI * j * i) / N) - i * sin((2 * PI * j * i) / N));
            }
            output[i] = output[i] * (1.0 / N);
        }
    } else {
        for (int i = 0; i < N; i++)
        {
            output[i] = 0;
            for (int j = 0; j < N; j++)
            {
                output[i] += X[j] * (cos((2 * PI * j * i) / N) + i * sin((2 * PI * j * i) / N));
            }
        }
    }
}

int main(){
    using namespace std;

    const int N = 10;
    complex<double>* X = new complex<double> [N];
    complex<double>* Y = new complex<double> [N];

    for (int i = 0; i < N; i++)
    {
        X[i] = sin((2 * PI * i) / N);
    }

    Fourier_transform dft_my = Fourier_transform(N, X);
    dft_my.dft(Y);

    for (int i = 0; i < N; i++)
    {
        cout << Y[i] << endl;
    }
    
    return 0;
}