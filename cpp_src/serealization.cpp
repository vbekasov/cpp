#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int rw_c_stile(void);
int carr_len(const char* txt);

class Container
{
    private:
        char    otype;
        int     len_o;
        char*   object;
    public:
        Container(){};
        Container(char q, char* txt);
        virtual ~Container(){};
        virtual void print_var(void);
        void save(std::ofstream& wfile);
};

Container::Container(char q, char* txt){
    this->otype = q;
    this->len_o = carr_len(txt);
    this->object = txt;
}

void Container::print_var(void)
{
    std::cout<< "Type   :" << this->otype << std::endl;
    std::cout<< "Int    :" << this->len_o << std::endl;
    std::cout<< "Text   :" << this->object << std::endl;
    std::cout << std::endl;
}

void Container::save(std::ofstream& wfile){
    wfile.write(&otype, sizeof(otype));
    auto tmp = this->len_o;
    //wfile.write(&tmp, sizeof(len_o));

}

int main(void){

    //Container   Objw1('S', 21, 87.68, (char *)"TEST TEXT");
    //Container   Objw2('K', 65, 632.632, (char *)"!!!NEXT ROW!!!");
    //Container*   pObj = &Objw1;
    char*       cobj = new char[sizeof(Container)];
    Container*  tmpObj = new (cobj) Container('S', (char *)"TEST TEXT");
    //tmpObj->print_var();

    mkdir("data", 0777);
    chdir("data");

    std::ofstream   wfile;
    tmpObj->save(wfile);
    wfile.open("student.dat", std::ios::binary | std::ios::out);
    int tmp = 123;
    //wfile.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
    //wfile.write(cobj, sizeof(cobj));
    //pObj = nullptr; Objw1.~Container();
    //pObj = &Objw2;
    //pObj = nullptr; Objw2.~Container();
    //wfile.write((char*)pObj, sizeof(Container));
    wfile.close();

    std::ifstream   rfile;
    char*          outObj;
    rfile.open("student.dat", std::ios::binary | std::ios::in);
    int tmp2; char* out;
    //rfile.read(out, sizeof(tmp));
    //rfile.read(outObj, sizeof(Container));
    rfile.close();
    //Container*  rObj = (Container*)outObj;
    //rObj->print_var();
    
    chdir("..");

    return 0;
}

int rw_c_stile(void){
    std::ofstream wf("student.dat", std::ios::out | std::ios::binary);
    if (!wf){
        std::cout<< "Cannot open file to write!\n";
        return 1;
    }
    //wf.write((char *) &Objw1, sizeof(Objw1));
    //wf.write((char *) &Objw2, sizeof(Objw2));
    wf.close();
    //Objw1.~Container();
    //Objw2.~Container();

    std::ifstream rf("student.dat", std::ios::out | std::ios::binary);
    if (!rf) {
        std::cout<< "Cannot open file to read!\n";
        return 1;
    }
    Container   Objr;
    rf.read((char *) &Objr, sizeof(Container));
    Objr.print_var();
    rf.read((char *) &Objr, sizeof(Container));
    Objr.print_var();
    rf.close();
    Objr.~Container();

    return 1;
}

int carr_len(const char* txt){
    int out = 0;
    while (*txt)
    {
        out++;
        txt++;
    }
    return out;
}
