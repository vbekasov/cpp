#ifndef CL_LL_NS_HPP
#define CL_LL_NS_HPP

#include "st_ns.hpp"
#include "cl_dt_ns.hpp"
#include "cl_fun_over.hpp"
#include <iostream>
#include <string>

namespace ll
{
    class   LinkedList
    {
        private:
            static int icount;
            st_node*   s_root;
            template<typename T>
                void sup_print_val(st_node* node);
                void sup_print_val(st_node* node, int n);
        public:
            LinkedList();
            template<typename T> void write_class(T add_val);
            void print_val(st_node* node);
            void print_val();
    };

    int LinkedList::icount = 0;

    LinkedList::LinkedList()
    {
        this->s_root = nullptr;
    }

    template<typename T> 
    void LinkedList::write_class(T add_val)
    {
        s_root = new st_node;
        s_root->obj_cont = new char[sizeof(ClassData<T>)];
        s_root->set_type(add_val);
        ClassData<T>* tmpObj = new (s_root->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
        this->icount++;
        std::cout << "IN" << s_root->et << this->icount << std::endl;
    }

    template<typename T>
    void LinkedList::sup_print_val(st_node* node)
    {
        ClassData<T>* nObj = (ClassData<T>*)node->obj_cont;
        std::cout << "Saved val  :" << nObj->val << std::endl;
        std::cout << "Struc type :" << node->et << std::endl;
    }

    void LinkedList::sup_print_val(st_node* node, int n)
    {
        TestInput* nObj = (TestInput*)node->obj_cont;
        nObj->print_xy();
        n++;
    }
    
    void LinkedList::print_val()
    {
        switch (s_root->et)
        {
        case 'I':
            sup_print_val<int>(s_root);
            break;
        case 'C':
            sup_print_val<char>(s_root);
            break;
        case 'D':
            sup_print_val<double>(s_root);
            break;
        case 'S':
            sup_print_val<std::string>(s_root);
            break;
        case 'O':
            sup_print_val(s_root, 1);
        default:
            break;
        }
    }

    void LinkedList::print_val(st_node* node)
    {
        switch (node->et)
        {
        case 'I':
            sup_print_val<int>(node);
            break;
        case 'C':
            sup_print_val<char>(node);
            break;
        case 'D':
            sup_print_val<double>(node);
        case 'S':
            sup_print_val<std::string>(node);
            break;
        // ADD object        
        default:
            break;
        }
    }
}

#endif
