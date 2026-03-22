#include <iostream>


class ComplexNumber
{
    private:
    double re = 0;
    double im = 0;

    public:
    ComplexNumber(double re=0, double im=0) :
     re(re), im(im){
    }
    

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& comp_num)
    {   
        bool no_im = (comp_num.im == 0);
        bool no_re = (comp_num.re == 0);
        if (no_im && no_re)
        {
            return os << "no solution";
        }
        else if (no_im)
        {
            return os << comp_num.re << "\nOnly real solutiom";
        }
        else if (no_re)
        {
            return os << comp_num.im << "i\nOnly imaginary solution";
        }
        else  
        {
            return os << comp_num.re << "+" << comp_num.im << "i";
        }
        
        return os;
    }

    friend ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) 
    {
        double re = {c1.re + c2.re};
        double im = {c1.im + c2.im};
        return ComplexNumber {re, im};
    }

    friend ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2) 
    {
        double re = {c1.re * c2.re};
        double im = {c1.im * c2.im};
        return ComplexNumber {re, im};
    }
    
    int pow(int p = 1) 
    {   
        int n
        if p % 2
        return ComplexNumber {re, im};
    }


};


int main()
{
    ComplexNumber a {2, 3};
    ComplexNumber b {2, 3};
    ComplexNumber z {}
    std::cout << a + b << "\n" << a * b << ;
    
}