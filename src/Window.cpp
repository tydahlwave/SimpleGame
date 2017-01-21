#include "Window.h"

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iostream>

#include "ECS/World.h"

using namespace std;

#define CAMERA_SPEED 0.2
#define CAMERA_STOPPED_THRESHOLD 0.1
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

World* Window::world;

float alpha1 = 0;
float beta1 = -M_PI/2;

static void error_callback(int error, const char *description) {
    cerr << description << endl;
}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        } else if (key == GLFW_KEY_W) {
            world->camera.vel[2] = -CAMERA_SPEED;
        } else if (key == GLFW_KEY_S) {
            world->camera.vel[2] = CAMERA_SPEED;
        } else if (key == GLFW_KEY_A) {
            world->camera.vel[0] = -CAMERA_SPEED;
        } else if (key == GLFW_KEY_D) {
            world->camera.vel[0] = CAMERA_SPEED;
        }
    } else if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W) {
            if (world->camera.vel[2] < -CAMERA_STOPPED_THRESHOLD) {
                world->camera.vel[2] = 0;
            } else {
                world->camera.vel[2] = CAMERA_SPEED;
            }
        } else if (key == GLFW_KEY_S) {
            if (world->camera.vel[2] > CAMERA_STOPPED_THRESHOLD) {
                world->camera.vel[2] = 0;
            } else {
                world->camera.vel[2] = -CAMERA_SPEED;
            }
        } else if (key == GLFW_KEY_A) {
            if (world->camera.vel[0] < -CAMERA_STOPPED_THRESHOLD) {
                world->camera.vel[0] = 0;
            } else {
                world->camera.vel[0] = CAMERA_SPEED;
            }
        } else if (key == GLFW_KEY_D) {
            if (world->camera.vel[0] > CAMERA_STOPPED_THRESHOLD) {
                world->camera.vel[0] = 0;
            } else {
                world->camera.vel[0] = -CAMERA_SPEED;
            }
        }
    }
}

// static void mouse_callback(GLFWwindow *window, int button, int action, int mods) {
//    double posX, posY;
//    if (action == GLFW_PRESS) {
//       glfwGetCursorPos(window, &posX, &posY);
//       cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
// 	}
// }

void Window::mouse_move_callback(GLFWwindow *window, double posX, double posY) {
    // Get current window size.
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // Compute new alpha and beta for the camera lookat point
    double alpha2 = alpha1 + ((posY + height/2.0) / height * M_PI*16/18) - M_PI*8/18;
    double beta2 = beta1 + ((posX + width/2.0) / width * M_PI*2) - M_PI;

    // Constrain the view (up and down constrained to (-80,80) degrees)
    if (alpha2 > M_PI*8/18) alpha2 = M_PI*8/18;
    if (alpha2 < -M_PI*8/18) alpha2 = -M_PI*8/18;

    // Compute camera lookat point
    world->camera.lookAt[0] = world->camera.pos[0] + cos(alpha2) * cos(beta2);
    world->camera.lookAt[1] = world->camera.pos[1] + -sin(alpha2);
    world->camera.lookAt[2] = world->camera.pos[2] + cos(alpha2) * cos(M_PI/2 - beta2);
    cout << world->camera.lookAt.x << ", " << world->camera.lookAt.y << ", " << world->camera.lookAt.z << endl;
}

static void resize_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
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
    glfwSetKeyCallback(window, Window::key_callback);
    //set the mouse call back
    // glfwSetMouseButtonCallback(window, mouse_callback);
    // Set the mouse move call back
    glfwSetCursorPosCallback(window, Window::mouse_move_callback);
    //set the window resize call back
    glfwSetFramebufferSizeCallback(window, resize_callback);
    
    return 0;
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
