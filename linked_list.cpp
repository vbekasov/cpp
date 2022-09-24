#include "ll_head/tl.h"

class Der: public TestInput 
{
    public:
        int     a;
        char    b;
        void    print_val(){std::cout << a << b << std::endl;}
};

int main()
{
    ll::LinkedList   Obj1;
    Obj1.write_class(123);
    Obj1.print_val();

    Obj1.write_class('Q');
    Obj1.print_val();

    Obj1.write_class(123.445);
    Obj1.print_val();

    Obj1.write_class(rs("TEST TEXT"));
    Obj1.print_val();

    TestInput       TObj(3, 434.54);
    Obj1.write_class(TObj);
    Obj1.print_val();

    Der             DObj; DObj.a = 876; DObj.b = 'U';
    Obj1.write_class(DObj);
    //Obj1.print_val();
    Der            Ocpy;
    Ocpy = Obj1.ret_object<Der>();
    Ocpy.print_val();

    return 0;
}
