#include <iostream>
#include <cmath>
using namespace std;
// Fixed-point and Newton-Raphson methods for solving nonlinear equation
// Fixed Point - Iteration method
double g(double y) {
    return 0.5 * (y + 5) / y;
    
}

void f(double x0){
     double tol = 1e-6;
     int n = 10000;
     int nc = 0;
     double xold = x0;
     for (int k = 0; k < n; k++)
        nc++;
        double xnew = g(xold);
        if (abs(xnew - xold) < tol) {
            cout << "done at" << nc << endl;
        }
     xold = xnew;
    
}


int main() {
    
    f(2);
}