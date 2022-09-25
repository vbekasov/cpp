#ifndef CL_LL_NS_HPP_
#define CL_LL_NS_HPP_

#include "st_ns.hpp"
#include "cl_dt_ns.hpp"
#include <iostream>
#include <string>

namespace ll
{
    class   LinkedList
    {
        private:
            static unsigned short int  icount;
            st_node*    s_root;
            template<typename T> void    sup_print_val(st_node* node);
        public:
            LinkedList();
            template<typename T> void    write_object(T add_val);
            template<typename T> T       ret_object();
            unsigned short int    ll_length();
            void    print_val(st_node* node);
            void    print_val();
            char    ret_obj_type();
    };

    unsigned short int LinkedList::icount = 0;

    LinkedList::LinkedList()
    {
        this->s_root = nullptr;
    }

    template<typename T> 
    void LinkedList::write_object(T add_val)
    {
        s_root = new st_node;
        s_root->obj_cont = new char[sizeof(ClassData<T>)];
        s_root->set_type(add_val);
        ClassData<T>* tmpObj = new (s_root->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
        this->icount++;
    }

    template<typename T>
    void LinkedList::sup_print_val(st_node* node)
    {
        ClassData<T>* nObj = (ClassData<T>*)node->obj_cont;
        std::cout << "Saved val  :" << nObj->val << std::endl;
        std::cout << "Struc type :" << node->et << std::endl;
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
        default:
            break;
        }
    }

    template<typename T>
    T LinkedList::ret_object()
    {
        ClassData<T>* nObj = (ClassData<T>*)this->s_root->obj_cont;
        T ret = (T)nObj->val;

        return ret;
    }

    char LinkedList::ret_obj_type()
        { return this->s_root->et;}

    unsigned short int LinkedList::ll_length()
    {
        if (!this->s_root)
            return 0;
        if (!this->s_root->next)
            return 1;

        unsigned short int    tcount = 1;

        st_node*    tmp = this->s_root->next;
        while (tmp->next)
        {
            tcount++;
            tmp = tmp->next;
        }

        return tcount;
    }

}

#endif
