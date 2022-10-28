//#include "../ll_head/tl.h"
#include "../nbt/nbt.h"
#include <iostream>

class Der 
{
  public:
    char    a;
    int     b;
    virtual void    print_val(){std::cout << "Der val: "<< a << "  " << b << "!" << std::endl;}
    Der(char v1, int v2): a{v1}, b{v2} {}
    Der() {}
    virtual ~Der() {}
    void ret_a(){ std::cout<< "Text\n";}
};

int main()
{
  nbt::LinkedList   Obj1;

  std::cout<<"START\n\n";
  //Obj1.push_forword(123);
  //Obj1.push_back(rs("Test text"));
  //Obj1.print_ll();
  //Obj1.push_back('F');
  //Obj1.push_forword(rs("FRST"));


/*
  nbt::ClassData<int>* retObj = (nbt::ClassData<int>*)Obj1[1];
  std::cout << "Ret obj = " << retObj->val << std::endl;
  std::cout << "N[] =" << Obj1[3] << std::endl;
  Obj1.l_insert(0, 987);

  Obj1.print_ll();

  
  char* p = new char[sizeof(Der)];
  Der* ap = new (p) Der('Q', 456);
  ap->print_val();
  ap->~Der();
  delete [] p;
*/
  Der tp('Q', 456);
  Obj1.push_back(tp);
  Obj1.print_ll();
  //nbt::ClassData<Der>* tt = (nbt::ClassData<Der>*)Obj1[5];
  //tt->val.ret_a();
  void* dd = Obj1[5];
  Der* ww = (Der*)dd;
  //ww->print_val();
  ww->a = 'O';


  std::cout<< "Finished\n";

  return 0;
}
