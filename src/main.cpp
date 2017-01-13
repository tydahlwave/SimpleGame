#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GLSL.h"
#include "Program.h"
#include "MatrixStack.h"
#include "Shape.h"

using namespace std;
using namespace Eigen;

GLFWwindow *window; // Main application window
string RESOURCE_DIR = "../resources/"; // Where the resources are loaded from
shared_ptr<Program> program;
shared_ptr<Shape> shape;

GLuint VertexArrayID;
GLuint groundBuffer;
GLuint groundNormalsBuffer;
static const GLfloat g_ground_buffer_data[] = {
    -1.0, 0.0, -1.0, 
    -1.0, 0.0, 1.0, 
    1.0, 0.0, 1.0, 
    -1.0, 0.0, -1.0, 
    1.0, 0.0, 1.0, 
    1.0, 0.0, -1.0
};
static const GLfloat g_ground_normals_buffer_data[] = {
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0
};

DirectionalLight sun;
PointLight light;
Camera camera;

int g_width, g_height;
float lightPosOffset = 0;
float alpha = 0;
float beta = -M_PI/2;
float t = 0;

// Initialize seeds for the game
// int globalRand = rand();
int treeGenRand = rand();
int treePosRand = rand();

static void error_callback(int error, const char *description) {
   cerr << description << endl;
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
   if (action == GLFW_PRESS) {
      if (key == GLFW_KEY_ESCAPE) {
         // Do Something
      }
   }
}

// static void mouse_callback(GLFWwindow *window, int button, int action, int mods) {
//    double posX, posY;
//    if (action == GLFW_PRESS) {
//       glfwGetCursorPos(window, &posX, &posY);
//       cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
//    }
// }

static void mouse_move_callback(GLFWwindow *window, double posX, double posY) {
   // Get current window size.
   int width, height;
   glfwGetWindowSize(window, &width, &height);

   // Do Something
}

static void resize_callback(GLFWwindow *window, int width, int height) {
   g_width = width;
   g_height = height;
   glViewport(0, 0, width, height);
}

static void init()
{
   GLSL::checkVersion();

   // Set background color.
   glClearColor(.12f, .34f, .56f, 1.0f);
   // Enable z-buffer test.
   glEnable(GL_DEPTH_TEST);

   // Initialize Programs and Meshes
}

static void initGeom() {
   // Initialize the vertex array object
   glGenVertexArrays(1, &VertexArrayID);
   glBindVertexArray(VertexArrayID);

   // Send the ground position array to the GPU
   glGenBuffers(1, &groundBuffer);
   glBindBuffer(GL_ARRAY_BUFFER, groundBuffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(g_ground_buffer_data), g_ground_buffer_data, GL_DYNAMIC_DRAW);
}

static void render() {
   // Get current frame buffer size.
   int width, height;
   glfwGetFramebufferSize(window, &width, &height);
   glViewport(0, 0, width, height);

   // Clear framebuffer.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //Use the matrix stack for Lab 6
   float aspect = width/(float)height;

   // Create the matrix stacks - please leave these alone for now
   auto P = make_shared<MatrixStack>();
   auto M = make_shared<MatrixStack>();

   // Begin matrix transforms
   P->pushMatrix();
   // Apply perspective projection.
   P->perspective(45.0f, aspect, 0.01f, 100.0f);


   // Draw Stuff

   
   P->popMatrix();
   t += 0.01;
   sun.dir[0] = cos(t);
   sun.dir[1] = sin(t);
   sun.dir[2] = cos(t);
}

int main(int argc, char **argv)
{
   if (argc < 2) {
      cout << "Using ../resources/ as the default resources directory." << endl;
      cout << "Please specify an argument if you wish to change the resources directory." << endl;
   } else {
      RESOURCE_DIR = argv[1] + string("/");
   }


   // Initialize things


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

   // Initialize scene. Note geometry initialized in init now
   init();
   initGeom();

   // Loop until the user closes the window.
   while(!glfwWindowShouldClose(window)) {
      // Render scene.
      render();
      // Swap front and back buffers.
      glfwSwapBuffers(window);
      // Poll for and process events.
      glfwPollEvents();
   }
   // Quit program.
   glfwDestroyWindow(window);
   glfwTerminate();
   return 0;
}
