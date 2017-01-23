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
    if (curTime - *elapsedTime >= 3000)
    {
        //            int bunny = spawner.spawnBunny(world);
        GameObject *bunny = EntityFactory::createBunny(&world);
        *elapsedTime = curTime;
    }
}

int main(int argc, char **argv) {
    handleInput(argc, argv);
    
    World world = World();
    Window window = Window(&world);
    Physics physics = Physics();
    Renderer renderer = Renderer();
    
    // Initialization
    Mesh::LoadMeshes(resourceDir);
    Shader::LoadShaders(resourceDir);
    Material::InitializeMaterials();
    
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
        
        physics.Update(world);
        renderer.Render(world, window);
        window.Update();
        
        // Update camera;
//        world.camera.update();
        
        // Reset current frame time
        oldTime = curTime;
    }
    
    return 0;
}
