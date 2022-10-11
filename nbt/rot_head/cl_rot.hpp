#ifndef CL_ROT_HPP_
#define CL_ROT_HPP_

#include "math.h"
#include <iostream>
#include <fstream>
#include <string>

namespace nbt{
    class Rot{
        private:
            double          equator;
            double          equ_rot;
            double          latetude;
            double          lat_rot;
            double          dtime;
            char   r;
            virtual void one_step(void);
        public:
            Rot();
            Rot(double x, double y): equator(x), latetude(y), r(50), dtime(1){}
            virtual void in_put(void);
    };

    Rot::Rot(){
        std::string myText;
        std::ifstream MyReadFile("filename.txt");

        this->equ_rot = 15;
        this->lat_rot = 15;

        std::string tmp1 = "";
        while (getline (MyReadFile, myText)) {
            tmp1 = myText;
        }
        std::string tmp2 = "";
        int i = 0;
        for (; i < tmp1[i] && tmp1[i] != ' '; i++){
            tmp2 += tmp1[i];}
        this->equator = std::stod(tmp2);
        i++;

        tmp2 = "";
        for (; i < tmp1[i] && tmp1[i] != ' '; i++){
            tmp2 += tmp1[i];}
        this->latetude = std::stod(tmp2);

        MyReadFile.close();
    }

    void Rot::one_step(void){
        this->equ_rot = 15;
        this->lat_rot = 15;
        this->latetude  += this->lat_rot;
        this->equator   += this->equ_rot;

        if (this->latetude > abs(this->r))
            this->lat_rot *= -1;

        if (this->equator > abs(this->r))
            this->equ_rot *= -1;
    }

    void Rot::in_put(void){
        std::ofstream MyFile("filename.txt");
        std::string    tmp = std::to_string(this->equator) + " " + std::to_string(this->latetude);

        for (int i=0;i<3;i++)
            one_step();

        MyFile << tmp;
        MyFile.close();
        std::cout<< this->equator << " | " << this->latetude << std::endl;
    }
}

#endif