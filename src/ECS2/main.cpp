//
//  main.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#include <iostream>
#include <vector>

#include "Time.h"
#include "Window.h"
#include "World.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Material.h"
#include "Shader.h"
#include "EntityFactory.h"
#include "Physics.h"
#include "Renderer.h"
#include "CameraController.h"

static std::string resourceDir;

void handleInput(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Expect: program [RESOURCE_DIR]" << std::endl;
        exit(0);
    }
    resourceDir = argv[1];
}

void spawnBunnies(World &world, long curTime, long *elapsedTime) {
    if (curTime - *elapsedTime >= 3000) {
        GameObject *bunny = EntityFactory::createBunny(&world);
//        bunny->transform->position = vec3(0, -1, -1);
        *elapsedTime = curTime;
    }
}

int main(int argc, char **argv) {
    handleInput(argc, argv);
    
    World world = World();
    Window window = Window(&world);
    Physics physics = Physics();
    Renderer renderer = Renderer();
    CameraController cameraController = CameraController();
    
    // Static Initializers
    Mesh::LoadMeshes(resourceDir);
    Shader::LoadShaders(resourceDir);
    Material::InitializeMaterials();
    Window::AddWindowCallbackDelegate((WindowCallbackDelegate*)&cameraController);
    
    // Create ground
    GameObject *ground = EntityFactory::createGround(&world);
    ground->transform->position.y -= 2;
    ground->transform->scale = vec3(50, 1, 50);
    
    // Seed random generator
    srand(time(0));
    
    // Init times
    long oldTime = Time::Now();
    long elapsedTime = oldTime;
    
    // Game loop
    while (!window.ShouldClose()) {
        long curTime = Time::Now();
        std::cout << "Frame time = " << curTime - oldTime << std::endl;
        int dt = curTime - oldTime;
        
        spawnBunnies(world, curTime, &elapsedTime);
        
        cameraController.Update(world);
//        physics.Update(world);
        renderer.Render(world, window);
        window.Update();
        
        // Reset current frame time
        oldTime = curTime;
    }
    
    return 0;
}
