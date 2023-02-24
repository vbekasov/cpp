# Binary Tree

`BT` - Binary Tree

## Binary Tree Node

```
template <class T>
    class BtNode{
        public:
            T           val;
            BtNode<T>*  left;
            BtNode<T>*  right;
            BtNode  (T n);
            ~BtNode (){ }
            void    set_val(T n){ *val = n;}
            void    show_val(){ std::cout<< "Node " << val << std::endl;}
    };
```
This template class represents a node for BT. If you would like to make BT of objects, you have to use overloaded comparison operators <i><=></i>.
* `T val;` - a value of the node.
* `BtNode<T>*  left; BtNode<T>*  right;` - references to left and right brenches. The left value is less than the node value, right is greater than the node value.
* `BtNode (T n);` - binary tree node constructor. `T n` sets object value. Constructor assaigns <i>left</i> and <i>right</i> to <i>nullptr</i>.
* `~BtNode ();` - destructor. The destructor does not deallocate the sub-tree.
* `void set_val();` - sets value. Remember, it would break the concept of the BT: Left < Value < Right.
* `void show_val();` - prints value.

## Binary Tree Class
```
template <class T>
    class BTree{
        private:
            BtNode<T>*           root;
            unsigned int         btsize;
            void        sup_print(BtNode<T>* node);
            void        sup_vec(BtNode<T>* node, std::vector<T>& vec_add);
            void        sup_del(BtNode<T>* node);
            BtNode<T>*  sup_ret_node(auto vl);
            BtNode<T>*  sup_ret_prev(T vl);
        public:
            BTree () : root(nullptr), btsize(0) {}
            BTree (T n): root(new BtNode<T>(n)), btsize(1) {}
            void    add_node(T n);
            void    arr_to_tree(T* arr, unsigned int sz);
            void    vec_to_tree(std::vector<T>& vc);
            void    arr_by_order(T* arr, unsigned int sz);
            void    vec_by_order(std::vector<T>& vc);
            void    print_tree();
            void    del_by_val(T vl);
            void    replace_val(T oldv, T newv);
            void    balance_tree();
            void    erase_tree();
            T       return_obj(auto vl);
            unsigned int    ret_size(){ return btsize;}
            std::vector<T>  tree_to_vec();
    };
```
This template class carries the BT. An object of the class `BTree<T>` carries a pointer to the root of the BT and has methods to work with the BT.

Public methods:
* `BTree();` - constructor. Assigns root to the <i>nullptr</i>, and BT size to 0.
* `BTree(T n);` - constructor. Allocates the first root with value `T n`, and assigns BT size to 0.
* `void add_node(T n);` - adds node to the BT. Does not add duplicated objects.
* `void arr_to_tree(T* arr, unsigned int sz);` - erases existing tree and generates new BT based on the passed array. `T* arr` - pointer to the arr. `unsigned int sz` - size of the array. The method uses binary search: middle goes first, then goes middle of the left side, then goes middle of the right side, and so on.
* `void vec_to_tree(std::vector<T>& vc);` - erases existing tree and generates new BT based on the passed vector. `std::vector<T>& vc` - a reference to the array. The method uses binary search: middle goes first, then goes middle of the left side, then goes middle of the right side, and so on.
* `void arr_by_order(T* arr, unsigned int sz);` - erases existing tree and generates new BT based on the passed array. `T* arr` - pointer to the arr. `unsigned int sz` - the size of the array. The method adds elements to the BT by the order they are in the array.
* `void vec_by_order(std::vector<T>& vc);` - erases existing tree and generates new BT based on the passed vector. `std::vector<T>& vc` - a reference to the vector. The method adds elements to the BT by the order they are in the vector.
* `void print_tree();` - prints BT.
* `void del_by_val(T vl);` - deletes node and sub-tree.
* `void replace_val(T oldv, T newv);` - replaces old value to new. `T oldv` - old value. `T newv` - a new value. Please remember, it would break the concept of the BT: Left < Value < Right.
* `void balance_tree();` - balances tree.
* `void erace_tree();` - eraces BT.
* `unsigned int ret_size();` - returns the size of the BT.
* `std::vector<T> tree_to_vec();` - returnes the BT in vector form.
* `T* return_obj(auto vl);` - returnes a pointer of an object found by value. If object was not found, function returns <i>nullptr</i>.

Private methods:
* `BtNode<T>* root;` - pointer to the first element of the BT.
* `unsigned int btsize;` - number of elements in the BT.
* Support functions for public methods.
