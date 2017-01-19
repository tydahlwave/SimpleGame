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
//#include "EntityManager.h"
#include "World.h"

using namespace std;

string RESOURCE_DIR = "../../resources/"; // Where the resources are loaded from
shared_ptr<Program> phongProg;
shared_ptr<Program> groundProg;
shared_ptr<Shape> bunny;
shared_ptr<Shape> sphere;
shared_ptr<Shape> cube;
shared_ptr<Shape> robot;

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


static void init(RenderSystem &renderer)
{
    GLSL::checkVersion();
    
    // Set background color.
    glClearColor(.12f, .34f, .56f, 1.0f);
    // Enable z-buffer test.
    glEnable(GL_DEPTH_TEST);
    
    renderer.loadShape("bunny");
    
    // Initialize the GLSL program.
    phongProg = make_shared<Program>();
    phongProg->setVerbose(true);
    phongProg->setShaderNames(RESOURCE_DIR + "phong_vert.glsl", RESOURCE_DIR + "phong_frag.glsl");
    phongProg->init();
    phongProg->addUniform("P");
    phongProg->addUniform("M");
    phongProg->addUniform("V");
    phongProg->addAttribute("vertPos");
    phongProg->addAttribute("vertNor");
    phongProg->addUniform("lightPos");
    phongProg->addUniform("lightColor");
    phongProg->addUniform("sunDir");
    phongProg->addUniform("sunColor");
    phongProg->addUniform("matDiffuseColor");
    phongProg->addUniform("matSpecularColor");
    phongProg->addUniform("matAmbientColor");
    phongProg->addUniform("matShine");
    
    // Initialize the GLSL program.
    groundProg = make_shared<Program>();
    groundProg->setVerbose(true);
    groundProg->setShaderNames(RESOURCE_DIR + "ground_vert.glsl", RESOURCE_DIR + "ground_frag.glsl");
    groundProg->init();
    groundProg->addUniform("P");
    groundProg->addUniform("M");
    groundProg->addUniform("V");
    groundProg->addAttribute("vertPos");
    groundProg->addAttribute("vertNor");
    groundProg->addUniform("lightPos");
    groundProg->addUniform("lightColor");
    groundProg->addUniform("sunDir");
    groundProg->addUniform("sunColor");
    groundProg->addUniform("matDiffuseColor");
    groundProg->addUniform("matSpecularColor");
    groundProg->addUniform("matAmbientColor");
    groundProg->addUniform("matShine");
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

int main(int argc, char **argv) {
    Window window;
    RenderSystem renderer;
//    Graphics graphics = new Graphics();
    
    // Initialization
    window.initialize();
//    initGameObjects();
    
    // Initialize scene. Note geometry initialized in init now
    init(renderer);
//    initGeom();
    
    // Game loop
    while (!window.shouldClose()) {
        // Update objects
//        for (GameObject* obj : gameObjects) {
//            obj.update();
//        }
        
        // Render scene.
        renderer.render(window, groundProg);
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
