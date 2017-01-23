//
//  Renderer.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#include "Renderer.h"
#include "MeshRenderer.h"

void Renderer::Initialize() {
    // Load all meshes
    // This should look at the resource directory and automatically load all the obj files.
}

void Renderer::Render(World &world) {
    for (GameObject *gameObject : world.GetGameObjects()) {
        MeshRenderer *meshRenderer = (MeshRenderer*)gameObject->GetComponent("MeshRenderer");
        if (meshRenderer) {
            
        }
    }
}
