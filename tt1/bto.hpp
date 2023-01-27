//https://en.wikipedia.org/wiki/Copy_elision#RVO

#include <vector>

namespace nbt
{
    //++++++++++++++++++++++++++++++++++++++++++++++++
    template <class T>
    class BtNode{
        public:
            T           val;
            BtNode<T>*  left;
            BtNode<T>*  right;
            BtNode  (T n);
            ~BtNode (){ }
            void    set_val(T n){ *val = n;}
            void    show_val(){ std::cout<< "Node " << *val << std::endl;}
    };

    template <class T>
    BtNode<T>::BtNode(T n){
        val = n;
        left = nullptr; right = nullptr;
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++
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
            void    print_tree();
            void    del_by_val(T vl);
            void    replace_val(T oldv, T newv);
            void    balance_tree();
            void    erace_tree();
            unsigned int    ret_size(){ return btsize;}
            std::vector<T>  tree_to_vec();
    };

    template <class T>
    void BTree<T>::add_node(T n){
        if (this->root == nullptr){
            this->root = new BtNode<T>(n);
            return ;
        }
        
        bool        flag = true;
        BtNode<T>*  tmp  = this->root;

        while (flag)
        {
            if (n == tmp->val) return ;
            if (n < tmp->val && tmp->left)
                tmp = tmp->left;
            else if (n > tmp->val && tmp->right)
                tmp = tmp->right;
            else
                flag = false;
        }

        if (n < tmp->val)
            tmp->left  = new BtNode<T>(n);
        else
            tmp->right = new BtNode<T>(n);
        
    }

    template<class T>
    void BTree<T>::print_tree(){
        std::cout<< "===Tree===\n";
        sup_print(this->root);
        std::cout<< "==========\n";
    }

    template<class T>
    void BTree<T>::sup_print(BtNode<T>* node){
        std::cout<< "val  " << node->val << std::endl;
        if (node->left)
            std::cout<< node->left->val << " <-|-> ";
        else
            std::cout<< "Null  <-|-> ";
        
        if (node->right)
            std::cout<< node->right->val << std::endl;
        else
            std::cout<< "Null\n";

        if (node->left)  sup_print(node->left);
        if (node->right) sup_print(node->right);
    }

    template<class T>
    std::vector<T> BTree<T>::tree_to_vec(){
        std::vector<T> ret;
        sup_vec(this->root, ret);
        sort(ret.begin(), ret.end());

        return ret;
    }

    template<class T>
    void BTree<T>::sup_vec(BtNode<T>* node, std::vector<T>& vec_add){
        if (node->left)  sup_vec(node->left, vec_add);
        if (node->right) sup_vec(node->right, vec_add);
        vec_add.push_back(node->val);
    }

    template<class T>
    void BTree<T>::del_by_val(T vl){
        BtNode<T>*  tmp = sup_ret_prev(vl);
        if (!tmp) return ;
        if (root->val == vl){sup_del(this->root); this->root = nullptr; }
        if (tmp->val > vl)  {sup_del(tmp->left);  tmp->left  = nullptr; }
        else                {sup_del(tmp->right); tmp->right = nullptr; }
    }

    template<class T>
    void BTree<T>::sup_del(BtNode<T>* node){
        if (node->left)  sup_del(node->left);
        if (node->right) sup_del(node->right);
        this->btsize--;
        delete node;
    }

    template<class T>
    BtNode<T>* BTree<T>::sup_ret_prev(T vl){
        BtNode<T>*  tmp  = this->root;
        bool        flag = true;
        while (flag){
            flag = false;
            if (tmp->left && vl < tmp->val){
                if (tmp->left->val == vl) return tmp;
                tmp = tmp->left;
                flag = true;
            }
            if (tmp->right && vl > tmp->val){
                if (tmp->right->val == vl) return tmp;
                tmp = tmp->right;
                flag = true;
            }
        }
        return nullptr;
    }
    
    template<class T>
    BtNode<T>* BTree<T>::sup_ret_node(T vl){
        BtNode<T>*  tmp = this->root;
        while (true){
            if (vl == tmp->val) return tmp;
            if (vl < tmp->val && tmp->left)
                tmp = tmp->left;
            else if (vl > tmp->val)
                tmp = tmp->right;
            else return nullptr;
        }
    }

    template<class T>
    void BTree<T>::arr_to_tree(T* arr, unsigned int sz){
        if (sz > 2){
            add_node(arr[sz / 2]);
            arr_to_tree(&arr[0], sz / 2);
            arr_to_tree(&arr[sz - sz / 2], sz / 2);
        }
        else if(sz == 2){
            add_node(arr[1]);
            add_node(arr[0]);
        }
    }

    template<class T>
    void BTree<T>::vec_to_tree(std::vector<T>& vc){
        arr_to_tree(&vc[0], vc.size());
    }

    template<class T>
    void BTree<T>::replace_val(T oldv, T newv){
        BtNode<T>*  tmp = sup_ret_node(oldv);
        if (!tmp) return ;
        tmp->val = newv;
    }

    template<class T>
    void BTree<T>::balance_tree(){
        std::vector<T>  tmp = tree_to_vec();
        this->erace_tree();
        vec_to_tree(tmp);
    }

    template<class T>
    void BTree<T>::erace_tree(){
        sup_del(this->root);
        this->root = nullptr;
    }

    
} // namespace nbt
