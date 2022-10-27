#ifndef ST_PRIM_HPP_
#define ST_PRIM_HPP_

#include <math.h>
#include <cstdint>
#include <iostream>

namespace nbt{
  struct d2_point{
    float   center[2];
  };

  struct d2_rect: d2_point{ //rectangle
    float       ray[2];
    static void pr(){std::cout<<  "Struct\n";}
  };

  struct d2_ellipse: d2_rect{
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
};

#endif
