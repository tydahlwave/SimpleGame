#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ECS/World.h"

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
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void mouse_move_callback(GLFWwindow *window, double posX, double posY);
private:
    GLFWwindow *window; // Main application window
    static World *world;
};

#endif
