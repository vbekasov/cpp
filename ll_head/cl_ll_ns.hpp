#ifndef CL_LL_NS_HPP
#define CL_LL_NS_HPP

#include "st_ns.hpp"
#include "cl_dt_ns.hpp"
#include <iostream>

namespace ll
{
    class   LinkedList
    {
        private:
            st_node*   s_root;
        public:
            LinkedList();
            template<typename T> void write_class(T add_val);
            void print_val();
    };

    LinkedList::LinkedList()
    {
        s_root = nullptr;
    }

    template<typename T> void LinkedList::write_class(T add_val)
    {
        s_root = new st_node;
        s_root->obj_cont = new char[sizeof(ClassData<T>)];
        s_root->set_type(add_val);
        ClassData<T>* tmpObj = new (s_root->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
    }

    void LinkedList::print_val()
    {
        /*
        switch (root->et)
        {
        case 'I':
            c_dummy<char>* nObj = (c_dummy<char>*)root->obj_cont;
            break;
        case 'C':
            c_dummy<int>* nObj = (c_dummy<int>*)root->obj_cont;
            break;
        
        default:
            break;
        }
        */
        
        ClassData<int>* nObj = (ClassData<int>*)s_root->obj_cont;
        std::cout << "Saved val  :" << nObj->val << std::endl;
        std::cout << "Struc type :" << s_root->et << std::endl;
    }
}

#endif