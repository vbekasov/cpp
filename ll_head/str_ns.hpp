#ifndef STR_NS_HPP
#define STR_NS_HPP

#include <iostream>

namespace ll
{   
    // can be overloaded by user
    
    char    ret_type(int v)
        {v++; return 'I';}

    char    ret_type(float v)
        {v++; return 'F';}

    char    ret_type(std::string v)
        {v=""; return 'S';}

    char    ret_type(char v)
        {v++; return 'C';}
    
    char    ret_type(auto v)
        {v++; return 'O';}

    struct  node
    {
        char*   obj_cont;
        char    et;
        node*   next;
        void    set_type(auto tt)
        {
            et = ret_type(tt);
        }
    };

}

#endif