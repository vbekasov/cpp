#include <iostream>
#include "../nbt/nbt.h"

int main(void){

    chdir("..");
    mkdir("data", 0777);
    chdir("data");

    nbt::Rot Obj1;
    Obj1.one_step();
    Obj1.in_put();

    chdir("..");

    return 0;
}