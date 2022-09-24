#ifndef CL_FUN_OVER_HPP
#define CL_FUN_OVER_HPP

#include <iostream>

std::string rs(std::string val)
    {return val;}

class TestInput
{
    private:
        
    public:
        TestInput();
        TestInput(int x, double y){this->x=x; this->y=y;}
        ~TestInput() {}
        void print_xy(void);
        void set_vars(int x, double y){this->x=x; this->y=y;}
    protected:
        int     x;
        double  y;
};

TestInput::TestInput()
    { this->x=0; this->y=0.0;}

void TestInput::print_xy(void)
    { std::cout << "x=" << x << " ; y=" << y << std::endl;}

#endif
