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
#include <vector>

#include "World.h"

typedef void (*MouseCallback)(double, double);

class Window {
public:
    Window(World *w);
    virtual ~Window() {};
    
    int Initialize();
    void Terminate();
    
    int GetHeight();
    int GetWidth();
    
    bool ShouldClose();
    void SwapBuffers();
    void PollEvents();
    static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void MouseMoveCallback(GLFWwindow *window, double posX, double posY);
private:
    GLFWwindow *window; // Main application window
    static World *world;
    std::vector<MouseCallback> mouseMoveCallbacks;
};

#endif /* Window_h */
