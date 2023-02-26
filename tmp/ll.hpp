#ifndef LL_HPP
#define LL_HPP

#include <cstring>

namespace nbt{
    class LLNode{
        private:
            char*   val;
            int     ID;
            LLNode*   next;
        public:
            LLNode();
            LLNode(const auto vl);
            void    add_val(const auto vl);
            void    add_val(const char* vl);
            void    add_val(const auto vl[], int sz);
            char*   return_val();
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

    void LLNode::add_val(const auto vl){
        if (val){
            delete [] val;
            val = nullptr;
        }

        val = new char[sizeof(vl)];
        memcpy(val, &vl, sizeof(vl));
    }

    void LLNode::add_val(const char* vl){
        if (val){
            delete [] val;
            val = nullptr;
        }
        unsigned int ln = strlen(vl);
        val = new char[ln * sizeof(char)];
        strcpy(val, vl);
        val[ln] = '\0';
    }

    void LLNode::add_val(const auto vl[], int sz){
        if (val){
            delete [] val;
            val = nullptr;
        }

        val = new char[sz];
        memcpy(val, vl, sz);
    }

    char* LLNode::return_val(){
        return val;
    }

};

#endif
