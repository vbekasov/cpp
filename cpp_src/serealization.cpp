#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>

class   Container{
    private:
        int     o_len;
        char*   object;
        std::vector<int>    file_map = {0};
    public:
        Container(){};
        Container(char* y);
        virtual void print_var(void);
        virtual void add_str(char* txt);
        virtual void save(std::ofstream& wf);
        virtual void read(std::ifstream& rf, unsigned int num);
        virtual int str_len(const char* txt);
        virtual Container return_cont(void);
};

Container::Container(char* y)
{
    this->o_len  = this->str_len(y);
    this->object = y;
}

Container Container::return_cont(){return *this;}

void Container::print_var(){
    std::cout<< this->o_len << "  " << this->object << std::endl;
}

void Container::save(std::ofstream& wf){
    wf.write((char*)&this->o_len, sizeof(this->o_len));
    wf.write((char*)&this->object, sizeof(this->object));
    wf.close();
    this->file_map.push_back(this->file_map.back() + this->o_len);
}

void Container::read(std::ifstream& rf, unsigned int num){
    rf.read((char*) &this->o_len, sizeof(int));
    rf.read((char*)&this->object , this->o_len);
}

void Container::add_str(char* txt){
    this->o_len = this->str_len(txt);
    this->object = txt;
}

int Container::str_len(const char* txt){
    int i = 0;
    while(*txt){
        txt++;
        i++;
    }
    return i;
}

int main(void){

    Container       wObj((char*)"TEST TEXT!!!!!!!!!!");

    mkdir("data", 0777);
    chdir("data");

    std::ofstream   wf;
    wf.open("data.dat", std::ios::out | std::ios::binary);
    wObj.save(wf);
    wf.close();

    std::ifstream   rf;
    rf.open("data.dat", std::ios::out | std::ios::binary);
    wObj.read(rf, 12);
    wObj.print_var();

    Container       nObj;
    nObj = wObj.return_cont();
    nObj.print_var();

    chdir("..");

    return 0;
}
