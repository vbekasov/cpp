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
        ~TestInput() {}
        TestInput(int a, double b);
        void print_xy(void);
};

TestInput::TestInput()
    { x = 0; y = 0.0;}

TestInput::TestInput(int a, double b)
    { x = a; y = b;}

void TestInput::print_xy(void)
    { std::cout << "x=" << x << " ; y=" << y << std::endl;}

#endif