#ifndef TL_H
#define TL_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "stdio.h"

namespace ll
{       

    enum    etype
    { eint, efloat, echar, echar_ar, eobj};

    struct  node
    {
        char*   obj_cont;
        etype   et;
        std::string s_type;
        node*   next;
        //void    set_type(std::string etype);
        void    ret_type();
    };

    void node::ret_type()
    {
        et = eobj;
        std::cout << et << std::endl;
    }

    //-----------------------

    class   c_dummy
    {
        public:
            int val;
            ~c_dummy();
    };

    c_dummy::~c_dummy()
    {
        std::cout << "Dist\n";
    }

    class   c_row
    {
        private:
            node    root;
        public:
            void write_class();
            void print_val();
    };

    //------------------------

    void c_row::write_class()
    {
        root.obj_cont = new char[sizeof(c_dummy)];
        c_dummy* tmpObj = new (root.obj_cont) c_dummy;
        tmpObj->val = 1234;
        root.s_type = typeid(tmpObj).name();
    }

    void c_row::print_val()
    {
        c_dummy* nObj = (c_dummy*)root.obj_cont;
        std::cout << "Saved val :" << nObj->val << std::endl;
    }
    
}

#endif
