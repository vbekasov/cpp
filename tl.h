#ifndef TL_H
#define TL_H

namespace ll
{   
    template<class T> class UniList
    {
    private:
        struct ls
        {
            T   var;
            ls  *next;
        };
    public:
        UniList(/* args */);
        ~UniList();
    };
    
    template<class T> UniList<T>::UniList(/* args */)
    {
    }
    
    template<class T> UniList<T>::~UniList()
    {
    }
    
}

#endif
