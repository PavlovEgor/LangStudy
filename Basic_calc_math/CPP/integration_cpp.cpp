#include <iostream>
#include <vector>
#include <string>
#include <math.h>


class Integration
{
private:
    double (*function)(double);
    double a;
    double b;
    int N;
    double *mesh;

    void uniform_mesh(){
        int i;
	    for (i = 0; i < N; ++i){
		    mesh[i] = a + i * (b - a) / (N-1);
	    }
    }

public:
    Integration(int N_, double (*function_)(double), double a_=0, double b_=1);
    ~Integration();

    double Boole_integral();
    double trapezoidal_integral();
    double Simpson_1_3_integral();
    double Simpson_3_8_integral();
    double rectangle_right_integral();
    double rectangle_left_integral();

};


Integration::Integration(int N_, double (*function_)(double), double a_, double b_){
    N = N_;
    mesh = new double [N];
    a = a_;
    b = b_;
    function = function_;

    uniform_mesh();
}


Integration::~Integration(){
    delete mesh;
}


double Integration::Boole_integral(){
	int i;
	double discrete_sum = 0;
	double x_0, h;
	for (i = 0; i < N-1; ++i){
		h = (mesh[i+1] - mesh[i]) / 4;
		x_0 = mesh[i];
		discrete_sum += 2 * h * (7 * function(x_0) + 
								32 * function(x_0 + h) + 
								12 * function(x_0 + 2 * h) + 
								32 * function(x_0 + 3 * h) +
								7  * function(x_0 + 4 * h)) / 45 ;
	}

	return discrete_sum;
}


double Integration::trapezoidal_integral(){
	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * (function(mesh[i+1]) + function(mesh[i])) / 2.0 ;
	}

	return discrete_sum;
}


double Integration::Simpson_1_3_integral(){
	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * (function(mesh[i+1]) + 
												function(mesh[i]) + 
												4 * function((mesh[i+1] + mesh[i]) / 2)) / 6.0 ;
	}

	return discrete_sum;
}


double Integration::Simpson_3_8_integral(){
	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * (function(mesh[i+1]) + 
												function(mesh[i]) + 
												3 * function((2 * mesh[i+1] + mesh[i]) / 3) + 
												3 * function((mesh[i+1] + 2 * mesh[i]) / 3) ) / 8.0  ;
	}

	return discrete_sum;
}


double Integration::rectangle_right_integral(){

	int i;
	double discrete_sum = 0;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * function(mesh[i+1]);
	}

	return discrete_sum;
}


double Integration::rectangle_left_integral(){

    int i;
	double discrete_sum;
	for (i = 0; i < N-1; ++i){
		discrete_sum += (mesh[i+1] - mesh[i]) * function(mesh[i]);
	}

	return discrete_sum;
}

double f(double x){
	return sin(x);
}


int main(){

    using namespace std;

    const int N = 1000;
    const double pi = 3.14159265358979323846;
    Integration simple_integral = Integration(N, f, 0.0, pi);

    cout.precision(16);

    cout << "Rectangle method " << simple_integral.rectangle_left_integral() << endl;
    cout << "Trapezoidal rule " << simple_integral.trapezoidal_integral() << endl;
    cout << "Simpson 1/3 rule " << simple_integral.Simpson_1_3_integral() << endl;
    cout << "Simpson 3/8 rule " << simple_integral.Simpson_3_8_integral() << endl;
    cout << "Boole rule       " << simple_integral.Boole_integral() << endl;

    return 0;
}