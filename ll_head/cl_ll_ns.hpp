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
            void    show_last();
        public:
            LinkedList();
            template<typename T> void    push_back(T add_val);
            template<typename T> void    push_forword(T add_val);
            template<typename T> T       ret_object();
            unsigned short int           ll_length();
            void    print_val(st_node* node);
            void    print_val();
            char    ret_obj_type();
            void    print_ll();

    };

    unsigned short int LinkedList::icount = 0;

    LinkedList::LinkedList()
    {
        this->s_root = nullptr;
    }

    template<typename T> 
    void LinkedList::push_back(T add_val)
    {
        //s_root = new st_node;
        st_node*    tmp = new st_node;
        tmp->obj_cont = new char[sizeof(ClassData<T>)];
        tmp->set_type(&add_val);
        ClassData<T>* tmpObj = new (tmp->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
        if (!this->s_root)
            {this->s_root = tmp;}
        else
        {
            this->s_root->next = tmp;
        }
        this->icount++;
    }

    template<typename T>
    void LinkedList::push_forword(T add_val)
    {
        st_node*    tmp = new st_node;
        tmp->obj_cont = new char[sizeof(ClassData<T>)];
        tmp->set_type(&add_val);
        ClassData<T>* tmpObj = new (tmp->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
        if (!this->s_root)
            {s_root = tmp; return ;}

        st_node*    exCng = new st_node;
        *exCng = *s_root;
        s_root->et = '+';
        s_root->~st_node();
        s_root = tmp;
        s_root->next = exCng;

    }

    template<typename T>
    void LinkedList::sup_print_val(st_node* node)
    {
        ClassData<T>* nObj = (ClassData<T>*)node->obj_cont;
        std::cout << nObj->val ;
        std::cout << "!" << node->et << " | " ;
    }
    
    void LinkedList::print_val()
    {
        if      (s_root->et == 'I') {sup_print_val<int>(s_root);}
        else if (s_root->et == 'C') {sup_print_val<char>(s_root);}
        else if (s_root->et == 'D') {sup_print_val<double>(s_root);}
        else if (s_root->et == 'S') {sup_print_val<std::string>(s_root);}
        else {std::cout << "Object";}
    }

    void LinkedList::print_val(st_node* node)
    {
        if      (node->et == 'I') {sup_print_val<int>(node);}
        else if (node->et == 'C') {sup_print_val<char>(node);}
        else if (node->et == 'D') {sup_print_val<double>(node);}
        else if (node->et == 'S') {sup_print_val<std::string>(node);}
        else {std::cout << "Object | ";}
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

    void LinkedList::print_ll()
    {
        st_node*    tmp = this->s_root;

        while (tmp)
        {
            print_val(tmp);
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    void LinkedList::show_last()
    {
        st_node*    tmp = this->s_root;

        while (tmp->next)
            tmp = tmp->next;
        print_val(tmp);
    }
}

#endif
