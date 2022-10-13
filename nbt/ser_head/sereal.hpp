#ifndef SEREAL_HPP_
#define SEREAL_HPP_

//#include <filesystem>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
//---------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
//---------------------
#include "../nbt.h"
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
            SContainer(char* y);
            SContainer(char* y, std::string fn);
            ~SContainer();
            virtual void print_var(void);
            virtual void add_str(char* txt);
            virtual void save();
            virtual void read(int num);
            virtual void set_wfile(std::string fn){ this->f_name = fn;};
            virtual int  str_len(const char* txt);
            virtual char* ret_obj(void) { return this->object;}
            virtual SContainer return_cont(void);
    };

    std::vector<int> SContainer::file_map = {0};

    SContainer::SContainer(){
        this->object = nullptr;
        this->f_name = "";
        this->et = 'S';
    }

    SContainer::SContainer(char* y){
        this->o_len  = this->str_len(y);
        this->object = new char[this->o_len];
        strcpy(this->object, y);
        this->f_name = "";
        this->et = 'S';
    }

    SContainer::SContainer(char* y, std::string fn){
        this->o_len  = this->str_len(y);
        this->object = new char[this->o_len];
        strcpy(this->object, y);
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

    void SContainer::read(int num){
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
        strcpy(this->object, tmp);
        delete [] tmp;
        rf.close();
    }

    void SContainer::add_str(char* txt){
        this->o_len = this->str_len(txt);
        delete [] this->object;
        this->object = nullptr;
        this->object = new char[this->o_len];
        strcpy(this->object, txt);
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
