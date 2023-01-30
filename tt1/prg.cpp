#include <iostream>
#include <vector>
#include "bto.hpp"
#include "ex_cl.hpp"

template<class T> void    print_vec(std::vector<T>& tt){
    for (auto i = tt.begin(); i != tt.end(); i++)
            std::cout<< *i << "  ";
        
        std::cout<<std::endl;
}

int main(){
    std::cout<< "Start\n";
    nbt::BTree<int> BObj(5);
    std::cout<< "Size=" << sizeof(BObj) << std::endl;
    BObj.add_node(4);
    BObj.add_node(3);
    BObj.add_node(8);
    BObj.add_node(2);
    BObj.add_node(3);
    BObj.add_node(9);
    BObj.add_node(6);
    std::cout<< BObj.ret_size() << std::endl;
    BObj.print_tree();

    BObj.del_by_val(10);
    BObj.del_by_val(8);
    BObj.del_by_val(3);
    std::cout<< BObj.ret_size() << std::endl;
    BObj.print_tree();
    std::vector<int> tt(BObj.ret_size());
    tt = BObj.tree_to_vec();
    print_vec<int>(tt);

    int arr[5] = {9,8,7,6,5};
    BObj.erase_tree();
    BObj.arr_to_tree(arr, sizeof(arr)/sizeof(arr[0]));
    std::cout<< BObj.ret_size() << std::endl;
    BObj.print_tree();
    std::vector<int> av = {1,2,3,4,5,6,7,8};
    BObj.erase_tree();
    BObj.vec_to_tree(av);
    std::cout<< BObj.ret_size() << std::endl;
    BObj.print_tree();
    BObj.erase_tree();

    std::cout<< "\nNew Objects\n";
    std::vector<ExComp> ECvec = {
        {1, "1st"}, {2, "2nd"},
        {3, "3rd"}, {4, "4th"},
        {5, "5th"}, {6, "6th"},
        {7, "7th"}, {8, "8th"}
    };
    nbt::BTree<ExComp> EXT;
    //for (auto it = ECvec.begin(); it != ECvec.end(); it++)
    //    EXT.add_node(*it);
    print_vec<ExComp>(ECvec);
    EXT.vec_to_tree(ECvec);
    std::cout<< EXT.ret_size() << std::endl;
    EXT.print_tree();

    std::cout<< "\n-----------finish-------------\n";

    return 0;
}
