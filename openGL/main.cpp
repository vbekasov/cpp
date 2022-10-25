
#include <GLUT/GLUT.h>

#include <GLFW/glfw3.h>
//#include <time.h>
#include "cl_rot.h"
#include <chrono>
#include "unistd.h"

int main(void)
{
    std::cout<< "START\n";
    char    rub;
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(480, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    nbt::Rot     Obj;
    Obj.add_ray(0.3, 0.2, 0.5, 0.7, -0.04);
    nbt::d2_ray  xy_coord;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        usleep(pow(10, 6));
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        

        Obj.tMilSec();
        
        Obj.elipse_step(&xy_coord, 0);
        glBegin(GL_LINES);
        glVertex2d(xy_coord.center[0], xy_coord.center[1]);
        glVertex2d(xy_coord.ray[0], xy_coord.ray[1]);
        glEnd();
        /*
        Obj.t_step(&xy_coord, pow(10, 2.5));
        glBegin(GL_LINES);
        glVertex2d(0.,0.);
        glVertex2d(xy_coord.x, xy_coord.y);
        glEnd();
         */
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
