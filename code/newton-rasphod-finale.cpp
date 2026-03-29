#include <iostream>
#include <cmath>

// Math step called by fl
double f(double l) 
{
    return exp(-0.1 * l) * sin(2 * l);   
}
// Derivative part called by df
double df(double l) 
{
    double ex_t = exp(-0.1 * l);
    double tri_t = (2 * cos(2*l) - (0.1 * sin(2*l)));
    return ex_t * tri_t;
}

void newt(double x0) 
{
    // Defining value and 
    double tol = 1e-6;
    int n = 10000;
    int nc = 0;
    double xold = x0;
    for (int k = 0; k < n; k++) 
    {
        
        double fval = f(xold);
        double dfval = df(xold);
        if (abs(dfval) < 1e-15) 
        {
            std::cout << "Divergence: Derivative is zero at" << xold << "at iteration" << nc;
            break;
        }

        double xnew = xold - fval/dfval; 
        
        if (abs(xnew - xold) < tol)
        {
            std::cout << "done at " << nc + 1 << " iterations. Root: " << xnew;
            break;
        }
        xold = xnew;
        nc++;
    }
}


// Initialises the function
int main() 
{
    
    //f(10.0);
    
    newt(1.5*8);
    return 0;
}
