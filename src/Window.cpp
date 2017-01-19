#include "Window.h"

#include <iostream>

using namespace std;

static void error_callback(int error, const char *description) {
    cerr << description << endl;
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

// static void mouse_callback(GLFWwindow *window, int button, int action, int mods) {
//    double posX, posY;
//    if (action == GLFW_PRESS) {
//       glfwGetCursorPos(window, &posX, &posY);
//       cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
// 	}
// }

static void mouse_move_callback(GLFWwindow *window, double posX, double posY) {

}

static void resize_callback(GLFWwindow *window, int width, int height) {

}

int Window::initialize() {
    // Set error callback.
	glfwSetErrorCallback(error_callback);
	// Initialize the library.
	if(!glfwInit()) {
		return -1;
	}
    //request the highest possible version of OGL - important for mac
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	// Create a windowed mode window and its OpenGL context.
	window = glfwCreateWindow(640, 480, "Tyler's Awesome Window", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return -1;
	}
	// Make the window's context current.
	glfwMakeContextCurrent(window);
	// Initialize GLEW.
	glewExperimental = true;
	if(glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW" << endl;
		return -1;
	}
    //weird bootstrap of glGetError
    glGetError();
    cout << "OpenGL version: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

    // Disable cursor (allows unlimited scrolling)
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set vsync.
    glfwSwapInterval(1);
    // Set keyboard callback.
    glfwSetKeyCallback(window, key_callback);
    //set the mouse call back
    // glfwSetMouseButtonCallback(window, mouse_callback);
    // Set the mouse move call back
    glfwSetCursorPosCallback(window, mouse_move_callback);
    //set the window resize call back
    glfwSetFramebufferSizeCallback(window, resize_callback);
}

void Window::terminate() {
    glfwDestroyWindow(window);
	glfwTerminate();
}

int Window::getHeight() {
    int width, height;
	glfwGetFramebufferSize(window, &width, &height);
    return height;
}

int Window::getWidth() {
    int width, height;
	glfwGetFramebufferSize(window, &width, &height);
    return width;
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::swapBuffers() {
    // Swap front and back buffers.
    glfwSwapBuffers(window);
}

void Window::pollEvents() {
    // Poll for and process events.
    glfwPollEvents();
}
