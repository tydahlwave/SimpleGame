#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
   Window() {}
   virtual ~Window() {}

   int initialize();
   void terminate();

   int getHeight();
   int getWidth();

   bool shouldClose();
   void swapBuffers();
   void pollEvents();
private:
   GLFWwindow *window; // Main application window
};

#endif
