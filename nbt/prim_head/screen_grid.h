#ifndef SCREEN_GRID_H_
#define SCREEN_GRID_H_

#ifdef __APPLE__
    #include <GLUT/GLUT.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

#include <GLFW/glfw3.h>

void draw_grid(){
  glColor3f(1,0,0);
  glBegin(GL_LINES);
    glVertex2d(-1. , 0.);
    glVertex2d(1.  , 0.);
  glEnd();

  glBegin(GL_LINES);
    glVertex2d(0. , -1.);
    glVertex2d(0. ,  1.);
  glEnd();
}


#endif
