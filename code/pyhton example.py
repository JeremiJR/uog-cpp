import math
import numpy as np
import matplotlib.pyplot as plt
import sympy as sp

def f(x):
    return math.exp(-0.1 * x) * math.sin(2 * x)

def df(x):
    exp_term = math.exp(-0.1 * x)
    trig_term = (2 * math.cos(2 * x)) - (0.1 * math.sin(2 * x))
    return exp_term * trig_term

def newton_raphson(func, dfunc, x0, niters=100, tol=1e-6):
    xold = x0
    for iter in range(niters):

        fval = func(xold)
        dfval = dfunc(xold)
        if abs(dfval) < 1e-15:
            print(f"Divergence: Derivative is zero at x = {xold} at iteration {iter}")
        xnew = xold - fval / dfval

        if abs(xnew - xold) < tol:
            print(f"Solution converges at step {iter + 1}")
            return xnew
        
        xold = xnew

    print(f"Divergence: Root not found within the defined number of iterations and tolerance")

x = np.linspace(0, 10, 1000)
h = np.exp(-0.1 * x) * np.sin(2 * x)
plt.plot(x, h, x, np.zeros_like(x))
plt.show()