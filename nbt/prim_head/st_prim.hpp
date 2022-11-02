#ifndef ST_PRIM_HPP_
#define ST_PRIM_HPP_

#include <math.h>
#include <cstdint>
#include <iostream>

namespace nbt{
  struct d2_point{
    float   center[2];
    d2_point(){};
    d2_point(float x, float y){
      center[0] = x; center[1] = y;};
  };

  struct d2_rect: d2_point{ //rectangle
    float       ray[2];
    static void pr(){std::cout<<  "Struct\n";}
    d2_rect(){};
    d2_rect(float x1, float y1, float x2, float y2){
      center[0] = x1; center[1] = y1;
      ray[0] = x2; ray[1] = y2;};
  };

  struct d2_ellipse: d2_rect{
    float              r;
    int                x_rot;
    char               direction;
    char               u_d;        //up & down
    char               trig_ud;
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
      trig_ud   = (ro < 0) ? -1 : 1;
      t_loop    = loop / 100;
      std::cout<< r << std::endl;
    }
    void rad(){
      float dx = center[0] - ray[0]; 
      dx = pow(dx, 2);
      float dy = center[1] - ray[1];
      dy = pow(dy, 2);
      std:: cout<< sqrt(abs(dx + dy)) << std::endl;
    }
  }; 
};

#endif
