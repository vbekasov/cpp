#ifndef TL_H
#define TL_H

namespace ll
{   
    //template<class T> 
        class UniList
    {
    private:
        template<auto val>
            struct ls
        {
            static constexpr auto var = val;
            ls*  next;
        };

        //ls*  root;

    public:
        UniList(const auto fst);
        ~UniList();
    };
    
    /*template<class T> */ UniList::UniList(const auto fst)
    {
        const char tmp = 'A';
        const auto tmp1 = fst;
        ls<tmp1>* root = nullptr;
        //root = new ls;
        //root->var = fst;
        std::cout<<fst<<std::endl;
        root->next = nullptr;
    }
    
    /*
    template<class T> UniList<T>::~UniList()
    {
    }*/
    
}

#endif
