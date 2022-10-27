#ifndef DRAW_FUN_H_
#define DRAW_FUN_H_

#include "primitives.h"

void draw_ray(nbt::d2_rect* xy){
  glColor3f(0,1,0);
  glBegin(GL_LINES);
    glVertex2d(xy->center[0], xy->center[1]);
    glVertex2d(xy->ray[0], xy->ray[1]);
  glEnd();
}

void draw_point(){

}

#endif
