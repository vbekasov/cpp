#include <iostream>
#include "../nbt/nbt.h"
#include "../nbt/test_cl.hpp"

int main(void){

  nbt::SContainer       wObj("ABCdefg", "data.dat");

  mkdir("data", 0777);
  chdir("data");

  wObj.save();
  wObj.add_str("XYZZZqwerty");
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
  char* p = new char[sizeof(CL1)];
  CL1* ap = new (p) CL1(423, 65.31);
  ap->print_var();

  wObj.add_obj(p, sizeof(CL1), 'O');
  wObj.save();

  std::cout<< "Obj type : " << rObj.read(2) << std::endl;
  CL1* cObj;
  cObj = (CL1*)rObj.ret_obj();
  cObj->print_var();

  ap->CL1::~CL1();
  delete [] p;
  cObj->~CL1();
  CL1* scCL1 = (CL1*)rObj.ret_obj();
  scCL1->print_var();
//-------------
  char*    o  = new char[sizeof(CL_CSTR)];
  CL_CSTR* ao = new (o) CL_CSTR(123, "UUU11111UUUUUUU", 518.73);
  //CL_CSTR tt(123, "TEEXXT");
  ao->print_var();

  wObj.add_obj(o, sizeof(CL_CSTR), 'T');
  wObj.save();
  rObj.read(3);
  CL_CSTR* tO = (CL_CSTR*)rObj.ret_obj();
  tO->print_var();

  rObj.~SContainer();
  chdir("..");

  std::cout<< "\nFinished\n";
   return 0;
}
