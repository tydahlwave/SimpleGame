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

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Expect: program [RESOURCE_DIR]" << std::endl;
        return 0;
    }
    resourceDir = argv[1];
    
    // Initialization
    Mesh::LoadMeshes(resourceDir);
    Shader::LoadShaders(resourceDir);
    Material::InitializeMaterials();
    
    World world = World();
    Window window = Window(&world);
    Physics physics = Physics();
    Renderer renderer = Renderer();
    
    srand(time(0));
    
    long oldTime = Time::Now();
    long elapsedTime = oldTime;
    // Game loop
    while (!window.ShouldClose()) {
        long curTime = Time::Now();
        std::cout << "Frame time = " << curTime - oldTime << std::endl;
        int dt = curTime - oldTime;
        
        //spawn bunnies
        if (curTime - elapsedTime >= 3000)
        {
//            int bunny = spawner.spawnBunny(world);
            GameObject *bunny = EntityFactory::createBunny(&world);
            elapsedTime = curTime;
        }
        
        physics.Update(world);
        renderer.Render(world, window);
        window.Update();
        
        // Update camera;
//        world.camera.update();
        
        // Reset current frame time
        oldTime = curTime;
    }
    
    // Clean up
    window.Terminate();
    
    return 0;
}
