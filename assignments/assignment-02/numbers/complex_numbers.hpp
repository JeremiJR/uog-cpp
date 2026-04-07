#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

#include <iostream>

class ComplexNumber {
protected:
    double re;
    double im;

public:
    // Functions defined inside the class body are implicitly 'inline'
    ComplexNumber(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    ComplexNumber& operator=(const ComplexNumber& other) {
        if (this != &other) {
            re = other.re;
            im = other.im;
        }
        return *this;
    }

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(re + other.re, im + other.im);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(
            re * other.re - im * other.im,
            re * other.im + im * other.re
        );
    }

    ComplexNumber pow(int n) const {
        ComplexNumber result(1.0, 0.0);
        for (int i = 0; i < n; ++i) {
            result = result * (*this);
        }
        return result;
    }

    // Friend functions must be defined inside the class or marked 'inline'
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
        if (cn.re != 0 && cn.im > 0)
            os << cn.re << " + " << cn.im << "i";
        else if (cn.re != 0 && cn.im < 0)
            os << cn.re << " - " << -cn.im << "i";
        else if (cn.re == 0 && cn.im != 0)
            os << cn.im << "i";
        else
            os << cn.re;
        return os;
    }
};

class RealNumber : public ComplexNumber {
public:
    RealNumber(double r) : ComplexNumber(r, 0.0) {}
};

#endif // COMPLEX_NUMBER_HPP