#ifndef TEST_CL_HPP_
#define TEST_CL_HPP_

#include <iostream>
#include "nbt.h"

int str_len(const char* txt){
        int i = 0;
        while(*txt){
            txt++;
            i++;
        }
        return i;
}

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

class CL_CSTR{
  private:
    int     x;
    char*   c_str;
    double  y;
    public:
      CL_CSTR(){}
      CL_CSTR(int a, const char* input, double b);
      virtual ~CL_CSTR();
      virtual void print_var(void);
};

CL_CSTR::CL_CSTR(int a, const char* input, double b){
  this->x = a;
  this->c_str = new char[str_len(input)];
  strcpy(this->c_str, input);
  this->y = b;
}

CL_CSTR::~CL_CSTR(){
  //delete [] this->c_str;
  //this->c_str = nullptr;
}

void CL_CSTR::print_var(){
  std::cout<< "Int :" << this->x << " | CStr :" << this->c_str << 
  "| Doub : " << this->y <<std::endl;
}

#endif