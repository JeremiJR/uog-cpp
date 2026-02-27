#include <iostream>
#include <cmath>
using namespace std;
// Fixed-point and Newton-Raphson methods for solving nonlinear equation
// Fixed Point - Iteration method
// Almost did this code translation first time but i tried to make an vector(array) of values for it to cylce through of going 1-10000 as a 'iter' copy of the function in the for loop... it didnt work.

// This function just does the maths step. Called by g()
double g(double y) {
    return 0.5 * (y + 5.0 / y);
    
}

double fl(double l) {
    return exp(-0.1 * l) * sin(2 * l);   
}

double df(double l) {
    double ex_t = exp(-0.1 * l);
    double tri_t = (2 * cos(2*l) - (0.1 * sin(2*l)));
    return ex_t * tri_t;
}

void newt(double x0) {
    double tol = 1e-6;
    int n = 10000;
    int nc = 0;
    double xold = x0;
    for (int k = 0; k < n; k++) {
        
        double fval = fl(xold);
        double dfval = df(xold);
        if (abs(dfval) < 1e-15) {
            cout << "Divergence: Derivative is zero at" << xold << "at iteration" << nc << endl;
            break;
        }

        double xnew = xold - fval/dfval; 
        
        if (abs(xnew - xold) < tol) {
            cout << "done at " << nc + 1 << " iterations. Root: " << xnew << endl;
            break;
        }
        xold = xnew;
        nc++;
    }
    //cout << "didnt work" << endl;
}

// This is the main void, it returns the 'cout' line, it has the loop function with a check for the value to go over the tolerance
void f(double x0){
    // Defining values and data types
     double tol = 1e-6;
     int n = 100;
     int nc = 0;
     // Resetting value
     double xold = x0;
     // This originally was a vector of going 1 to 10,000. This didnt really wrok, another idea i had was to make it a matrix and for each iter have the value given, just a 2D vector, not sure if possible.
     for (int k = 0; k < n; k++) {
        // Increment
        
        // Running through function
        double xnew = g(xold);
        if (abs(xnew - xold) < tol) { // This check's if the abs value is smaller than tolerance, if it is it breaks the loop and ends the loop with a break.
            cout << "done at " << nc + 1 << " iterations. Root: " << xnew << endl;
            break;
        }
        // If loop condition not matched, code repeats.
        xold = xnew;
        nc++;
     }
    
}

// Just initalises the function.
int main() {
    
    //f(10.0);
    
    newt(1.5*8);
    return 0;
}


// Defintely not the most amazing translation but seems to be very similar to python one, does make sense as its just following basic operations.
// Most of this code worked, i ended up using gemini to help me figure out the increment loop(felt stupid when i read it), then some basic debugging(spacing and wrong equation input things.)

///////////////////// NEWTON ////////////////////////


