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

  struct d2_point{
    float   center[2];
  };

  struct d2_ray: d2_point{
    float   ray[2];
  };

  struct d2_ellipse: d2_ray{
    float              r;
    int                x_rot;
    char               direction;
    char               u_d;        //up & down
    uint64_t           t_time;
    unsigned short int t_loop;
    d2_ellipse(){}
    d2_ellipse(float x1, float y1, float ro, uint64_t tm, int loop){
      center[0] = x1; center[1] = y1;
      ray[0]    = x1 ; ray[1]   = y1 + ro;
      t_time    = tm;
      r         = abs(ro);
      direction = (ro < 0) ? -1 : 1;
      x_rot     = 0;
      u_d       = 1;
      t_loop    = loop / 100;
    }
  };

  class Rot{
    private:
      std::vector<d2_ellipse>   ray_colection;
      uint64_t              loop_stime;
      unsigned short int    min_frame_time;
      void     read_last();
      uint64_t cMilS();
      void     ret_out(d2_ray *out, int v_num);
    public:
      Rot(unsigned int tT){ this->min_frame_time = tT; this->loop_stime = this->tMilS();};
      uint64_t     tMilS();
      virtual void add_ray(float x1, float y1, float ro, int loop);
      virtual void ellipse_step(d2_ray* out, int v_num);
      virtual void cycle_step(d2_ray* out, int v_num);
      virtual void lock_screen();
  };

  void Rot::ellipse_step(d2_ray* out, int v_num){
      if (loop_stime - (uint64_t)this->ray_colection[v_num].t_time < (uint64_t)ray_colection[v_num].t_loop){
          ret_out(out, v_num);         
          return ;}
    
      ray_colection[v_num].t_time = loop_stime;      
      ray_colection[v_num].x_rot += ray_colection[v_num].direction;
      if (abs(ray_colection[v_num].x_rot) == 50){
        ray_colection[v_num].direction *= -1;
        ray_colection[v_num].u_d *= -1;}
      
      ray_colection[v_num].ray[0] = ray_colection[v_num].center[0] + (float)ray_colection[v_num].x_rot * ray_colection[v_num].r / 50.;
      ray_colection[v_num].ray[1] = ray_colection[v_num].center[1] + 
                      sqrt(abs(pow(ray_colection[v_num].r, 2) - pow(ray_colection[v_num].center[0]-ray_colection[v_num].ray[0], 2))); * ray_colection[v_num].u_d;
      ret_out(out, v_num);
  }

  void Rot::cycle_step(d2_ray* out, int v_num){
    if (loop_stime - (uint64_t)this->ray_colection[v_num].t_time < (uint64_t)ray_colection[v_num].t_loop){
          ret_out(out, v_num);
          return ;}

      ray_colection[v_num].t_time = loop_stime;
      ray_colection[v_num].x_rot += ray_colection[v_num].direction;
      if (abs(ray_colection[v_num].x_rot) == 50)
        ray_colection[v_num].direction *= -1;

    ray_colection[v_num].ray[0] = ray_colection[v_num].center[0] + cos(ray_colection[v_num].x_rot * (M_PI / 100.))
                     * ray_colection[v_num].r * ray_colection[v_num].direction;
    ray_colection[v_num].ray[1] = ray_colection[v_num].center[1] + sin(ray_colection[v_num].x_rot * (M_PI / 100.))
                     * ray_colection[v_num].r;
    ret_out(out, v_num);
  }
/*
  void Rot::in_put(){
    std::ofstream MyWrite("rot.txt", std::ios::app);
    std::string out = "|" + std::to_string(ray[0]) + " " + std::to_string(ray[1]) + "\n";
    MyWrite << out;
    MyWrite.close();
  }
*/
  uint64_t Rot::tMilS() {
      this->loop_stime = 
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      return this->loop_stime;
  }

  uint64_t Rot::cMilS(){
    return
      std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  }

  void Rot::add_ray(float x1, float y1, float ro, int loop){
    d2_ellipse  tmp(x1, y1, ro, tMilS() - loop_stime, loop);
    this->ray_colection.push_back(tmp);
  }

  void Rot::ret_out(d2_ray *out, int v_num){
    out->center[0] = ray_colection[v_num].center[0];
    out->center[1] = ray_colection[v_num].center[1];
    out->ray[0]    = ray_colection[v_num].ray[0];
    out->ray[1]    = ray_colection[v_num].ray[1];
  }

  void Rot::lock_screen(){
    usleep(1000 * this->min_frame_time);
  }
////////////////////////////////////////////////////////////////////////////
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
}

#endif
