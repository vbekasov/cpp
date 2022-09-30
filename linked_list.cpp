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
    Obj1.push_forword(rs("FRST"));

    Der             InObj(876, 'Q');
    Obj1.push_forword(InObj);
    InObj.~Der();

    Obj1.print_ll();
    Der            OutObj;
    OutObj = Obj1.ret_object<Der>();
    OutObj.print_val();
    OutObj.~Der();

    return 0;
}
