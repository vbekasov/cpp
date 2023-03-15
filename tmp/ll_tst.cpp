#include <iostream>
#include "ll.hpp"

int main(){
    nbt::LL LiL;

    LiL.add_node(5);
    LiL.add_node(123.87);
    LiL.print();

    std::cout<< "LL finished\n";

    return 0;
}
