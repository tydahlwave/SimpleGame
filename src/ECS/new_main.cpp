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
#include "EntityFactory.h"
#include "World.h"

using namespace std;

string RESOURCE_DIR = "../../resources/"; // Where the resources are loaded from

static void init(RenderSystem &renderer, ShaderSystem &shader)
{
    GLSL::checkVersion();
    
    // Set background color.
    glClearColor(.12f, .34f, .56f, 1.0f);
    // Enable z-buffer test.
    glEnable(GL_DEPTH_TEST);
    
    renderer.loadShape("bunny");
    renderer.loadShape("rect");
    shader.loadPhong();
    shader.loadGround();
}

void initGameObjects(World &world) {
    EntityFactory::createGround(world);
}

int main(int argc, char **argv) {
    RenderSystem renderSystem;
    ShaderSystem shaderSystem;
    World world;
    Window window(&world);
//    Graphics graphics = new Graphics();
    
    // Initialization
    window.initialize();
    initGameObjects(world);
    
    // Initialize scene. Note geometry initialized in init now
    init(renderSystem, shaderSystem);
    
    // Game loop
    while (!window.shouldClose()) {
        // Update objects
//        for (GameObject* obj : gameObjects) {
//            obj.update();
//        }
        
        // Render scene.
        renderSystem.render(world, shaderSystem, window);
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
