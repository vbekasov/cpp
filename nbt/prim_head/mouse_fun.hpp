#ifndef MOUSE_FUN_HPP_
#define MOUSE_FUN_HPP_

#include <iostream>
#include "primitives.h"

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
  //std::cout<< xpos << "  " << ypos << std::endl;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
    std::cout << "Mouse But ";
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    std::cout<< xpos << "   " << ypos << std::endl;
  }
}

#endif
                