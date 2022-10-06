//#include <filesystem>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
//---------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class   Container{
    public:
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
    this->object = new char[this->o_len];
    strcpy(this->object, y);
}

Container Container::return_cont(){return *this;}

void Container::print_var(){
    std::cout<< this->o_len << std::endl;
    std::cout<< this->object << std::endl;
}

void Container::save(std::ofstream& wf){
    int tmp = this->o_len;
    wf.write((char*)&tmp, sizeof(int));
    wf.write((char*)&this->object, this->o_len);
    this->file_map.push_back(this->file_map.back() + this->o_len);
}

void Container::read(std::ifstream& rf, unsigned int num){
    rf.read((char*) &o_len, sizeof(int));
    std::cout << o_len;
    char* tmp;
    rf.read((char*)&tmp , this->o_len);
    std::cout<<tmp;
    //delete [] this->object;
    this->object = nullptr;
    this->object = new char[this->o_len];
    strcpy(this->object, tmp);
    //o_len = 32;
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

int main(void){

    Container       wObj((char*)"TEST TEXT!!!!!!!");
    //wObj.print_var();

    mkdir("data", 0777);
    chdir("data");

    std::ofstream   wf;
    wf.open("data.dat", std::ios::out | std::ios::binary);
    wObj.save(wf);
    int k = 2;
    wf.write((char*) &k, sizeof(int));
    wf.close();
    if(!wf.good()) {
      std::cout << "Error occurred at writing time!" << std::endl;
      return 1;
    }

    std::ifstream   rf;
    rf.open("data.dat", std::ios::out | std::ios::binary);
    if(!rf.good()) {
      std::cout << "Error occurred at reading time!" << std::endl;
      return 1;
    }
    int t;
    Container       rObj;
    rObj.read(rf, 2);
    //rObj.o_len = 321;
    std::cout<< rObj.o_len;
    //rObj.print_var();

    chdir("..");

    std::cout<< "\nFinished\n";
    return 0;
}
