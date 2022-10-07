#ifndef CL_LL_NS_HPP_
#define CL_LL_NS_HPP_

#include "st_ns.hpp"
#include "cl_dt_ns.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace nbt
{
    class   LinkedList
    {
        private:
            int         icount;
            int         id;
            st_node*    position;
            st_node*    s_root;
            template<typename T> void    sup_print_val(st_node* node);
        public:
            LinkedList();
            template<typename T> void    push_back(T add_val);
            template<typename T> void    push_forword(T add_val);
            template<typename T> T       ret_object(size_t num = 0);
            template<typename T> void   l_insert(size_t pos, T insert);
            int     ll_length(){ return this->icount;}
            void    print_val(st_node* node);
            void    print_val(size_t num = 0);
            char    ret_obj_type();
            void    print_ll();

            char*   operator[] (const int num);
    };

    char* LinkedList::operator[] (const int num)
    {
        if (!this->s_root || num > icount)
            {return nullptr;}

        int lim = num;
        st_node* tmp = this->s_root;
        if (id <= num && this->position && id >= 0){
            tmp = this->position;
            lim -= id;}
        int i;
        for (i = 0; i < lim && tmp; i++)
            tmp = tmp->next;
                
        if (!tmp)
            {return nullptr;}
        this->position = tmp;
        this->id = num;
        return tmp->obj_cont;
    }

    LinkedList::LinkedList()
    {
        this->s_root    = nullptr;
        this->icount    = 0;
        this->id        = -1;
        this->position  = nullptr;
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
        if (!this->s_root){
            this->s_root = ins;
            return ;}
        
        st_node*    tmp = s_root;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ins;
    }

    template<typename T>
    void LinkedList::push_forword(T add_val)
    {
        this->icount++;
        
        st_node*    tmp = new st_node;
        tmp->obj_cont = new char[sizeof(ClassData<T>)];
        tmp->set_type(&add_val);
        ClassData<T>* tmpObj = new (tmp->obj_cont) ClassData<T>;
        tmpObj->val = add_val;
        if (!this->s_root){
            tmp->next=nullptr;
            this->s_root=tmp;
            return ;}

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
        if (!this->s_root)
            {push_forword(insert); return ;}
        
        st_node*    tmp = s_root;

        for (size_t i = 0; i < pos && tmp; i++)
            {tmp = tmp->next;}
        
        if (!tmp)
            return ;

        if (!tmp->next)
            {
                push_back(insert);
                return ;
            }
        
        st_node*    tmp_in = new st_node;
        tmp_in->obj_cont = new char[sizeof(ClassData<T>)];
        tmp_in->set_type(&insert);
        ClassData<T>* tmpObj = new (tmp_in->obj_cont) ClassData<T>;
        tmpObj->val = insert;

        tmp_in->next = tmp->next;
        tmp->next = tmp_in;
        icount++;
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
}

#endif
