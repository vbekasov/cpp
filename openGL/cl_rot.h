#ifndef CL_ROT_HPP_
#define CL_ROT_HPP_

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <chrono>
#include "unistd.h"
#include <vector>
#include <algorithm>

namespace nbt{

    struct d2_ray{
        double        center[2];  //xy
        double        ray[2];     //xy
        double        x_rot;
        double        r;
        uint64_t      t_time;
        char          direction;
        d2_ray(){}
        d2_ray(double x1, double y1, double ro, double xr, uint64_t tm){
            center[0] = x1; center[1] = y1;
            ray[0] = x1 + ro; ray[1] = y1;
            t_time = tm;
            //r = sqrt(pow(r, 2) + pow(y1 - y2, 2));
            r = ro;
            //std::cout<< "Radius  " << r << std::endl;
            x_rot = xr;
            direction = (xr < 0) ? 1 : -1;
        }
    };

  class Rot{
    private:
      std::vector<d2_ray>   ray_colection;
      uint64_t              loop_stime;
      unsigned int          min_frame_time;
      void read_last();
    public:
      Rot(unsigned int tT){ this->min_frame_time = tT; this->loop_stime = this->tMilSec();};
      uint64_t tMilSec();
      virtual void add_ray(double x1, double y1, double ro, double xx);
      virtual void elipse_step(d2_ray* out, int v_num);
      virtual void t_step(d2_ray* out, int v_num, uint64_t mil){};
      //virtual void in_put(void);
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
    //ray[1] = std::stod(out);
    //std::cout<< ray[1] << std::endl;

    out = "";
    for ( ; ch != '|'; i++){
      MyRead.seekg(-1 * i, std::ios_base::end);
      MyRead.get(ch);
      out += ch;
    }
    out.pop_back();
    std::reverse(out.begin(), out.end());
    //ray[0] = std::stod(out);
    //std::cout<< ray[0] << std::endl;
    MyRead.close();
  }

  void Rot::elipse_step(d2_ray* out, int v_num){
      if (this->loop_stime - this->ray_colection[v_num].t_time < this->min_frame_time){
          out->center[0] = this->ray_colection[v_num].center[0];
          out->center[1] = this->ray_colection[v_num].center[1];
          out->ray[0]    = this->ray_colection[v_num].ray[0];
          out->ray[1]    = this->ray_colection[v_num].ray[1];
          return ;}
      this->ray_colection[v_num].t_time = this->loop_stime;
      
      this->ray_colection[v_num].ray[0] += this->ray_colection[v_num].x_rot * this->ray_colection[v_num].direction;
      if (abs(this->ray_colection[v_num].ray[0]-this->ray_colection[v_num].center[0]) >= this->ray_colection[v_num].r)
          this->ray_colection[v_num].x_rot *= -1;
      
      double tmp_x = abs(this->ray_colection[v_num].center[0] - this->ray_colection[v_num].ray[0]);      
      char up_down = (this->ray_colection[v_num].x_rot < 0) ? 1 : -1;      
      this->ray_colection[v_num].ray[1] =
        this->ray_colection[v_num].center[1] + sqrt(abs(pow(this->ray_colection[v_num].r, 2) - pow(tmp_x, 2))) * up_down;
      
      std::cout<< this->ray_colection[v_num].x_rot << std::endl;      
      
      out->center[0] = this->ray_colection[v_num].center[0];
      out->center[1] = this->ray_colection[v_num].center[1];
      out->ray[0]    = this->ray_colection[v_num].ray[0];
      out->ray[1]    = this->ray_colection[v_num].ray[1];
      //std::cout<< sqrt(abs(pow(out->center[0]-out->ray[0],2) - pow(out->center[1]-out->ray[1],2))) << std::endl;
  }
/*
  void Rot::t_step(st_xy* out, uint64_t mil){
      if (this->tMilSec() - this->t_time < mil){
          out->x = cos(t_ray[0]) * this->r;
          out->y = sin(this->t_ray[0]) * this->r;
          std::cout<< tMilSec() - t_time << std::endl;
          return ;}

      this->t_time = this->tMilSec();
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
*/
  uint64_t Rot::tMilSec() {
      this->loop_stime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      return this->loop_stime;
  }

    void Rot::add_ray(double x1, double y1, double ro, double xx){
        d2_ray  tmp(x1, y1, ro, xx, this->loop_stime);
        this->ray_colection.push_back(tmp);
    }
}

#endif
