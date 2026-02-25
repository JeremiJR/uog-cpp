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

// This is the main void, it returns the 'cout' line, it has the loop function with a check for the value to go over the tolerance
void f(double x0){
    // Defining values and data types
     double tol = 1e-6;
     int n = 10000;
     int nc = 0;
     // Resetting value
     double xold = x0;
     // This originally was a vector of going 1 to 10,000. This didnt really wrok, another idea i had was to make it a matrix and for each iter have the value given, just a 2D vector, not sure if possible.
     for (int k = 0; k < n; k++) {
        // Increment
        nc++;
        // Running through function
        double xnew = g(xold);
        if (abs(xnew - xold) < tol) { // This check's if the abs value is smaller than tolerance, if it is it breaks the loop and ends the loop with a break.
            cout << "done at " << nc << " iterations. Root: " << xnew << endl;
            break;
        }
        // If loop condition not matched, code repeats.
        xold = xnew;
     }
    
}

// Just initalises the function.
int main() {
    
    f(10.0);
    return 0;
}


// Defintely not the most amazing translation but seems to be very similar to python one, does make sense as its just following basic operations.
// Most of this code worked, i ended up using gemini to help me figure out the increment loop(felt stupid when i read it), then some basic debugging(spacing and wrong equation input things.)

///////////////////// NEWTON ////////////////////////

