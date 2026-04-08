#ifndef POLY1D_HPP
#define POLY1D_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

namespace math {
    template <typename T>
    class Poly1D {
    private:
        // Coefficients stored from highest degree to lowest (NumPy style)
        // [1, 2, 3] -> 1x^2 + 2x + 3
        std::vector<T> coeffs;

    public:
        Poly1D(std::vector<T> c) : coeffs(c) {
            // Remove leading zeros to maintain correct degree
            auto it = coeffs.begin();
            while (it != coeffs.end() - 1 && *it == 0) {
                it = coeffs.erase(it);
            }
        }

        // Degree of the polynomial
        int degree() const {
            return coeffs.empty() ? 0 : static_cast<int>(coeffs.size()) - 1;
        }

        // Evaluation using Horner's Method: p(x) = (...((a_n*x + a_{n-1})*x + a_{n-2})...)
        double operator()(double x) const {
            double result = 0.0;
            for (double c : coeffs) {
                result = result * x + c;
            }
            return result;
        }

        // Derivative: if P(x) = ax^2 + bx + c, P'(x) = 2ax + b
        Poly1D derive() const {
            if (coeffs.size() <= 1) return Poly1D({0.0});
            std::vector<double> d_coeffs;
            int n = degree();
            for (int i = 0; i < n; ++i) {
                d_coeffs.push_back(coeffs[i] * (n - i));
            }
            return Poly1D(d_coeffs);
        }

        // Addition
        Poly1D operator+(const Poly1D& other) const {
            int max_size = std::max(coeffs.size(), other.coeffs.size());
            std::vector<double> res(max_size, 0.0);
            
            for (int i = 0; i < max_size; ++i) {
                int idx1 = coeffs.size() - 1 - i;
                int idx2 = other.coeffs.size() - 1 - i;
                if (idx1 >= 0) res[max_size - 1 - i] += coeffs[idx1];
                if (idx2 >= 0) res[max_size - 1 - i] += other.coeffs[idx2];
            }
            return Poly1D(res);
        }

        // Subtraction
        Poly1D operator-(const Poly1D& other) const {
            int max_size = std::max(coeffs.size(), other.coeffs.size());
            std::vector<double> res(max_size, 0.0);
            
            for (int i = 0; i < max_size; ++i) {
                int idx1 = coeffs.size() - 1 - i;
                int idx2 = other.coeffs.size() - 1 - i;
                if (idx1 >= 0) res[max_size - 1 - i] += coeffs[idx1];
                if (idx2 >= 0) res[max_size - 1 - i] -= other.coeffs[idx2];
            }
            return Poly1D(res);
        }

        // Multiplication
        Poly1D operator*(const Poly1D& other) const {
            std::vector<double> res(degree() + other.degree() + 1, 0.0);
            for (size_t i = 0; i < coeffs.size(); ++i) {
                for (size_t j = 0; j < other.coeffs.size(); ++j) {
                    res[i + j] += coeffs[i] * other.coeffs[j];
                }
            }
            return Poly1D(res);
        }

        // Output formatting
        friend std::ostream& operator<<(std::ostream& os, const Poly1D& p) {
            int n = p.degree();
            for (size_t i = 0; i < p.coeffs.size(); ++i) {
                int pwr = n - i;
                double c = p.coeffs[i];
                if (c == 0 && n > 0) continue;
                
                if (i > 0 && c > 0) os << " + ";
                if (c < 0) os << " - ";
                
                double abs_c = std::abs(c);
                if (abs_c != 1 || pwr == 0) os << abs_c;
                
                if (pwr > 0) os << "x";
                if (pwr > 1) os << "^" << pwr;
            }
            return os;
        }

        double find_root(double x0, double tol = 1e-6, int max_iter = 500) const {
            
            double x = x0;
            Poly1D p_prime = this->derive();
            
            for (int i = 0; i < max_iter; ++i) {
                double fx = this->operator()(x);
                double fpx = p_prime(x);
                
                if (std::abs(fpx) < 1e-12) break; // Avoid division by zero
                
                double x_next = x - fx / fpx;
                if (std::abs(x_next - x) < tol) return x_next;
                x = x_next;
            }
            return x;
        }
};

    template <typename T>
    // Newton's Method solver
    double find_root(const Poly1D<T>& p, double x0, double tol = 1e-6, int max_iter = 500) {
        return p.find_root(x0, tol, max_iter);
    }

} // namespace mathcpp

#endif