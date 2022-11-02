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
#include "basic_obj.hpp"
#include "st_prim.hpp"
#include "draw_fun.h"

namespace nbt{

  class Rot{
    private:
      uint64_t                  loop_stime;
      unsigned short int        min_frame_time;
      void     read_last();
      uint64_t cMilS();
      void     ret_out(d2_rect *out, int v_num);
      std::vector<d2_ellipse>   ray_collection ;
    public:
      Rot(unsigned int tT){ this->min_frame_time = tT; this->loop_stime = this->tMilS();};
      virtual ~Rot(){ ray_collection.clear(); ray_collection.shrink_to_fit(); }
      uint64_t     tMilS();
      virtual void add_ray(float x1, float y1, float ro, int loop);
      virtual void ellipse_step(d2_rect* out, int v_num, bool draw = false);
      virtual void cycle_step(d2_rect* out, int v_num, bool draw = false);
      virtual void lock_screen();
      friend  void draw_ray(nbt::d2_rect* xy);
  };

  void Rot::ellipse_step(d2_rect* out, int v_num, bool draw){
    if (loop_stime - (uint64_t)ray_collection[v_num].t_time < (uint64_t)ray_collection[v_num].t_loop){
        ret_out(out, v_num);         
        return ;}
  
    ray_collection[v_num].t_time = loop_stime;      
    ray_collection[v_num].x_rot += ray_collection[v_num].direction;
    if (abs(ray_collection[v_num].x_rot) == 50){
      ray_collection[v_num].direction *= -1;
      ray_collection[v_num].u_d *= -1;}
    
    ray_collection[v_num].ray[0] = ray_collection[v_num].center[0] + 
                    (float)ray_collection[v_num].x_rot * ray_collection[v_num].r / 50.;
    ray_collection[v_num].ray[1] = ray_collection[v_num].center[1] + 
                    sqrt(abs(pow(ray_collection[v_num].r, 2) - pow(ray_collection[v_num].center[0]-ray_collection[v_num].ray[0], 2))) * ray_collection[v_num].u_d;
    ret_out(out, v_num);
    if (draw)
      draw_ray(out);
  }

  void Rot::cycle_step(d2_rect* out, int v_num, bool draw){
    if (loop_stime - (uint64_t)ray_collection[v_num].t_time < (uint64_t)ray_collection[v_num].t_loop){
      ret_out(out, v_num);
      return ;}

    ray_collection[v_num].t_time = loop_stime;
    ray_collection[v_num].x_rot += ray_collection[v_num].direction;
    if (abs(ray_collection[v_num].x_rot) == 50){
      ray_collection[v_num].direction *= -1;}

    ray_collection[v_num].ray[0] = ray_collection[v_num].center[0] +
                    cos(ray_collection[v_num].x_rot * (M_PI / 100.)) * ray_collection[v_num].r * ray_collection[v_num].direction;
    
    ray_collection[v_num].ray[1] = ray_collection[v_num].center[1] - 
                    sin(ray_collection[v_num].x_rot * (M_PI / 100.)) * ray_collection[v_num].r * ray_collection[v_num].trig_ud;                  
    ret_out(out, v_num);
    if (draw)
      draw_ray(out);
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
    this->ray_collection.push_back(tmp);
  }

  void Rot::ret_out(d2_rect *out, int v_num){
    out->center[0] = ray_collection[v_num].center[0];
    out->center[1] = ray_collection[v_num].center[1];
    out->ray[0]    = ray_collection[v_num].ray[0];
    out->ray[1]    = ray_collection[v_num].ray[1];
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
