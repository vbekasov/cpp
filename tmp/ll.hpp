#ifndef LL_HPP
#define LL_HPP

#include <cstring>

namespace nbt{
    class LLNode{
        private:
            char*   val;
            int     ID;
            void    null_val();
        public:
            LLNode* next;
            LLNode();
            LLNode(const auto vl);
            void    add_val(const auto vl);
            void    add_val(const char* vl);
            void    add_val(const auto vl[], int sz);
            char*   return_val();
            template<class T> void add_obj(const char* vl);
    };

    LLNode::LLNode(){
        this->val  = nullptr;
        this->next = nullptr;
    }

    LLNode::LLNode(const auto vl){
        this->val  = nullptr;
        this->next = nullptr;
        val = new char[sizeof(vl)];
        memcpy(val, &vl, sizeof(vl));
    }

    void LLNode::null_val(){
        if (val){
            delete [] val;
            val = nullptr;
        }
    }

    void LLNode::add_val(const auto vl){
        this->null_val();
        val = new char[sizeof(vl)];
        memcpy(val, &vl, sizeof(vl));
    }

    void LLNode::add_val(const char* vl){
        this->null_val();
        unsigned int ln = strlen(vl);
        val = new char[ln * sizeof(char)];
        strcpy(val, vl);
    }

    void LLNode::add_val(const auto vl[], int sz){
        this->null_val();
        val = new char[sz];
        memcpy(val, vl, sz);
    }

    char* LLNode::return_val(){
        return val;
    }

    template<class T>
    void LLNode::add_obj(const char* vl){
        this->null_val();
        val = new char[sizeof(T)];
        memcpy(val, vl, sizeof(T));
    }

    class LL{
        private:
            LLNode* root;
            LLNode* give_last();
        public:
            LL(): root(nullptr) {};
            void    add_node(const auto vl);
            void    print();
    };

    LLNode* LL::give_last(){
        if (!root) return nullptr;
        LLNode* tmp = nullptr;
        while (root->next)
            tmp = root->next;
        return tmp;
    }

    void LL::add_node(const auto vl){
        if (!root){
            root = new LLNode(vl);
        }
        else{
            LLNode* tmp = this->give_last();
            tmp = new LLNode(vl);
        }
    }

    void LL::print(){
        if (!root){
            std::cout<< "Empty\n";
            return ;
        }
        LLNode* tmp = root;
        while (tmp){
            auto* tmp1 = tmp->return_val();
            std::cout<< tmp1 << std::endl;
            tmp = tmp->next;
        }
    }
};

#endif
