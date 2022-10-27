
#ifdef __APPLE__
    #include <GLUT/GLUT.h>
    #include "/Users/v-bek/Documents/bi-tree/g_cpp/nbt/prim_head/primitives.h"
#elif __linux__
    #include <GL/freeglut.h>
    #include "../nbt/prim_head/primitives.h"
#endif

#include <GLFW/glfw3.h>
#include <chrono>
#include "unistd.h"


int main(int argc, char *argv[])
{
    std::cout<< sizeof(nbt::d2_ellipse) << "  "
        << sizeof(nbt::Rot) << std::endl;
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    //glfwSetCursorPosCallback(window, cursor_position_callback);
    //double xpos, ypos;
    //glfwGetCursorPos(window, &xpos, &ypos);
    glfwSetMouseButtonCallback(window, nbt::Rot::mouse_button_callback);

    nbt::d2_rect  xy_coord;
    nbt::Rot     Obj(40);                  // standart frame time
    Obj.add_ray(-0.7, 0.7, -0.25, 1500);    // center: x, y; (r>0=clock)|(r<0=cclock), time to draw full cicle
    Obj.add_ray(-0.2, 0.7, +0.18, 2500);
    Obj.add_ray(-0.3, 0.3,  +0.2, 3000);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //usleep(pow(10, 6));

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        Obj.tMilS();
        
        draw_grid();
        
        Obj.ellipse_step(&xy_coord, 0);
        draw_ray(&xy_coord);
        
        Obj.ellipse_step(&xy_coord, 1);
        draw_ray(&xy_coord);
        
        Obj.cycle_step(&xy_coord, 2);
        draw_ray(&xy_coord);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }
    std::cout<<nbt::Rot::st_mouse.x << " ! " << nbt::Rot::st_mouse.y << std::endl;
    glfwTerminate();
    return 0;
}
