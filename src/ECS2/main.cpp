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
//#include "Renderer.h"

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
    
//    Renderer renderer = Renderer();
    
    
    // Init window
    // Load models
    // set cur time
    
    // Game loop
        // get cur time
        // Get user input
        // Update objects
        // Render objects
        // update cur time
    
    return 0;
}
