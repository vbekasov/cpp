#include <iostream>
#include <vector>
#include "bto.hpp"

template<class T> void    print_vec(std::vector<T>& tt){
    for (auto i = tt.begin(); i != tt.end(); i++)
            std::cout<< *i << "  ";
        
        std::cout<<std::endl;
}

int main(){
    std::cout<< "Start\n";
    nbt::BTree<int> BObj(5);
    BObj.add_node(4);
    BObj.add_node(3);
    BObj.add_node(8);
    BObj.add_node(2);
    BObj.add_node(3);
    BObj.add_node(9);
    BObj.add_node(6);
    BObj.print_tree();

    BObj.del_by_val(10);
    BObj.del_by_val(8);
    BObj.del_by_val(3);
    std::vector<int> tt(BObj.ret_size());
    tt = BObj.tree_to_vec();
    print_vec<int>(tt);

    int arr[5] = {9,8,7,6,5};
    std::vector<int> av = {1,2,3,4,5,6,7,8,9};
    nbt::BTree<int> BObj1(5);
    BObj1.arr_to_tree(&av[0] , av.size());
    BObj1.print_tree();

    std::cout<< "-----------finish-------------\n";

    return 0;
}
