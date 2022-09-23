#include <iostream>
#include <string>
#include "tl.h"

template <typename T>
    struct s_list
    {
        T           m;
        s_list<T>   *next = nullptr;
    };

template <class T>
    class c_scnd
    {
    private:
        s_list<T>*  loc;
        T           var;
        s_list<T>*  ret_last();
    public:
        c_scnd(T s_list);
        c_scnd();
        ~c_scnd() { wipe_all();}
        void    add_el(T nel);
        void    add_fst(T fel);
        void    del_last();
        void    wipe_all();
        void    prnt_list();
    };
    
template<class T> c_scnd<T>::c_scnd(T fst)
{
    loc = new s_list<T>;
    loc->m = fst;
    loc->next = nullptr;
}

template<class T> c_scnd<T>::c_scnd()
{
    loc = nullptr;
}

template<class T> void c_scnd<T>::prnt_list()
{
    if (loc == nullptr)
    {
        std::cout<< "!!!Empty list!!!\n";
        return ;
    }
    
    s_list<T>   *el;
    el = loc;
    std::cout<<"List   : ";
    while (el->next != nullptr)
    {
        std::cout << el->m << " ";
        el = el->next;
    }
    std::cout<< el->m <<std::endl;
}

template<class T> s_list<T>* c_scnd<T>::ret_last()
{
    s_list<T>   *el;
    el = loc;
    while (el->next != nullptr)
        el = el->next;

    return el;
}

template<class T> void c_scnd<T>::add_el(T nel)
{
    s_list<T>   *el;
    el = new(s_list<T>);
    el->m = nel;
    std::cout << "New el : " << el->m << std::endl;
    
    s_list<T>   *last = ret_last();
    last->next = el;
}

template<class T> void c_scnd<T>::del_last()
{
    if (loc->next == nullptr)
        return ;

    s_list<T>   *el = loc;
    while (el->next->next != nullptr)
        el = el->next;
    
    std::cout<<"del el : " << el->next->m <<std::endl;
    delete el->next;
    el->next = nullptr;
}

template<class T> void c_scnd<T>::wipe_all()
{
    if (loc == nullptr)
        return ;
    
    while (loc->next != nullptr)
        del_last();
    std::cout<< "del lst: " << loc->m << std::endl;
    delete loc;
    loc = nullptr;
    prnt_list();
}

template<class T> void c_scnd<T>::add_fst(T fel)
{
    s_list<T>   *el = loc;
    //T         tmp1 = loc->m;
    //T         tmp2;
    int         i = 0;

    //loc->m = fel;
    //tmp2++;
    fel++;
    while (el->next != nullptr)
    {
        el->m = i;
        el = el->next;
        i++;
    }

    el->m = i;
    el->next = new s_list<T>;
    el->next->m = ++i;
    el->next->next = nullptr;
}

//----------------------------------------------------------------

int main()
{
    std::cout << "\nPRG MAIN START\n\n";

    char* p = new char[sizeof(c_scnd<int>)];
    c_scnd<int>* Obj1 = new (p) c_scnd<int>(1);
    Obj1->add_el(1234);
    Obj1->add_el(987);
    Obj1->prnt_list();
    Obj1->add_fst(123);
    Obj1->prnt_list();
    Obj1->~c_scnd();
    delete [] p;

    std::cout<<std::endl;
    
    p = new char[sizeof(c_scnd<std::string>)];
    c_scnd<std::string>* Obj2 = new (p) c_scnd<std::string>("FST");
    Obj2->add_el("ABC");
    Obj2->add_el("QWERTY");
    Obj2->add_el("SOME");
    Obj2->add_el("!TO DELETE!");
    Obj2->prnt_list();
    Obj2->del_last();
    Obj2->prnt_list();
    Obj2->wipe_all();
    Obj2->c_scnd::~c_scnd();
    delete [] p;

    p = new char[sizeof(ll::UniList)];
    std::cout << "\nPRG MAIN FINISHED\n";
    ll::UniList* Obj3 = new (p) ll::UniList('A');
    std::cout << "\nPRG MAIN FINISHED\n";
    Obj3++;
    delete [] p;

    std::cout << "\nPRG MAIN FINISHED\n";
    
    return 0;
}
