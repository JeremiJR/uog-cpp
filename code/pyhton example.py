import math
import numpy as np
import matplotlib.pyplot as plt
import sympy as sp

def fixed_point(g, x0, niters=1000, tol=1e-6):
    """
    Fixed-point iteration method
    """
    xold = x0
    for iter in range(niters):
        xnew = g(xold)
        if abs(xnew - xold) < tol:
            print(f"Solution converges at iteration step {iter+1}")
            return xnew
        
        xold = xnew 
    
    print(f"Warning: Method did not converge within the maxinum number of iterations")


def g(x):
    return 0.5 * (x + 5 / x)

sqrt_of_five = fixed_point(g, 2.0)
print(f"sqrt(5)            = {sqrt_of_five}")
print(f"sqrt(5) using math = {math.sqrt(5)}")