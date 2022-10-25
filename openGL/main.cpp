
#ifdef __APPLE__
    #include <GLUT/GLUT.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

#include <GLFW/glfw3.h>
#include <chrono>
#include "unistd.h"

#include "cl_rot.h"
#include "draw_fun.h"

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
    
    nbt::d2_ray  xy_coord;
    nbt::Rot     Obj(100);
    Obj.add_ray(-0.7, 0.7, 0.28, -0.02);
    Obj.add_ray(-0.1, 0.7, 0.15, +0.05);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //usleep(pow(10, 6));
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        Obj.tMilSec();
        
        Obj.elipse_step(&xy_coord, 1);
        //draw_ray(&xy_coord);

        glBegin(GL_LINES);
        glVertex2d(xy_coord.center[0], xy_coord.center[1]);
        glVertex2d(xy_coord.ray[0],    xy_coord.ray[1]);
        glEnd();
        
        Obj.elipse_step(&xy_coord, 0);
        //draw_ray(&xy_coord);

        glBegin(GL_LINES);
        glVertex2d(xy_coord.center[0], xy_coord.center[1]);
        glVertex2d(xy_coord.ray[0],    xy_coord.ray[1]);
        glEnd();
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
