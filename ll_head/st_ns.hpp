#ifndef ST_NS_HPP_
#define ST_NS_HPP_

#include "cl_fun_over.hpp"
#include <string>

namespace ll
{   
    // can be overloaded by user
    
    char    ret_type(int* v)
        {v++; return 'I';}

    char    ret_type(double* v)
        {v++; return 'D';}

    char    ret_type(std::string* v)
        {v++; return 'S';}

    char    ret_type(char* v)
        {v++; return 'C';}
    
    char    ret_type(auto* v)
        {v = nullptr; return 'O';}

    struct  st_node
    {
        char*   obj_cont;
        char    et;
        st_node*   next;
        void    set_type(auto tt)
        {
            et = ret_type(&tt);
        }
    };
}

#endif
