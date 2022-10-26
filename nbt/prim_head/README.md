# Primitives

Classes and functions to manage graphic in OpenGL framework.
<br>
All time is given in milliseconds.

## Table of Contents

## Project Files
This project contained files:
* [primitives.h](primitives.h) : header file collecting classes and functions
* [draw_fun.h](draw_fun.h) : support functions to draw objects on the desctop
* [cl_rot.hpp](cl_rot.hpp) : 2D rotating objects


# 2D Objects
## 2D Structures
### struct d2_ray
```
    struct d2_ray{
        float              r;          // radius
        int                x_rot;      // one step 
        char               direction;  // Clockwise--Counterclockwise rotation
        char               u_d;        // up & down drawing direction
        uint64_t           t_time;     // time of priviuse drawing
        unsigned short int t_loop;     // time of revolution
        float              center[2];  // xy
        float              ray[2];     // xy
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
<i>d2_ray(float x1, float y1, float ro, uint64_t tm, int loop)</i> : constructor. Center X, Center Y, Radius, Current Time, Time in Milliseconds.

## 2D rotating objects
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
      virtual void elipse_step(d2_ray* out, int v_num);
  };
```
* <i>Rot(unsigned int tT)</i> : constructor. Resives minimum frame time as argument.
* <i>uint64_t tMilS();</i> : set and return current time.
* <i>void add_ray(float x1, float y1, float ro, int loop);</i> : add 2D object. Center X, Center Y, Radius, Revolution Time.
* <i>void elipse_step(d2_ray* out, int v_num);</i> : makes one step of object number passed by <i>v_num</i>, and changes values in pointed <i>d2_ray* out</i> structure. <i>*out</i> is used print or save elipse. Step can not be done faster then FPS.