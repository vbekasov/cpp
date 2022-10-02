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
            static size_t  icount;
            st_node*    s_root;
            template<typename T> void    sup_print_val(st_node* node);
            void    show_last();
        public:
            LinkedList();
            template<typename T> void    push_back(T add_val);
            template<typename T> void    push_forword(T add_val);
            template<typename T> T       ret_object(size_t num = 0);
            template<typename T> void   l_insert(size_t pos, T insert);
            size_t  ll_length();
            void    print_val(st_node* node);
            void    print_val(size_t num = 0);
            char    ret_obj_type();
            void    print_ll();

            char* operator[] (const size_t num)
            {
                if (!this->s_root)
                    {return nullptr;}
                
                st_node* tmp = this->s_root;
                for (size_t i = 0; i < num && tmp; i++)
                    tmp = tmp->next;
                
                if (!tmp)
                    {return nullptr;}                
                return tmp->obj_cont;
            }

    };

    size_t LinkedList::icount = 0;

    LinkedList::LinkedList()
    {
        this->s_root = nullptr;
    }

    template<typename T> 
    void LinkedList::push_back(T add_val)
    {
        this->icount++;
        
        st_node*    ins = new st_node;
        ins->next = nullptr;
        ins->obj_cont = new char[sizeof(ClassData<T>)];
        ins->set_type(&add_val);
        ClassData<T>* tmpObj = new (ins->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
        if (!this->s_root)
            {this->s_root = ins; return ;}
        
        st_node*    tmp = s_root;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ins;        
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
            {tmp->next=nullptr; this->s_root=tmp; return ;}

        st_node*    exCng = new st_node;
        *exCng = *s_root;
        this->s_root->et = '+';
        this->s_root->~st_node();
        this->s_root = tmp;
        this->s_root->next = exCng;

    }

    template<typename T>
    T LinkedList::ret_object(size_t num)
    {
        st_node*    tmp = s_root;

        for (size_t i=0; i<num && tmp; tmp++)
            tmp = tmp->next;

        if (!tmp)
            return ;
        
        ClassData<T>* nObj = (ClassData<T>*)tmp->obj_cont;
        T ret = (T)nObj->val;

        return ret;
    }

    template<typename T>
    void LinkedList::l_insert(size_t pos, T insert)
    {
        if (!this->s_root || pos = 0)
            {push_forword(insert); return ;}
        
        st_node*    tmp = s_root;
        size_t      i;
        for (i = 0; i < pos && tmp->next; i++)
            tmp = tmp->next;
           
    }

    template<typename T>
    void LinkedList::sup_print_val(st_node* node)
    {
        ClassData<T>* nObj = (ClassData<T>*)node->obj_cont;
        std::cout << nObj->val ;
        std::cout << "!" << node->et << " | " ;
    }
    
    void LinkedList::print_val(size_t num)
    {
        st_node*    tmp = s_root;

        for (size_t i=0; i<num && tmp; i++)
            tmp = tmp->next; 

        if      (!tmp) { std::cout << "Empty\n";}
        else if (tmp->et == 'I')         {sup_print_val<int>(tmp);}
        else if (tmp->et == 'C')        {sup_print_val<char>(tmp);}
        else if (tmp->et == 'D')      {sup_print_val<double>(tmp);}
        else if (tmp->et == 'S') {sup_print_val<std::string>(tmp);}
        else {std::cout << "Object";}
        std::cout << std::endl;
    }

    void LinkedList::print_val(st_node* node)
    {
        if      (node->et == 'I') {sup_print_val<int>(node);}
        else if (node->et == 'C') {sup_print_val<char>(node);}
        else if (node->et == 'D') {sup_print_val<double>(node);}
        else if (node->et == 'S') {sup_print_val<std::string>(node);}
        else {std::cout << "Object | ";}
    }

    char LinkedList::ret_obj_type()
        { return this->s_root->et;}

    size_t LinkedList::ll_length()
    {
        if (!this->s_root)
            return 0;
        if (!this->s_root->next)
            return 1;

        size_t      tcount = 1;

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
