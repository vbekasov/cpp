#ifndef CL_DT_NS_HPP_
#define CL_DT_NS_HPP_

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
