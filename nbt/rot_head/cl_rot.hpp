#ifndef CL_ROT_HPP_
#define CL_ROT_HPP_

#define _USE_MATH_DEFINES

#include "math.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <chrono>

namespace nbt{
  class Rot{
    private:
      double  center[3]; //xyz 
      double  ray[3]; //xyz
      double  equ_rot;
      double  lat_rot;
      double  dtime;
      double  r;
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
    ray[1] = std::stod(out);
    std::cout<< ray[1] << std::endl;

    out = "";
    for ( ; ch != '|'; i++){
      MyRead.seekg(-1 * i, std::ios_base::end);
      MyRead.get(ch);
      out += ch;
    }
    out.pop_back();
    std::reverse(out.begin(), out.end());
    ray[0] = std::stod(out);
    std::cout<< ray[0] << std::endl;
    MyRead.close();
  }

  Rot::Rot(){
    read_last();
    this->equ_rot  = M_PI / 10.;
    this->lat_rot  = M_PI / 10.;
    this->r        = 0.5;
    this->center[0]=0.; this->center[1]=0.; this->center[2]=0.;
    this->ray[2]=0;
  }

  void Rot::one_step(){
    ray[0] += this->r * cos(this->equ_rot);
    if (abs(ray[0]) >= this->r)
      this->equ_rot *= -1;
    ray[1] += this->r * sin(this->lat_rot);
    if (abs(ray[1]) >= this->r)
      this->lat_rot *= -1;

    uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    usleep(pow(10,5));

    ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - ms;
    //std::cout << ms << " milliseconds since the Epoch\n";
  }

  void Rot::in_put(){
    std::ofstream MyWrite("rot.txt", std::ios::app);
    std::string out = "|" + std::to_string(ray[0]) + " " + std::to_string(ray[1]) + "\n";
    MyWrite << out;
    MyWrite.close();
  }

}

#endif