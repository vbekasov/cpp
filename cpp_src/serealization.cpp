#include <iostream>
#include "../nbt/nbt.h"
#include "../nbt/test_cl.hpp"

int main(void){

  nbt::SContainer       wObj((char*)"ABCdefg", "data.dat");

  mkdir("data", 0777);
  chdir("data");

  wObj.save();
  wObj.add_str((char*)"XYZZZqwerty");
  wObj.save();

//------------
  nbt::SContainer       rObj;
  rObj.set_wfile("data.dat");

  rObj.read(0);
  rObj.print_var();

  rObj.read(1);
  rObj.print_var();

  rObj.read(0);
  rObj.print_var();

//-------------

  //CL1 cObj(5, 2345.235);
  char* p = new char[sizeof(CL1)];
  CL1* ap = new (p) CL1(423, 65.31);
  ap->print_var();
  wObj.add_str(p);
  wObj.save();

  rObj.read(2);
  CL1* cObj;
  cObj = (CL1*)rObj.ret_obj();
  cObj->print_var();

  ap->CL1::~CL1();
  delete [] p;

  rObj.~SContainer();

  chdir("..");

  std::cout<< "\nFinished\n";
   return 0;
}
