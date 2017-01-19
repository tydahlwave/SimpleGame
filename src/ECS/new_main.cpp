//
//  new_main.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>
#include <memory>

#include "../GLSL.h"
#include "../Window.h"
#include "../Program.h"
#include "../Shape.h"
#include "RenderSystem.h"
#include "ShaderSystem.h"
//#include "EntityManager.h"
#include "World.h"

using namespace std;

string RESOURCE_DIR = "../../resources/"; // Where the resources are loaded from

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


static void init(RenderSystem &renderer, ShaderSystem &shader)
{
    GLSL::checkVersion();
    
    // Set background color.
    glClearColor(.12f, .34f, .56f, 1.0f);
    // Enable z-buffer test.
    glEnable(GL_DEPTH_TEST);
    
    renderer.loadShape("bunny");
    shader.loadPhong();
    shader.loadGround();
}

static void initGeom() {
    // Initialize the vertex array object
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    // Send the ground position array to the GPU
    glGenBuffers(1, &groundBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, groundBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_ground_buffer_data), g_ground_buffer_data, GL_DYNAMIC_DRAW);
    
    // Send the ground normal array to the GPU
    glGenBuffers(1, &groundNormalsBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, groundNormalsBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_ground_normals_buffer_data), g_ground_normals_buffer_data, GL_DYNAMIC_DRAW);
}

void initGameObjects() {
    
}

int main(int argc, char **argv) {
    Window window;
    RenderSystem renderSystem;
    ShaderSystem shaderSystem;
//    Graphics graphics = new Graphics();
    
    // Initialization
    window.initialize();
    initGameObjects();
    
    // Initialize scene. Note geometry initialized in init now
    init(renderSystem, shaderSystem);
    initGeom();
    
    // Game loop
    while (!window.shouldClose()) {
        // Update objects
//        for (GameObject* obj : gameObjects) {
//            obj.update();
//        }
        
        // Render scene.
        renderSystem.render(shaderSystem, window);
        // Update camera;
//        updateCamera();
        
        // Swap front and back buffers.
        window.swapBuffers();
        // Poll for and process events.
        window.pollEvents();
    }
    
    // Clean up
    window.terminate();
    return 0;
}
