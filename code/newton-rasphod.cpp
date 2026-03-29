#include <iostream>
#include <cmath>



// Fixed-point and Newton-Raphson methods for solving nonlinear equation


/////////////////////////////////////////////////////////
///////////////////////Fixed-Point///////////////////////
/////////////////////////////////////////////////////////


// This function just does the maths step. Called by g()
double g(double y) 
{
    return 0.5 * (y + 5.0 / y);
}

/* 
This is the main void,
it returns the 'cout' line,
it has the loop function with a check if the value is to go over the tolerance.
The input is the initial guess.
*/
double iter(double x0)
{
    // Defining values and data types
     double tol = 1e-6;
     int n = 100;
     int nc = 0;
     double xold = x0;
     for (int k = 0; k < n; k++) 
     {    
        // Running through function
        double xnew = g(xold);
        if (abs(xnew - xold) < tol) { // This check's if the abs value is smaller than tolerance, if it is it breaks the loop and ends the loop with a break.
            std::cout << "done at " << nc + 1 << " iterations. Root: " << xnew;
            break;
        }
        // If loop condition not matched, code repeats.
        xold = xnew;
        // Resetting value
        nc++;
        // Increment.
     }
    return 0;
}


/////////////////////////////////////////////////////////
////////////////////Newton-Raphson///////////////////////
/////////////////////////////////////////////////////////


// This function does the maths step. Called by f().
double f(double l) 
{
    return exp(-0.1 * l) * sin(2 * l);   
}
// This function does the maths differential step. Called by df().
double df(double l) 
{
    return exp(-0.1 * l) * (2 * cos(2*l) - (0.1 * sin(2*l)));
}
/*This function uses the Newton-Raphson method,
to find the root of a nonlinear equation.
The input is the initial guess.*/
double newt(double x0) 
{   
    // Defining values and data types
    double tol = 1e-6;
    int n = 10000;
    int nc = 0;
    double xold = x0;
    // This loops over the function, checks for conditions and breaks if met.
    for (int k = 0; k < n; k++) 
    {   
        // Initalises the math steps.
        double fval = f(xold);
        double dfval = df(xold);
        // Checks if the derivative is zero.
        if (abs(dfval) < 1e-15) 
        {
            // If condition met, it breaks and spits out the divergence message.
            std::cout << "Divergence: Derivative is zero at" << xold << "at iteration" << nc;
            break;
        }
        // Main Newton-Raphson step, calculates the new value.
        double xnew = xold - fval/dfval; 
        /*Checks if the new value is within the tolerance.
        If it is, breaks and spits out the result.*/
        if (abs(xnew - xold) < tol) 
        {
            std::cout << "done at " << nc + 1 << " iterations. Root: " << xnew;
            break;
        }
        xold = xnew;
        // Resetting value
        nc++;
        // Increment
    }
    return 0;
}



// Just initalises the function.
int main() 
{
    double I = 10;
    double N = 1.5;
    std::cout << "Set the value set at " << I << "and" << iter(I) << std::endl;
    std::cout << "Set the value set at " << N << "and" << newt(1) << std::endl;
    return 0;
}


// Defintely not the most amazing translation but seems to be very similar to python one, does make sense as its just following basic operations.
// Most of this code worked, i ended up using gemini to help me figure out the increment loop(felt stupid when i read it), then some basic debugging(spacing and wrong equation input things.)




