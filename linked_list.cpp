#include "ll_head/tl.h"

int main()
{
    ll::LinkedList   Obj1;
    std::string tmp = "SOME TEST TEXT";
    Obj1.write_class(tmp);
    Obj1.print_val();

    return 0;
}
