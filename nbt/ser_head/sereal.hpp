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

namespace nbt
{
    class   Container{
        private:
            int         o_len;
            char*       object;
            std::string f_name;
        public:
            static std::vector<int>    file_map;
            Container();
            Container(char* y);
            Container(char* y, std::string fn);
            ~Container();
            virtual void print_var(void);
            virtual void add_str(char* txt);
            virtual void save(std::ofstream& wf);
            virtual void read(int num);
            virtual void set_wfile(std::string fn){ this->f_name = fn;};
            virtual int str_len(const char* txt);
            virtual Container return_cont(void);
    };

    std::vector<int> Container::file_map = {0};

    Container::Container(){
        this->object = nullptr;
        this->f_name = "";
    }

    Container::Container(char* y)
    {
        this->o_len  = this->str_len(y);
        this->object = new char[this->o_len];
        strcpy(this->object, y);
        this->f_name = "";
    }

    Container::Container(char* y, std::string fn){
        this->o_len  = this->str_len(y);
        this->object = new char[this->o_len];
        strcpy(this->object, y);
        this->f_name = fn;
    }

    Container::~Container(){
        if (this->object){
            delete [] this->object;
            this->object = nullptr; }
    }

    Container Container::return_cont(){return *this;}

    void Container::print_var(){
        std::cout<< this->o_len << std::endl;
        std::cout<< this->object << std::endl;
    }

    void Container::save(std::ofstream& wf){
        int tmp = this->o_len;
        wf.write((char*)&tmp, sizeof(int));
        wf.write(this->object, this->o_len);
        file_map.push_back(file_map.back() + this->o_len + sizeof(int));
    }

    void Container::read(int num){
        std::ifstream   rf;
        rf.open(this->f_name, std::ios::out | std::ios::binary);
        rf.seekg(Container::file_map[num]);
        rf.read((char*) &this->o_len, sizeof(int));
        if (this->object)
            delete [] this->object;
        this->object = new char[this->o_len];
        char* tmp = new char[16];
        rf.read(tmp, 16);
        strcpy(this->object, tmp);
        delete [] tmp;
        rf.close();
    }

    void Container::add_str(char* txt){
        this->o_len = this->str_len(txt);
        delete [] this->object;
        this->object = nullptr;
        this->object = new char[this->o_len];
        strcpy(this->object, txt);
    }

    int Container::str_len(const char* txt){
        int i = 0;
        while(*txt){
            txt++;
            i++;
        }
        return i;
    }
} // namespace nbt

#endif
