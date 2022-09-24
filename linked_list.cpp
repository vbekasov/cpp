#include "ll_head/tl.h"

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

    return 0;
}
