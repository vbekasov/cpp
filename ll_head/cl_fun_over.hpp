#ifndef CL_FUN_OVER_HPP
#define CL_FUN_OVER_HPP

#include <iostream>

std::string rs(std::string val)
    {return val;}

class TestInput
{
    private:
        int     x;
        double  y;
    public:
        TestInput();
        TestInput(int a, double b);
        ~TestInput() {}
        void print_xy(void);
        void set_vars(int x, double y){this->x=x; this->y=y;}
};

TestInput::TestInput()
    { this->x=0;this->y=0.0;}

TestInput::TestInput(int x, double y)
    { this->x=x;this->y=y;}

void TestInput::print_xy(void)
    { std::cout << "x=" << x << " ; y=" << y << std::endl;}

#endif
