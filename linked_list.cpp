#include "ll_head/tl.h"

int main()
{
    ll::LinkedList   Obj1;
    std::string tmp = "TTTTT";
    Obj1.write_class(123);
    Obj1.print_val();

    Obj1.write_class('Q');
    Obj1.print_val();

    Obj1.write_class(123.445);
    Obj1.print_val();

    return 0;
}
