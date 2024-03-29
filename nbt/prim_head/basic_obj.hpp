#ifndef BASIC_OBJ_HPP_
#define BASIC_OBJ_HPP_

#include "primitives.h"
//#include "st_prim.hpp"
//#include "cl_rot.hpp"

namespace nbt{
  struct StMouse{
    double x;
    double y;
  };


  class BasicClickClass{
    public:
      static StMouse st_mouse;
      static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
      void pprr(){std::cout<< "YYYY\n";}
  };

  StMouse BasicClickClass::st_mouse {0. , 0.};

  void BasicClickClass::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
  {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
      std::cout<< "Mouse But ";
      glfwGetCursorPos(window, &st_mouse.x, &st_mouse.y);
      st_mouse.x /= 300; st_mouse.x -= 1;
      st_mouse.y /= -300; st_mouse.y += 1;
      std::cout<< st_mouse.x << "   " << st_mouse.y << std::endl;
    }
  }

/*
  template<> 
  void BasicClass<int>::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
  {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
      std::cout<< "Mouse But ";
      glfwGetCursorPos(window, &st_mouse.x, &st_mouse.y);
      st_mouse.x /= 300; st_mouse.x -= 1;
      st_mouse.y /= -300; st_mouse.y += 1;
      std::cout<< st_mouse.x << "   " << st_mouse.y << std::endl;
      std::cout<< "int\n";
    }
  }
*/
}
#endif
