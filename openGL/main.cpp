
#ifdef __APPLE__
    #include <GLUT/GLUT.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

#include <GLFW/glfw3.h>
#include <chrono>
#include "unistd.h"

//#include "cl_rot.h"
//#include "draw_fun.h"
#include "../nbt/prim_head/primitives.h"

int main(void)
{
    std::cout<< sizeof(nbt::d2_ellipse) << "  "
        << sizeof(nbt::Rot) << std::endl;
    
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
    
    nbt::d2_ellipse  xy_coord;
    nbt::Rot     Obj(40);                  // standart frame time
    Obj.add_ray(-0.67, 0.7, -0.27, 1500);    // center: x, y; radius > 0 clock < 0 cclock, time to draw full cicle
    Obj.add_ray(-0.1,  0.7, +0.18, 2500);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //usleep(pow(10, 6));

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        Obj.tMilS();
        
        Obj.elipse_step(&xy_coord, 1);
        draw_ray(&xy_coord);

        Obj.elipse_step(&xy_coord, 0);
        draw_ray(&xy_coord);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        Obj.lock_screen();
    }

    glfwTerminate();
    return 0;
}
