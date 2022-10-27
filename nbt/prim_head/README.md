# Primitives

Classes and functions to manage graphic in OpenGL framework.
<br>
All time is given in milliseconds.

## Table of Contents
* [Project Files](#project-files)
* [2D Objects](#2d-objects)
  - [Structures](#2d-structures)
  - [Classes](#2d-classes)

## Project Files
This project contained files:
* [primitives.h](primitives.h) : header file collecting classes and functions
* [draw_fun.h](draw_fun.h) : support functions to draw objects on the desctop
* [cl_rot.hpp](cl_rot.hpp) : 2D rotating objects


# 2D Objects
## 2D Structures
### 2D Point
```
  struct d2_point{
    float   center[2];               // origin point xy
  };
```
### 2D Ray
```
  struct d2_ray: d2_point{           // inheriting from d2_point
    float   ray[2];                  // ray direction point
  };
```
### 2D Ellipse
```
  struct d2_ellipse: d2_ray{         // inheriting from d2_point
      float              r;          // radius
      int                x_rot;      // one step 
      char               direction;  // Clockwise--Counterclockwise rotation
      char               u_d;        // up & down drawing direction
      uint64_t           t_time;     // time of priviuse drawing
      unsigned short int t_loop;     // time of revolution
      d2_ray(){}
      d2_ray(float x1, float y1, float ro, uint64_t tm, int loop){
          center[0] = x1; center[1] = y1;
          ray[0]    = x1 ; ray[1]   = y1 + ro;
          t_time    = tm;
          r         = abs(ro);
          direction = (ro < 0) ? -1 : 1;
          x_rot     = 0;
          u_d       = 1;
          t_loop    = loop / 20;
      }
  };
```
`d2_ray(float x1, float y1, float ro, uint64_t tm, int loop)` : constructor. Center X, Center Y, Radius, Current Time, Time in Milliseconds.

## 2D Static Classes
Text

## 2D Motion Classes
### Class Rot
Object of <b>Rot::</b> stores 2D motioned primitives: elipse ...
```
  class Rot{
    private:
      std::vector<d2_ray>   ray_colection;  // voctor with objects
      uint64_t              loop_stime;     // current time
      unsigned short int    min_frame_time; // frame time
      void read_last();
      uint64_t cMilS();
    public:
      Rot(unsigned int tT){ this->min_frame_time = tT; this->loop_stime = this->tMilS();};
      uint64_t     tMilS();
      virtual void add_ray(float x1, float y1, float ro, int loop);
      virtual void ellipse_step(d2_ray* out, int v_num);
      virtual void cycle_step(d2_ray* out, int v_num);
      virtual void lock_screen();
  };
```
* `Rot(unsigned int tT)` : constructor. Resives minimum frame time as argument.
* `uint64_t tMilS()` : set and return current time.
* `void add_ray(float x1, float y1, float ro, int loop)` : add 2D object. Center X, Center Y, Radius, Revolution Time.
* `void ellipse_step(d2_ray* out, int v_num)` : makes one step of object, number passed by <i>v_num</i>, and changes values in pointed <i>d2_ray* out</i> structure. <i>*out</i> is used to print or save ellipse. Step can not be done faster then FPS.
* `void cycle_step(d2_ray* out, int v_num)` : makes one step of object, number passed by <i>v_num</i>, and changes values in pointed <i>d2_ray* out</i> structure. <i>*out</i> is used to print or save ellipse. Step can not be done faster then FPS.
* `void lock_screen()` : pause loop for time equel with <i>min_frame_time</i>. Used for FPS controle.
