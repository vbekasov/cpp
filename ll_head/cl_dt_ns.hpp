#ifndef CL_DT_NS_HPP
#define CL_DT_NS_HPP

#include <iostream>

namespace ll
{
    template<typename T>
    class   ClassData
    {
        public:
            T val;
            ~ClassData();
    };

    template<typename T>
        ClassData<T>::~ClassData()
    {
        std::cout << "Dist\n";
    }
}

#endif
