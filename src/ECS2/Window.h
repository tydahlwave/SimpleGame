//
//  Window.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Window_h
#define Window_h

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "World.h"

class Window {
public:
    Window(World *w) { Window::world = w; }
    virtual ~Window() {}
    
    int initialize();
    void terminate();
    
    int getHeight();
    int getWidth();
    
    bool shouldClose();
    void swapBuffers();
    void pollEvents();
    static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void MouseMoveCallback(GLFWwindow *window, double posX, double posY);
private:
    GLFWwindow *window; // Main application window
    static World *world;
};

#endif /* Window_h */
