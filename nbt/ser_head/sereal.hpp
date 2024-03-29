#ifndef SEREAL_HPP_
#define SEREAL_HPP_

#include <unistd.h>
#include <sys/stat.h>
//---------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
//---------------------
#include "../tree_head/st_bt.hpp"

namespace nbt
{
    class   SContainer{
        private:
            unsigned char        et;
            int                 o_len;
            char*               object;
            std::string         f_name;
        public:
            static std::vector<int>    file_map;
            SContainer();
            SContainer(const char* y);
            SContainer(const char* y, std::string fn);
            ~SContainer();
            virtual void  print_var(void);
            virtual void  add_str(const char* txt);
            virtual void  save();
            virtual char  read(int num);
            virtual void  set_wfile(std::string fn){ this->f_name = fn;};
            virtual int   str_len(const char* txt);
            virtual char* ret_obj(void) { return this->object;}
            virtual SContainer return_cont(void);
            void add_obj(char* Obj, int o_size, char o_type);
    };

    std::vector<int> SContainer::file_map = {0};

    SContainer::SContainer(){
        this->object = nullptr;
        this->f_name = "";
        this->et     = 'S';
    }

    SContainer::SContainer(const char* y){
        this->o_len  = this->str_len(y);
        this->object = new char[this->o_len];
        memcpy(this->object, y, this->o_len);
        this->f_name = "";
        this->et = 'S';
    }

    SContainer::SContainer(const char* y, std::string fn){
        this->o_len  = this->str_len(y);
        this->object = new char[this->o_len];
        memcpy(this->object, y, this->o_len);
        this->f_name = fn;
        this->et = 'S';
    }

    SContainer::~SContainer(){
        if (this->object){
            delete [] this->object;
            this->object = nullptr; }
    }

    SContainer SContainer::return_cont(){return *this;}

    void SContainer::print_var(){
        std::cout<< std::endl;
        std::cout<< this->et << std::endl;
        std::cout<< this->o_len << std::endl;
        std::cout<< this->object << std::endl;
    }

    void SContainer::save(){
        std::ofstream  wf;
        wf.open("data.dat", std::ios_base::app);

        int tmp = this->o_len;
        wf.write((char*)&tmp, sizeof(int));
        wf.write((char*)&this->et, sizeof(unsigned char));
        wf.write(this->object, this->o_len);
        file_map.push_back(file_map.back()+this->o_len+sizeof(int)+sizeof(unsigned char));
        prnt_vec(&file_map);

        wf.close();
    }

    char SContainer::read(int num){
        std::ifstream   rf;
        rf.open(this->f_name, std::ios::out | std::ios::binary);
        rf.seekg(SContainer::file_map[num]);
        rf.read((char*) &this->o_len, sizeof(int));
        rf.read((char*) &this->et, sizeof(unsigned char));
        if (this->object)
            delete [] this->object;
        this->object = new char[this->o_len];
        char* tmp = new char[this->o_len];
        rf.read(tmp, this->o_len);
        memcpy(this->object, tmp, this->o_len);
        delete [] tmp;
        rf.close();
        return this->et;
    }

    void SContainer::add_str(const char* txt){
        this->o_len  = this->str_len(txt);
        this->et     = 'S';
        delete [] this->object;
        this->object = nullptr;
        this->object = new char[this->o_len];
        memcpy(this->object, txt, this->o_len);
    }

    void SContainer::add_obj(char* Obj, int o_size, char o_type){
        this->o_len  = o_size;
        this->et     = o_type;
        delete [] this->object;
        this->object = nullptr;
        this->object = new char[this->o_len];
        memcpy(this->object, Obj, this->o_len);
    }

    int SContainer::str_len(const char* txt){
        int i = 0;
        while(*txt){
            txt++;
            i++;
        }
        return i;
    }
} // namespace nbt

#endif
