#include "ll_head/tl.h"

class Der: public TestInput 
{
    public:
        int     a {};
        char    b {};
        virtual void    print_val(){std::cout << "Der val:"<< a << "  " << b << "!" << std::endl;}
        Der(int v1, char v2): a{v1}, b{v2} {}
        Der() {}
        virtual ~Der() {}
};

int main()
{
    ll::LinkedList   Obj1;
    Obj1.push_back(123);
    Obj1.push_back(rs("Test text"));
    Obj1.print_ll();
    Obj1.push_back('F');
    Obj1.push_forword(rs("FRST"));

    Obj1.print_ll();

    return 0;
}
