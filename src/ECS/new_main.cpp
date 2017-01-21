//
//  new_main.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>
#include <memory>
#include <ctime>
#include <iostream>
#include <chrono>

#include "../GLSL.h"
#include "../Window.h"
#include "../Program.h"
#include "../Shape.h"
#include "RenderSystem.h"
#include "ShaderSystem.h"
#include "EntityFactory.h"
#include "World.h"

// value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

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
    EntityFactory::createSheep(world);
}

long long getCurrentTime() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

int main(int argc, char **argv) {
    RenderSystem renderSystem;
    ShaderSystem shaderSystem;
    World world;
    Window window(&world);
    
    // Initialization
    window.initialize();
    init(renderSystem, shaderSystem);
    initGameObjects(world);
    
    long long oldTime = getCurrentTime();
    
    // Game loop
    while (!window.shouldClose()) {
        long long curTime = getCurrentTime();
        cout << "Frame time = " << curTime - oldTime << std::endl;
        int dt = curTime - oldTime;
        
        // Update objects
//        for (GameObject* obj : gameObjects) {
//            obj.update();
//        }
        
        // Render scene.
        renderSystem.render(world, shaderSystem, window);
        // Update camera;
        world.camera.update();
        
        // Swap front and back buffers.
        window.swapBuffers();
        // Poll for and process events.
        window.pollEvents();
        
        // Reset current frame time
        oldTime = curTime;
    }
    
    // Clean up
    window.terminate();
    return 0;
}
