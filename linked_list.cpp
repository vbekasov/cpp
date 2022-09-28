#include "ll_head/tl.h"

class Der: public TestInput 
{
    public:
        int     a;
        char    b;
        void    print_val(){std::cout << "Der val:"<< a << "  " << b << "!" << std::endl;}
};

int main()
{
    ll::LinkedList   Obj1;
    Obj1.push_back(123);
    Obj1.push_back(rs("Test text"));
    Obj1.push_forword(rs("FRST"));

    Obj1.print_ll();

    return 0;
}
