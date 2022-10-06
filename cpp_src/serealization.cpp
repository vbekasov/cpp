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
    private:
        int     o_len;
        int     no;
        char*   object;
    public:
        static std::vector<int>    file_map;
        static int obj_num;
        Container();
        Container(char* y);
        ~Container();
        virtual void print_var(void);
        virtual void add_str(char* txt);
        virtual void save(std::ofstream& wf);
        virtual void read(std::ifstream& rf, unsigned int num);
        virtual int str_len(const char* txt);
        virtual Container return_cont(void);
};

std::vector<int> Container::file_map = {0};
int Container::obj_num = 0;

Container::Container(){
    this->object = nullptr;
    obj_num++;
    this->no = obj_num;
}

Container::Container(char* y)
{
    obj_num++;
    this->no = obj_num;
    this->o_len  = this->str_len(y);
    this->object = new char[this->o_len];
    strcpy(this->object, y);
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
    file_map.push_back(file_map.back() + this->o_len);
}

void Container::read(std::ifstream& rf, unsigned int num){
    rf.read((char*) &this->o_len, sizeof(int));
    if (this->object)
        delete [] this->object;
    this->object = new char[this->o_len];
    char* tmp = new char[16];
    rf.read(tmp, 16);
    strcpy(this->object, tmp);
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

    mkdir("data", 0777);
    chdir("data");

    std::ofstream   wf;
    wf.open("data.dat", std::ios::out | std::ios::binary);
    wObj.save(wf);
    wObj.add_str((char*)"????NextText???");
    wObj.save(wf);

    wf.close();
    if(!wf.good()) {
      std::cout << "Error occurred at writing time!" << std::endl;
      return 1;
    }
    wObj.~Container();

    std::ifstream   rf;
    rf.open("data.dat", std::ios::out | std::ios::binary);
    if(!rf) {
      std::cout << "Error occurred at reading time!" << std::endl;
      return 1;
    }
    Container       rObj;
    rf.seekg(0);
    rObj.read(rf, 2);
    rObj.print_var();

    rObj.read(rf, 3);
    rObj.print_var();

    rf.close();
    rObj.~Container();

    chdir("..");

    std::cout<< "\nFinished\n";
    return 0;
}
