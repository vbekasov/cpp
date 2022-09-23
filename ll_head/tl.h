#ifndef TL_H
#define TL_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "stdio.h"
#include "str_ns.hpp"

namespace ll
{       
    template<typename T>
    class   c_dummy
    {
        public:
            T val;
            ~c_dummy();
    };

    template<typename T>
        c_dummy<T>::~c_dummy()
    {
        std::cout << "Dist\n";
    }

    class   c_row
    {
        private:
            node*   root;
        public:
            c_row();
            template<typename T> void write_class(T add_val);
            void print_val();
    };

    c_row::c_row()
    {
        root = nullptr;
    }

    template<typename T> void c_row::write_class(T add_val)
    {
        root = new node;
        root->obj_cont = new char[sizeof(c_dummy<T>)];
        root->set_type(add_val);
        c_dummy<T>* tmpObj = new (root->obj_cont) c_dummy<T>;
        tmpObj->val = add_val;
    }

    void c_row::print_val()
    {
        c_dummy<int>* nObj = (c_dummy<int>*)root->obj_cont;
        std::cout << "Saved val  :" << nObj->val << std::endl;
        std::cout << "Struc type :" << root->et << std::endl;
    }
    
}

#endif
