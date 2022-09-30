#ifndef CL_FUN_OVER_CPP_
#define CL_FUN_OVER_CPP_

#include "tl.h"
#include <iostream>

std::string rs(std::string val)
    {return val;}

class TestInput
{
    private:
        
    public:
        TestInput();
        TestInput(int x, double y){this->x=x; this->y=y;}
        virtual ~TestInput() {}
        virtual void print_val(void);
        void set_vars(int x, double y){this->x=x; this->y=y;}
    protected:
        int     x;
        double  y;
};

TestInput::TestInput()
    { this->x=0; this->y=0.0;}

void TestInput::print_val(void)
    { std::cout << "x=" << x << " ; y=" << y << std::endl;}

#endif
