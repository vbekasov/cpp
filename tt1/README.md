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
            BtNode<T>*  sup_ret_node(T vl);
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
            unsigned int    ret_size(){ return btsize;}
            std::vector<T>  tree_to_vec();
    };
```
This template class carries the BT. Object of the class BTree<T> carries pointer to the root of the BT and has methods to work with the BT.<br>
Public methods:
* `BTree();` - constructor. Assignes root to the <i>nullptr</i>, and BT size to 0.
* `BTree(T n);` - constructor. Allocates first root with value `T n`, and assignes BT size to 0.
* `void add_node(T n);` - adds node to the BT. Do not adds duplicated objects.
* `void arr_to_tree(T* arr, usigned int sz);` - eraces existing tree and generates new BT based on the passed array. `T* arr` - pointer to the arr. `usigned int sz` - size of the array. Method uses binary search: midle goes first, then goes midle of the left side, then goes migle of the rightside, and so on.
* `void vec_to_tree(std::vector<T>& vc);` - eraces existing tree and generates new BT based on the passed vector. `std::vector<T>& vc` - reference to the arr. Method uses binary search: midle goes first, then goes midle of the left side, then goes migle of the rightside, and so on.
* `void arr_by_order(T* arr, usigned int sz);` - eraces existing tree and generates new BT based on the passed array. `T* arr` - pointer to the arr. `usigned int sz` - size of the array. Method adds elements to the BT by the order the are in the array.
* `void vec_by_order(std::vector<T>& vc);` - eraces existing tree and generates new BT based on the passed vector. `std::vector<T>& vc` - referance to the vector. Method adds elements to the BT by the order the are in the vector.
* `void print_tree();` - prints BT.
* `void del_by_val(T vl);` - deletes node and sub-tree.
* `void replace_val(T oldv, T newv);` - replaces old value to new. `T oldv` - old value. `T newv` - new value. Please remember, it would break the concept of the BT: Left < Value < Right.
* 'void balance_tree();` - balances tree.
* `void erace_tree();` - eraces BT.
* `unsigned int ret_size();` - returnes size of the BT.
* `std::vector<T> tree_to_vec();` - returnes the BT in vector form.
