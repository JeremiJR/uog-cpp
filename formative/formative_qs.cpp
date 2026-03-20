#include <iostream>


class ComplexNumber
{
    private:
    int re = 0;
    int im = 0;

    public:
    ComplexNumber(int r, int i) : re(r), im(i){
        std::cout <<"l"<< std::endl;
    }
    

};

int main()
{
    ComplexNumber w {1,2};
}