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
            double          r;
            void read_last();
        public:
            Rot();
            virtual void one_step(void);
            virtual void in_put(void);
    };

    void Rot::read_last(){
        std::ifstream MyRead("rot.txt");
        std::string out = "";
        char ch = '\0';
        int  i = 3;

        for ( ; ch != ' '; i++){
            MyRead.seekg(-1 * i, std::ios_base::end);
            MyRead.get(ch);
            out += ch;
        }
        std::reverse(out.begin(), out.end());
        this->latetude = std::stod(out);
        std::cout<< this->latetude << std::endl;

        out = "";
        for ( ; ch != '|'; i++){
            MyRead.seekg(-1 * i, std::ios_base::end);
            MyRead.get(ch);
            out += ch;
        }
        out.pop_back();
        std::reverse(out.begin(), out.end());
        this->equator = std::stod(out);

        std::cout<< this->equator << std::endl;
        MyRead.close();
    }

    Rot::Rot(){
        read_last();

        //this->equator  = 12.3;
        //this->latetude = 14.8;
        this->equ_rot  = 0.5;
        this->lat_rot  = 0.7;
        this->r        = 70.;
    }

    void Rot::one_step(){
        this->equator  += this->equ_rot;
        this->latetude += this->lat_rot;
    }

    void Rot::in_put(){
        std::ofstream MyWrite("rot.txt", std::ios::app);
        std::string out = "|" + std::to_string(this->equator) + " " + std::to_string(this->latetude) + "\n";
        MyWrite << out;
        MyWrite.close();
    }
    
}

#endif