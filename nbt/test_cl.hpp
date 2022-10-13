#ifndef TEST_CL_HPP_
#define TEST_CL_HPP_

#include <iostream>

class CL1{
  private:
    int     x;
    double  y;
  public:
    CL1(){}
    CL1(int a, double b): x(a), y(b) {};
    virtual ~CL1(){}
    virtual void print_var(void);
};

void CL1::print_var(){
  std::cout<< "Int :" << this->x << " | Doub :" << this->y << std::endl;
}

#endif