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
    Obj1.write_object(123);
    Obj1.print_val();

    Obj1.write_object('Q');
    Obj1.print_val();

    Obj1.write_object(123.445);
    Obj1.print_val();

    Obj1.write_object(rs("TEST TEXT"));
    Obj1.print_val();

    TestInput       TObj1(3, 434.54);
    Obj1.write_object(TObj1);
    TestInput       TObj2 = Obj1.ret_object<TestInput>();
    TObj2.print_xy();

    Der             DObj; DObj.a = 876; DObj.b = 'U';
    Obj1.write_object(DObj);
    Der            Ocpy;
    Ocpy = Obj1.ret_object<Der>();
    Ocpy.print_val();

    return 0;
}
