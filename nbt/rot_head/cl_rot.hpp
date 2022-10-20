#ifndef CL_ROT_HPP_
#define CL_ROT_HPP_

#define _USE_MATH_DEFINES

#include "math.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <chrono>
#include "unistd.h"

namespace nbt{

    struct st_xy{
        double x;
        double y;
    };

  class Rot{
    private:
      double    center[3]; //xyz
      double    ray[3]; //xyz
      double    t_ray[3];
      double    direction;
      double    equ_rot;
      double    lat_rot;
      uint64_t  dtime;
      double    r;
      void read_last();
      uint64_t tMilSec();
    public:
      Rot();
      virtual void one_step(st_xy* out);
      virtual void t_step(st_xy* out);
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
    //read_last();
    this->equ_rot  = -0.01;
    this->lat_rot  = 0.01;
    this->r        = 0.5;
    this->direction = -1;
    this->center[0]=0.; this->center[1]=0.; this->center[2]=0.;
    this->ray[0]=0.5; this->ray[1]=0.0; this->ray[2]=0;
    this->t_ray[0]=M_PI; this->t_ray[1]=0; this->t_ray[2]=0;
    this->dtime   = this->tMilSec();
  }

  void Rot::one_step(st_xy* out){
      if (this->dtime - this->tMilSec() < 2){
          return ;}
      
      this->ray[0] += this->equ_rot;
      if (abs(ray[0]) >= this->r)
          this->equ_rot *= -1;
      this->ray[1] = sqrt(abs(r*r - ray[0]*ray[0]));
      out->x = ray[0]; out->y = ray[1];
      
  }

  void Rot::t_step(st_xy* out){
      if (this->dtime - this->tMilSec() < 2){
          return ;}
      
      this->t_ray[0] -= (M_PI / 20) * this->direction;
      out->x = cos(t_ray[0]) * this->r;
      if (abs(out->x) >= this->r)
          this->direction *= -1;
      out->y = sin(this->t_ray[0]) * this->r;
  }

  void Rot::in_put(){
    std::ofstream MyWrite("rot.txt", std::ios::app);
    std::string out = "|" + std::to_string(ray[0]) + " " + std::to_string(ray[1]) + "\n";
    MyWrite << out;
    MyWrite.close();
  }

  uint64_t Rot::tMilSec() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  }

}

#endif
