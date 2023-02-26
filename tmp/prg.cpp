#include <iostream>
#include "ll.hpp"
#include "tst_class.hpp"

int main(){

    nbt::LLNode Obj(1);
    std::cout<< *(int*)Obj.return_val() << std::endl;
    Obj.add_val(987.654);
    std::cout<< *(double*)Obj.return_val() << std::endl;
    Obj.add_val("TEST TEXT");
    std::cout<< Obj.return_val() << std::endl;

    TstC TObj(5, 675.23);
    Obj.add_val(TObj);
    TstC* TObj1 = (TstC*)Obj.return_val();
    std::cout<< *TObj1 << std::endl;
    TObj.~TstC(); TObj1->~TstC();

    long double arr[3] = {4.3, 2.7, 1.2};
    Obj.add_val(arr, sizeof(arr));
    long double* ia = (long double*)Obj.return_val();
    std::cout<< ia[1] << std::endl;

    TstC1 TObj2;
    //std::cout<< TObj2 << std::endl;
    Obj.add_val(TObj2);
    std::cout<< Obj.return_val() << std::endl;

    return 0;
}
