#ifndef ST_NS_HPP_
#define ST_NS_HPP_

#include <string>

namespace ll
{   
    // can be overloaded by user
    
    char    ret_type(int v)
        {v++; return 'I';}

    char    ret_type(double v)
        {v++; return 'D';}

    char    ret_type(std::string v)
        {v=""; return 'S';}
// STRING TO CHAR ARR
    char    ret_type(char v)
        {v++; return 'C';}
    
    char    ret_type(auto v)
        {v++; return 'O';}

    struct  st_node
    {
        char*   obj_cont;
        char    et;
        st_node*   next;
        void    set_type(auto tt)
        {
            et = ret_type(tt);
        }
    };
}

#endif