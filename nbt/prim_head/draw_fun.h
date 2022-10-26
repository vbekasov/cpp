#ifndef DRAW_FUN_H_
#define DRAW_FUN_H_

#ifdef __APPLE__
    #include <GLUT/GLUT.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

#include <GLFW/glfw3.h>
#include "cl_rot.hpp"

void draw_ray(nbt::d2_ellipse* xy){
  glBegin(GL_LINES);
    glVertex2d(xy->center[0], xy->center[1]);
    glVertex2d(xy->ray[0], xy->ray[1]);
  glEnd();
}

#endif
