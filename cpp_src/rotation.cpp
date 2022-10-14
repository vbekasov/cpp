#include <iostream>
#include "../nbt/nbt.h"

int main(void){
  mkdir("data", 0777);
  chdir("data");

  nbt::Rot Obj1;
  Obj1.one_step();
  Obj1.in_put();

    return 0;
}