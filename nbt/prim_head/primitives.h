#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#ifdef __APPLE__
    #include <GLUT/GLUT.h>
    #include "/Users/v-bek/Documents/bi-tree/g_cpp/nbt/prim_head/primitives.h"
#elif __linux__
    #include <GL/freeglut.h>
#endif
#include <GLFW/glfw3.h>

#include "cl_rot.hpp"
#include "draw_fun.h"
#include "screen_grid.h"
#include "mouse_fun.hpp"
#include "basic_obj.hpp"
#include "st_prim.hpp"

#endif
