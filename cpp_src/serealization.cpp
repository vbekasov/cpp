#include <iostream>
#include "../nbt/nbt.h"

int main(void){

    nbt::SContainer       wObj((char*)"TEST TEXT!!!!!!!", "data.dat");

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
    wObj.~SContainer();


    nbt::SContainer       rObj;
    rObj.set_wfile("data.dat");

    rObj.read(0);
    rObj.print_var();

    rObj.read(1);
    rObj.print_var();
    
    rObj.read(0);
    rObj.print_var();

    rObj.~SContainer();

    chdir("..");

    std::cout<< "\nFinished\n";
    return 0;
}
