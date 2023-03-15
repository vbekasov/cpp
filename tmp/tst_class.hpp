#ifndef TST_CLASS_HPP
#define TST_CLASS_HPP

#include <iostream>
#include <cstring>
#include <string>
//#include <string.h>

class TstC{
    private:
        int    a;
        double b;
    public:
        TstC(int A, double B): a(A), b(B) {};
        TstC(){};
        ~TstC(){};
        friend std::ostream& operator<<(std::ostream& os, const TstC& dt);
};

std::ostream& operator<<(std::ostream& os, const TstC& dt){
    os<< "TstC Obj;Int=" << dt.a << " |Dou=" << dt.b;
    return os;
}

class TstC1{
    private:
        double  d[5];
        char*   carr;
    public:
        TstC1();
        friend  std::ostream& operator<<(std::ostream& os, const TstC1& dt);
        TstC1*  ret_this();
};

TstC1::TstC1(){
    for (int i=0; i < 5; i++)
        this->d[i] = i * 1.12;
    
    this->carr = new char[8];
    strcpy(carr, "Obj TXT");
}

std::ostream& operator<<(std::ostream& os, const TstC1& dt){
    std::string str;
    str = "Str=";
    str += dt.carr;
    str += "| Darr=";
    for (int i=0; i < 5; i++){
        str += std::to_string(dt.d[i]);
        str += '|';
    }
    os<< str;
    return os;
}

TstC1* TstC1::ret_this(){
    std::cout<< "Ret TstC1\n";
    std::cout<< this->carr[1] << std::endl;

    return this;
}

#endif
