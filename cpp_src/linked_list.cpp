//#include "../ll_head/tl.h"
#include "../nbt/nbt.h"
#include <iostream>

class Der: public TestInput 
{
  public:
    int     a {};
    char    b {};
    virtual void    print_val(){std::cout << "Der val:"<< a << "  " << b << "!" << std::endl;}
    Der(int v1, char v2): a{v1}, b{v2} {}
    Der() {}
    virtual ~Der() {}
};

int main()
{
  nbt::LinkedList   Obj1;

  std::cout<<"START\n\n";
  Obj1.push_forword(123);
  Obj1.push_back(rs("Test text"));
  Obj1.print_ll();
  Obj1.push_back('F');
  Obj1.push_forword(rs("FRST"));

  Obj1.print_ll();

  nbt::ClassData<int>* retObj = (nbt::ClassData<int>*)Obj1[1];
  std::cout << "Ret obj = " << retObj->val << std::endl;
  std::cout << "N[] =" << Obj1[3] << std::endl;
  Obj1.l_insert(0, 987);

  Obj1.print_ll();

  
  char* p = new char[sizeof(Der)];
  Der* ap = new (p) Der(456, 'Q');
  Obj1.push_back(p);

  /*  
  Der                 inObj(546, 'Q');
  Obj1.push_back(inObj); inObj.~Der();*/
  Obj1.print_ll();
  std::cout<< "Len  " << Obj1.ll_length() << std::endl;

  //nbt::ClassData<Der>* outObj = (nbt::ClassData<Der>*)Obj1[5];
  //Der outClass;
  //outObj->val.print_val();
  char* b = new char[sizeof(nbt::ClassData<Der>)];
  b = (char*)(nbt::ClassData<Der>*)Obj1[5];
  nbt::ClassData<Der>* outObj = (nbt::ClassData<Der>*)b;
  //Der ttmmmpp = (Der)outObj->val;
  outObj->val.print_val();
  
  //outClass.print_val();

  std::cout<< "Finished\n";

  return 0;
}
