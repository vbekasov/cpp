#ifndef ST_NS_HPP_
#define ST_NS_HPP_

#include <string>

namespace nbt
{
  // BEFORE COMPILE FOR .SO REMOVE FLAGS and ++

  char    ret_type(int* v)
    {return 'I';}
  char    ret_type(double* v)
    {return 'D';}
  char    ret_type(std::string* v)
    {return 'S';}
  char    ret_type(char* v)
    {return 'C';}
  char    ret_type(auto* v)
    {return 'O';}

  struct  st_node
  {
    char      et;
    //char*     obj_cont;
    void*     obj_cont;
    st_node*  next;
    ~st_node()
    {
      if (obj_cont && et != '+') 
      { 
        //delete [] obj_cont;
        obj_cont = nullptr;
      }
      next = nullptr;
    }
    void    set_type(auto *tt)
    {
      et = ret_type(tt);
    }
  };
}

#endif
