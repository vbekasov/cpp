
#include <GLUT/GLUT.h>

#include <GLFW/glfw3.h>
//#include <time.h>
#include "cl_rot.h"
#include <chrono>
#include "unistd.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    nbt::Rot    Obj;
    nbt::st_xy  xy_coord;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        usleep(pow(10, 5));
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        Obj.one_step(&xy_coord);
        glBegin(GL_LINES);
        glVertex2d(0.,0.);
        glVertex2d(xy_coord.x, xy_coord.y);
        glEnd();
        
        Obj.t_step(&xy_coord);
        glBegin(GL_LINES);
        glVertex2d(0.,0.);
        glVertex2d(xy_coord.x, xy_coord.y);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
